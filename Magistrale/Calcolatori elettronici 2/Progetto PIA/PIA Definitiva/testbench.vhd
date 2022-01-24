library ieee;
use ieee.std_logic_1164.all;

entity testbench is

end testbench;

architecture behavioural of testbench is

	component PIA is				
		port(
		ENABLE: 	in std_logic;							
		CS:			in std_logic_vector(2 downto 0);	
		RW:			in std_logic;							
		RESET:		in std_logic;							
		PA:			inout std_logic_vector(7 downto 0);		
		PB:			inout std_logic_vector(7 downto 0);		
		CA1:		in std_logic;							
		CA2:		inout std_logic;					
		CB1:		in std_logic;							
		CB2:		inout std_logic;						
		D:			inout std_logic_vector(7 downto 0);		
		RS:			in std_logic_vector(0 to 1);			
		IRQA:		out std_logic;							
		IRQB:		out std_logic							
		);
	end component;
	
	signal enable, reset, rw, ca1, ca2, cb1, cb2, irqa, irqb: std_logic  := 'Z';
	signal cs: std_logic_vector(2 downto 0) := (others => 'Z');
	signal rs: std_logic_vector(0 to 1) := (others => 'Z');
	signal pa, pb, d: std_logic_vector(7 downto 0) := (others => 'Z');
	constant period: time := 10 ns;
	
begin

	pia_test: PIA port map (enable, cs, rw, reset, pa, pb, ca1, ca2, cb1, cb2, d, rs, irqa, irqb);
	
	clock: process
		variable count: integer;
	begin
		for count in 0 to 55 loop
			enable <= '0';
			wait for period/2;
			enable <= '1';
			wait for period/2;
		end loop;
		wait;
	end process;

	test: process
	begin
		wait for 17 ns;
		cs <= "011";										--E'stata selezionata la PIA;
		reset <= '0';
		wait for 30 ns;
		reset <= '1';
		wait for 11 ns;
		
		--Scrittura in CRA
		d <= "10100001";
		rs <= "10";
		wait for 3 ns;
		rw <= '0';
		wait for 10 ns;
		rs <= "ZZ";
		d <= (others => 'Z');
		rw <= 'Z';
		wait for 40 ns;

		
		--Scrittura DDRA
		wait for 7 ns;
		d <= "00000000";
		rs <= "00";
		wait for 6 ns;
		rw <= '0';
		wait for 11 ns;
		rs <= "ZZ";
		d <= (others => 'Z');
		rw <= 'Z';
		
		--Seconda scrittura in CRA per dire che dopo l vuole accedere al PDRA
		wait for 30 ns;
		d <= "00100101";
		wait for 6 ns;
		rs <= "10";
		wait for 3 ns;
		rw <= '0';
		wait for 10 ns;
		rs <= "ZZ";
		d <= (others => 'Z');
		rw <= 'Z';
		wait for 40 ns;
		
		--Dispositivo sul porto A interrompe e scrive su PDRA
		pa <= "10101111";
		wait for 7 ns;
		ca1 <= '0';
		wait for 12 ns;
		ca1 <= '1';

		--CPU legge il PDRA
		wait for 19 ns;
		rs <= "00";
		rw <= '1';
		wait for 29 ns;
		rw <= 'Z';
		rs <= "ZZ";
		
		--CPU scrive su CRB
		wait for 25 ns;
		d <= "00100001";
		rs <= "11";
		wait for 3 ns;
		rw <= '0';
		wait for 10 ns;
		rs <= "ZZ";
		d <= (others => 'Z');
		rw <= 'Z';
		wait for 40 ns;
		
		--Scrittura DDRB
		wait for 7 ns;
		d <= "11111111";
		rs <= "01";
		wait for 6 ns;
		rw <= '0';
		wait for 11 ns;
		rs <= "ZZ";
		d <= (others => 'Z');
		rw <= 'Z';
		
		--Seconda scrittura in CRB per acedere al PDRB
		wait for 25 ns;
		cb1 <= '0';					--Intanto B interrompe
		d <= "00100101";
		rs <= "11";
		wait for 3 ns;
		rw <= '0';
		wait for 10 ns;
		cb1 <= '1';				
		rw <= 'Z';
		wait for 40 ns;
		
		--Scrittura in PDRB
		wait for 7 ns;
		d <= "11111111";
		rs <= "01";
		wait for 6 ns;
		rw <= '0';			--Da questo momento, sul fronte di discesa di enable, mi aspetto che CB2 si abbassi.
		wait for 11 ns;
		rs <= "ZZ";
		d <= (others => 'Z');
		rw <= 'Z';
		

		
		
		wait;
	end process;




end behavioural;