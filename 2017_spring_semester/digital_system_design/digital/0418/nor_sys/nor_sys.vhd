library ieee;
use ieee.std_logic_1164.all;

entity nor_sys is
	port ( a 	: in std_logic_vector(7 downto 0);
	      c 		: out std_logic );
end nor_sys;

architecture sample of nor_sys is
	component norx
      	generic(size : integer);
      	port( x : in std_logic_vector(size-1 downto 0);
        	     z : out std_logic );
     	end component;		
begin 
	ux : norx generic map(8) port map(a, c);
end sample;