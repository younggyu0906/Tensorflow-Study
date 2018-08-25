library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
	port( w, x, y 		: in std_logic;
           carry, sum 		: out std_logic ); 
end full_adder;

architecture sample of full_adder is          
	signal temp_c1, temp_c2, temp_s : std_logic;    
	component HA port( x, y : in std_logic;
      	            c, s : out std_logic);   
 	end component;
  
	component OR_2 port( a, b : in std_logic;	   
                               c : out std_logic );
	end component;

begin
	u1 : HA port map(w, x, temp_c1, temp_s);	
    	u2 : HA port map(temp_s, y, temp_c2, sum); 
    	u3 : OR_2 port map(temp_c1, temp_c2, carry); 
end sample;