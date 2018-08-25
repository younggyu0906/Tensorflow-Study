  library ieee;
  use ieee.std_logic_1164.all;
  
  entity logic is
  	port( a, b, c 	: in std_logic;
                y	: out std_logic );
  end logic;
  
  architecture sample of logic is  
	signal w, x : std_logic;
	
  begin                                           
  	no1 : process(a, b)	-- process와 process 간은 병행처리된다
 	begin
		if (a='1') or (b='1') then w <= '1'; 	-- w <= a or b문과 동일
               	else w <= '0'; 			-- process 내부는 순차문
               	end if;
	end process;
	
        no2 : process(b, c)   			-- x <= b nand c와 동일
	begin                 			-- process 내부는 순차문
		if (b='0') or (c='0') then x <= '1';
                else x <= '0';
                end if;
	end process;
	
        no3 : process(w, x)     			-- y <= w xor x와 동일
        begin   	                       	-- process 내부는 순차문
                if (w=x) then y <= '0';
                else y <= '1';
                end if;
	end process;
  end sample;