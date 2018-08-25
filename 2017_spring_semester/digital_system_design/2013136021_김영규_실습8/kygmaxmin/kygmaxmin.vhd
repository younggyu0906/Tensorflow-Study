library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity kygmaxmin is
port ( x, y : in std_logic_vector(4 downto 0);
      max, min	: out std_logic_vector(4 downto 0) );
end kygmaxmin;

architecture sample of kygmaxmin is
	procedure maxmin(	a, b : in  std_logic_vector;
      		c, d : out std_logic_vector ) is
	begin
		if a > b then
			c := a;
			d := b;
		else
			c := b;
			d := a;
		end if;
	end maxmin;
	begin
	process(x, y)
		variable temp1, temp2 : std_logic_vector( 4 downto 0 );
		begin
        	maxmin( x, y, temp1, temp2 );
            	max <= temp1;
             	min <= temp2;
    	end process;
	end sample;