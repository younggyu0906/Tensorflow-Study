library ieee;
use ieee.std_logic_1164.all;

entity and_4 is
	port( a, b, c, d 	: in std_logic;
					o 	: out std_logic );
end and_4;

architecture sample of and_4 is
begin
	o <= a and b and c and d;
end sample;