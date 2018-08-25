library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
	port( w, x, y 		: in std_logic;
           carry, sum 		: out std_logic ); 
end full_adder;

architecture sample of full_adder is          
	signal temp_c1, temp_c2, temp_s : std_logic;    
	component HA port( x, y : in std_logic;		-- component HA 선언
      	            c, s : out std_logic);        	-- (반가산기)
 	end component;
  
	component or_2 port( a, b : in std_logic;	      -- component OR2 선언
                               o : out std_logic );
	end component;

begin
	u1 : HA port map(w, x, temp_c1, temp_s);		-- HA를 사례화 
    	u2 : HA port map(temp_s, y, temp_c2, sum);  	-- HA를 사례화 
    	u3 : or_2 port map(temp_c1, temp_c2, carry);    -- OR2게이트를 사례화
end sample;