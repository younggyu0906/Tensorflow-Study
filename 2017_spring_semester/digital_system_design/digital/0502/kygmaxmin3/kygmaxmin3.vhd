library ieee;
  use ieee.std_logic_1164.all;
  use work.mypack1.all;
  
  entity kygmaxmin3 is
	port ( x, y : in  std_logic_vector(4 downto 0);
	      max, min : out std_logic_vector(4 downto 0) ); 
  end kygmaxmin3;
  
  architecture sample of kygmaxmin3 is
  begin
  	process(x, y)
  		variable temp1, temp2 : std_logic_vector(4 downto 0);
  	begin
        	maxmin( x, y, temp1, temp2 );
         	max <= temp1;
				min <= temp2;
  	end process;
  end sample;