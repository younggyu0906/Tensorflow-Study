library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
package mypack1 is
	procedure maxmin(	a, b : in  std_logic_vector;
							c, d : out std_logic_vector );
end mypack1;

package body mypack1 is
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
end;