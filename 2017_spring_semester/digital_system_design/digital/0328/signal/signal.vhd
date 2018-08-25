library ieee;
use ieee.std_logic_1164.all;
entity system is 
  	port( k1, k2, k3 	: in std_logic; 	-- signal k1, k2, k3 선언
                 y_out	: out std_logic ); 	-- signal y_out 선언
end system;
architecture sample of system is
  	signal cn : std_logic;    		-- signal cn 선언
begin             		-- signal 선언위치 : architecture와 begin사이
      	cn <= k1 nand k2;  		-- signal에 파형 대입
      	y_out <= cn xor k3;
end sample;