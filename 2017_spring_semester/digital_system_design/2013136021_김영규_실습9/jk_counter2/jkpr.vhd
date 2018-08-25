library ieee;
use ieee.std_logic_1164.all;

entity jkpr is
	port( clk, j,k : in std_logic;
            y_out : buffer std_logic );
end jkpr;

architecture sample of jkpr is 
begin
	process(clk)           
      begin
      	if (clk'event and clk='1') then
              	if(j ='1' and k='0') then
	                	y_out  <= '1' ;
	   	     	elsif(j='0' and k='1') then
		     		y_out <= '0';
	      		elsif(j='1' and k='1') then
	             		y_out <= not(y_out);
	      		end if;			
           	end if; 
     	end process;
end sample;