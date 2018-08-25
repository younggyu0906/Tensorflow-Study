library ieee;
use ieee.std_logic_1164.all;

entity ex02 is
port(d,en : in std_logic;
	q : out std_logic );
end ex02;

architecture sample of ex02 is
begin
process(en, d)
	begin
	if en='1' then
	q <= d;
	end if;
	end process;
end sample;