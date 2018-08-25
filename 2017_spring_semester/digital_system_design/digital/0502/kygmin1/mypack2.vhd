library ieee;
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;
   
package mypack2 is
	function min1(x, y : in std_logic_vector) return std_logic_vector;
end mypack2;

package body mypack2 is
	function min1(x, y : in std_logic_vector) return std_logic_vector is
      	variable temp : std_logic_vector(2 downto 0);
     	begin
      	if x < y then 
            	temp := x;
       	else 
              	temp := y; 
      	end if;
              return(temp);
   	end min1;
end mypack2;