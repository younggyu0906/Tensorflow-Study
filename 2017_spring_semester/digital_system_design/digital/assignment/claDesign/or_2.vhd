library ieee;
use ieee.std_logic_1164.all;

entity or_2 is
	port( a, b 	: in std_logic;
					o 	: out std_logic );
end or_2;

architecture sample of or_2 is
begin
	o <= a or b;
end sample;