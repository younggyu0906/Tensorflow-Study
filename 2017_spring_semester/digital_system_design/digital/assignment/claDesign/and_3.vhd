library ieee;
use ieee.std_logic_1164.all;

entity and_3 is
	port( a, b, c 	: in std_logic;
					o 	: out std_logic );
end and_3;

architecture sample of and_3 is
begin
	o <= a and b and c;
end sample;