library ieee;
use ieee.std_logic_1164.all;

entity hw3decoder24 is
	port ( a	: in std_logic_vector(1 downto 0);
            y 	: out std_logic_vector(3 downto 0) );
end hw3decoder24;

architecture sample of hw3decoder24 is
begin
	process(a)	
   begin
		case a is
			when "00" => y <= "0001";
			when "01" => y <= "0010";
			when "10" => y <= "0100";
			when others => y <= "1000";
		end case;
   end process;
end sample;
