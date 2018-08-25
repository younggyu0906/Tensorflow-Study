library ieee; 
  use ieee.std_logic_1164.all;
  
  entity hw01 is
  	port( a, b 	: in std_logic_vector(3 downto 0);
         agtb, altb 	: out std_logic ); 
  end hw01;
  
  architecture data_flow of hw01 is
  begin
       	agtb <= ((a(3) xor b(3)) and a(3)) or 
					  (((a(2) xor b(2)) and a(2)) and not((a(3) xor b(3)) and a(3))) or 
					  (((a(1) xor b(1)) and a(1)) and (not((a(2) xor b(2)) and a(2)) and 
					  not((a(3) xor b(3)) and a(3)))) or (((a(0) xor b(0)) and a(0)) and 
					  (not((a(1) xor b(1)) and a(1)) and (not((a(2) xor b(2)) and a(2)) and 
					  not((a(3) xor b(3)) and a(3)))));
			altb <= not(((a(3) xor b(3)) and a(3)) or 
					  (((a(2) xor b(2)) and a(2)) and not((a(3) xor b(3)) and a(3))) or 
					  (((a(1) xor b(1)) and a(1)) and (not((a(2) xor b(2)) and a(2)) and 
					  not((a(3) xor b(3)) and a(3)))) or (((a(0) xor b(0)) and a(0)) and 
					  (not((a(1) xor b(1)) and a(1)) and (not((a(2) xor b(2)) and a(2)) and 
					  not((a(3) xor b(3)) and a(3))))));
end data_flow;