library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
package kygcla is
	procedure cla(	a, b, c_in : in  std_logic;
						sum : out std_logic;
						carry : out std_logic);
end kygcla;

package body kygcla is
	procedure cla(	a, b, c_in : in  std_logic;
                  sum, carry : out std_logic) is
  	begin
		sum := (a xor b) xor c_in;
		carry := (a and b) or ((a xor b) and c_in);
   end cla;
end;