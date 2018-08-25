library ieee; 
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity comp is
	port( a, b 	: in std_logic_vector(1 downto 0);
		equal 	: out std_logic ); 
end comp;

architecture sample  of comp is
	begin
	process(a, b)
		begin
			if a = b then
				equal <= '1';
			else
				equal <= '0';
		end if;
	end process;
end sample ;