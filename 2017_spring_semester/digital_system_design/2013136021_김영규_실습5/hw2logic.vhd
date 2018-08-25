library ieee;
use ieee.std_logic_1164.all;

entity hw2logic is
	port( a, b, c, d 	: in bit;
           y_out 	: out bit );
end hw2logic;

architecture sample of hw2logic is
begin
	process (a, b, c, d)
	begin
	if d = '0' then
		y_out <= '0';
	elsif c = '1' then
		y_out <= '0';
	elsif a = '1' then
		if b = '1' then
			y_out <= '0';
		else
			y_out <= '1';
		end if;
	else
		y_out <= '1';
	end if;
	end process;
end sample;