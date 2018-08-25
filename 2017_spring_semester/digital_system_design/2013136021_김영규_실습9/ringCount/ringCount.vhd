library ieee;
use ieee.std_logic_1164.all;

entity ringCount is
	port( clk, reset 	: in std_logic;
	         count 	: buffer std_logic_vector(7 downto 0));
end ringCount;

architecture sample of ringCount is
begin
	process(clk, reset)
	begin
		if reset = '1'  then
	      	count <= "00000001";
	   elsif (clk'event and clk= '1') then
				count <= count(6 downto 0) & count(7);
	   end if;	
	end process;
end sample;