library ieee; 
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
  entity hw02 is
  	port( a, b 	: in std_logic_vector(3 downto 0);
         agtb, altb 	: out std_logic ); 
  end hw02;
  architecture sample  of hw02 is
  begin
	process(a, b)
	begin
		if a > b then
			agtb <= '1';
			altb <= '0';
		else
			agtb <= '0';
			altb <= '1';
		end if; 
	end process;
  end sample ;