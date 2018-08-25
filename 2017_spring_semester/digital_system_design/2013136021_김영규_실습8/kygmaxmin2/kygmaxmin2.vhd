library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity kygmaxmin2 is
	port ( x, y : in  std_logic_vector(4 downto 0);
            max, min : out std_logic_vector(4 downto 0) );
end kygmaxmin2;

architecture sample of kygmaxmin2 is
begin
	process(x, y)
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
   variable temp1, temp2 : std_logic_vector(4 downto 0);
  	begin
      maxmin(x, y, temp1, temp2);
         max <= temp1;
         min <= temp2;
  	end process;
end sample;