library ieee;
use ieee.std_logic_1164.all;

entity HA is
	port( x, y  	: in std_logic;
	     c, s	: out std_logic );
end HA;

architecture sample of HA is
begin
	p1 : process(x, y)
	begin
		if (x='1') and (y='1') then
			c <= '1';
		else
			c <= '0';
		end if;
	end process;

	p2 : process(x, y)
	begin
		if (x=y) then
			s <= '0';
		else 
			s <= '1';
		end if;
	end process;
end sample;