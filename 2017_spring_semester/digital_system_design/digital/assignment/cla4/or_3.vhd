library ieee;
use ieee.std_logic_1164.all;

entity or_3 is
	port( a, b, c 	: in std_logic;
					o 	: out std_logic );
end or_3;

architecture sample of or_3 is
begin
	o <= a or b or c;
end sample;