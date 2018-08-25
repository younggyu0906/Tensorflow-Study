Library ieee;
Use ieee.std_logic_1164.all;

entity combosys is
port ( in1, in2, in3, in4 	: in bit ;
o1, o2, o3	: out bit ) ; 
end combosys ;
architecture sample of combosys is
begin
o1 <= in1 or in2 ;
o2 <= in2 nand in3 ;
o3 <= not(in4) ;
end sample ;