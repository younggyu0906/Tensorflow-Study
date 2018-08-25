library ieee; 
use ieee.std_logic_1164.all;

entity logic2 is
	port( xin	 	: in std_logic_vector(1 downto 0);	  
           y_out 	: out std_logic_vector(3 downto 0) );
end logic2;	

architecture sample of logic2 is
begin
	with xin select
   		y_out <=	 "0001" when "00",
           		 "0010" when "01",
           		 "0100" when "10",
               	 "1000" when others;
end sample;