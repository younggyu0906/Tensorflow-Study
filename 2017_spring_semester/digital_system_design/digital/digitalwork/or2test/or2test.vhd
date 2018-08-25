Library ieee;
Use ieee.std_logic_1164.all;

entity or2test is 
port (a, b : in bit;
y 	: out bit);
end or2test;

architecture sample of or2test is
begin
y <= a or b ;
end sample; 
