library ieee;
use ieee.std_logic_1164.all;

entity or_4 is
	port( a, b, c, d 	: in std_logic;
					o 	: out std_logic );
end or_4;

architecture sample of or_4 is
begin
	o <= a or b or c or d;
end sample;