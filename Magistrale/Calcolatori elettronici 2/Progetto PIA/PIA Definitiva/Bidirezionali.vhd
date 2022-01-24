library IEEE;
use IEEE.std_logic_1164.all;

entity Bidirezionali is
	generic (N: integer);
	port(Bidi:			inout std_logic_vector(N-1 downto 0);
		Input:			in std_logic_vector(N-1 downto 0);
		Enable: 		in std_logic;
		Interr:			in std_logic
		);
end Bidirezionali;

architecture Behavioural of Bidirezionali is
	
	signal temp1: std_logic_vector(N-1 downto 0) := (others => 'Z');

begin
	
	process (ENABLE)
	begin
		if(ENABLE'event and ENABLE='0') then 
				temp1 <= Input;
		end if;
	end process;

	process(Interr, bidi, temp1)
	begin
		if(Interr = '1') then		
			Bidi <= temp1;
		else
			Bidi <= (others => 'Z');
		end if;
		
	end process;

end Behavioural;