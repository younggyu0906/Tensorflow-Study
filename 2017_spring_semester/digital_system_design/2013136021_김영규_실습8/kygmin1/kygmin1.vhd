library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
use ieee.numeric_std.all;
use ieee.numeric_bit.all;
use work.mypack2.all;

entity kygmin1 is
	port( a, b 	: in std_logic_vector (2 downto 0);
         y_out 	: inout std_logic_vector (2 downto 0) := "000";
			seg1, seg2, seg3 : out std_logic_vector(6 downto 0);
			segsel1, segsel2, segsel3 : out std_logic);
end kygmin1;

architecture sample of kygmin1 is      
begin
	process(a, b)
	variable segm1, segm2, segm3 : integer range 0 to 9 := 0;
	
      begin
      	y_out <= min1(a, b);
			
			segsel1 <= '1';
			segsel2 <= '1';
			segsel3 <= '1';
			
			segm1 := conv_integer(a);
			segm2 := conv_integer(b);
			segm3 := conv_integer(y_out);
			
			case segm1 is
			when 0 =>seg1<= "1111110";
			when 1 =>seg1<= "0110000";
			when 2 =>seg1<= "1101101";
			when 3 =>seg1<= "1111001";
			when 4 =>seg1<= "0110011";
			when 5 =>seg1<= "1011011";
			when 6 =>seg1<= "1011111";
			when 7 =>seg1<= "1110000";
			when 8 =>seg1<= "1111111";
			when 9 =>seg1<= "1110011";
			when others => NULL;
			end case;
			
			case segm2 is
			when 0 =>seg2<= "1111110";
			when 1 =>seg2<= "0110000";
			when 2 =>seg2<= "1101101";
			when 3 =>seg2<= "1111001";
			when 4 =>seg2<= "0110011";
			when 5 =>seg2<= "1011011";
			when 6 =>seg2<= "1011111";
			when 7 =>seg2<= "1110000";
			when 8 =>seg2<= "1111111";
			when 9 =>seg2<= "1110011";
			when others => NULL;
			end case;

			case segm3 is
			when 0 =>seg3<= "1111110";
			when 1 =>seg3<= "0110000";
			when 2 =>seg3<= "1101101";
			when 3 =>seg3<= "1111001";
			when 4 =>seg3<= "0110011";
			when 5 =>seg3<= "1011011";
			when 6 =>seg3<= "1011111";
			when 7 =>seg3<= "1110000";
			when 8 =>seg3<= "1111111";
			when 9 =>seg3<= "1110011";
			when others => NULL;
			end case;			
	end process;
end sample;