library ieee;
use ieee.std_logic_1164.all;

entity logic is
	port( a, b, c, d 	: in bit;
           y_out 	: out bit );
end logic;

architecture sample of logic is
begin 
	y_out <= '0' when (d='0') else			-- ①번 기술
               '0' when (c='1') else			-- ②번 기술
               '0' when (a='1') and (b='1') else 	-- ③번 기술
               '1';
end sample;