library ieee;
use ieee.std_logic_1164.all;

entity PIA is
	port(
	--Segnali di controllo per la PIA
	ENABLE: 	in std_logic;							--Come segnale di abilitazione useremo il clock
	CS:			in std_logic_vector(2 downto 0);		--Segnali di chip select (con 011 seleziono la PIA)							--Segnale che uso per leggere e scrivere(leggo se RW=1, scrivo se RW=0)
	RESET:		in std_logic;							--Reset che funziona in logica negata
	
	--Segnali di comunicazione tra PIA e device
	PA:			inout std_logic_vector(7 downto 0);		--Bus per scambiare i dati con il porto A: la direzione viene scelta in base al registro DDRA
	PB:			inout std_logic_vector(7 downto 0);		--Bus per scambiare i dati con il porto B: la direzione viene scelta in base al registro DDRB
	CA1:		in std_logic;							--Linea che usa il device A per mandare una richiesta di interruzione
	CA2:		inout std_logic;						--Linea che usa il device A per instaurare un protocollo con la PIA o per interrompere
	CB1:		in std_logic;							--Linea che usa il device B per mandare una richiesta di interruzione
	CB2:		inout std_logic;						--Linea che usa il device B per instaurare un protocollo con la PIA o per interrompere
	
	--Segnali di comunicazione tra PIA e CPU
	D:			inout std_logic_vector(7 downto 0);		--Bus per scambiare i dati con la CPU
	RW:			in std_logic;
	RS:			in std_logic_vector(0 to 1);			--Segnali per selezionare uno dei registri interni della PIA
	IRQA:		out std_logic;							--Linea che usa la PIA per dire alla CPU che il dispositivo A ha interrotto
	IRQB:		out std_logic							--Linea che usa la PIA per dire alla CPU che il dispositivo B ha interrotto
	);
end PIA;

architecture behavioural of PIA is
	
--REGISTRI INTERNI DELLA PIA
	--Segnali per i Control Register
	signal CRA: std_logic_vector(7 downto 0) := (others => '0');
	signal CRB: std_logic_vector(7 downto 0) := (others => '0');	
	
	--Segnali per i Data Direction Register
	signal DDRA: std_logic_vector(7 downto 0) := (others => '0');		--Settate a 0 permette di selezionare i segnali PA e PB come ingressi, a 1 invece sono usacite
	signal DDRB: std_logic_vector(7 downto 0) := (others => '0');
	
	--Segnali per i Periferal Control Register
	signal PDRA: std_logic_vector(7 downto 0) := (others => '0');
	signal PDRB: std_logic_vector(7 downto 0) := (others => '0');
	 
--SEGNALI PER GESTIRE I BUS BIDIREZIONALI	
	--Segnali che servono a gestire la direzione del bus D
	signal d_in: std_logic_vector(7 downto 0) := (others => 'Z');		
	signal interr: std_logic := 'Z';							--Interruttore per implementare un buffer tristate per il bud D
	
	--Segnali che servono a gestire la direzione del bus PA
	signal pa_in: std_logic_vector(7 downto 0) := (others => 'Z');		
	signal pa_interr: std_logic := 'Z';
	
	--Segnali che servono a gestire la direzione del bus PB
	signal pb_in: std_logic_vector(7 downto 0) := (others => 'Z');		
	signal pb_interr: std_logic := 'Z';
	

--COMPONENT PER I BUS BIDIREZIONALI	
	component Bidirezionali is
		generic (N: integer);
		port(Bidi:			inout std_logic_vector(N-1 downto 0);
			Input:			in std_logic_vector(N-1 downto 0);
			Enable: 		in std_logic;
			Interr:			in std_logic
			);
		end component;
	
begin

