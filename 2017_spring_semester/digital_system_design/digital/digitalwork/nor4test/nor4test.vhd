Library ieee;
Use ieee.std_logic_1164.all;

entity nor4test is
port( a, b, c, d	: in bit;
y 	: out bit );
end nor4test ;

architecture sample of nor4test is
begin
y <= not ( a or b or c or d );
end sample;