--Gestione bus bidirezionali come buffer tristate	 
	Gestione_bus_D: Bidirezionali generic map (8) port map(D, d_in, ENABLE, interr);
	Gestione_bus_PA: Bidirezionali generic map(8) port map(PA, pa_in, ENABLE, pa_interr);
	Gestione_bus_PB: Bidirezionali generic map(8) port map(PB, pb_in, ENABLE, pb_interr);
	
	Interr <= RW;																			--Se RW=1, l'interruttore del buffer tristate si chiude, e quindi il dato che viene letto viene inserito sul bus D.
	pa_interr <= DDRA(0) and DDRA(1) and DDRA(2) and DDRA(3) and DDRA(4) and DDRA(5) and DDRA(6) and DDRA(7);		--Questa and bit a bit indica che l'interruttore per il bus PA si deve chiudere (la lettura dal PDRA avviene) solo se titti i bit del PDRA sono 1, ovvero se le PA sono di output
	pb_interr <= DDRB(0) and DDRB(1) and DDRB(2) and DDRB(3) and DDRB(4) and DDRB(5) and DDRB(6) and DDRB(7);


	
	IRQA <= CRA(7);
	IRQB <= CRB(7);
	
--I bit 6 dei CR sono messi a 0 perchè abbiamo scelto di analizzare la modalità di handshaking, quindi CA2 solo di output
	CRA(6) <= '0';
	CRB(6) <= '0';
	
	
	funzionamento:process(ENABLE)						
	begin
		if(ENABLE'event and ENABLE='0') then
		
			  if (RESET='0') then
				 CRA <= (others => '0');
				 CRB <= (others => '0');
				 DDRA <= (others => '0');
				 DDRB <= (others => '0');
				 PDRA <= (others => '0');
				 PDRB <= (others => '0');
			
			else
			
				if(DDRA = "11111111") then
					pa_in <= PDRA;									--PA legge dal PDRA sempre se DDRA assume valori pari a 1, non ci sono altre condizioni.
				end if;
				
				
				if(DDRB <=	"11111111")	then	
					pb_in <= PDRB;
				end if;	
				
				
				if (CA1='0') then
					if(DDRA <=	"00000000")	then					--PA scrive nel DDRA solo se il DDRA è settato opportunamente
						PDRA <= PA;
					end if;
					if(CRA(1 downto 0) = "01") then					--Scateno l'interruzione sul fronte di discesa di CA1
						CRA(7) <= '1';
						if(CRA(5 downto 3) <= "100") then				--Modalità handshaking
							CA2 <= '1';	
						end if;
					end if;					
				end if;
			
			
				
				if (CB1='0') then
					if(DDRB <=	"00000000")	then	
						PDRB <= PB;
					end if;
					if(CRB(1 downto 0) = "01") then				
						CRB(7) <= '1';
						if(CRB(5 downto 3) <= "100") then			
							CB2 <= '1';	
						end if;
					end if;					
				end if;
			
					
				case RS is 
				
					when "10" =>
						if(RW='0') then
							CRA(5 downto 0) <= D(5 downto 0);
						elsif(RW='1') then
							d_in(5 downto 0) <= CRA(5 downto 0);		--Il dato del registro viene messo in d_in, e verrà poi messo sul bus D dal component Gestione_bud_D
						end if;
						
				
					when "11" =>
						if(RW='0') then
							CRB(5 downto 0) <= D(5 downto 0);
						elsif(RW='1') then
							d_in(5 downto 0) <= CRB(5 downto 0);
						end if;

			
					
					when "00" =>
						if(CRA(2)='0')then
							if(RW='0') then
								DDRA <= D;
							elsif(RW='1') then
								d_in <= DDRA;
							end if;
						elsif(CRA(2)='1') then		
							if(RW='1') then
								CRA(7) <= '0';
								d_in <= PDRA;
								if(CA2='1') then
									CA2 <= '0';
								end if;
							elsif(RW='0') then
								PDRA <= D;
							end if;
						end if;
					
					
					when "01" =>
						if(CRB(2)='0') then
							if(RW='0') then
								DDRB <= D;
							elsif(RW='1') then
								d_in <= DDRB;
							end if;
						elsif(CRB(2)='1') then
							if(RW='0') then
								PDRB <= D;
								if(CB2 = '1') then
									CB2 <= '0';
								end if;
							elsif(RW='1') then
								CRB(7) <= '0';
								d_in <= PDRB;
							end if;
						end if;
						
					when others => 
						 null;
						
					end case;
			end if;
		end if;				
	end process;
	
	
end behavioural;