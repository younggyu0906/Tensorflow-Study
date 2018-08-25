library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity movement is
        port( clock : in std_logic;
              m_state : in integer;
              q1, q2 : out std_logic_vector( 3 downto 0 ) );
end movement;

architecture sample of movement is
   signal d1, d2, s1, s2 : std_logic;
   signal m1, m2 : integer;
   
   component stepmotor
      port( clk, reset, dir, stop_start : in std_logic;
            a : in integer;
            q : out std_logic_vector( 3 downto 0 ));
   end component;
   
   begin
   
    p1 : process(m_state)
      begin
      if (m_state = 0) then   -- slow forward
         d1 <= '1';
         d2 <= '1';
         s1 <= '0';
         s2 <= '0';
         m1 <= 7;
         m2 <= 7;
      elsif (m_state = 1) then   -- fast forward
         d1 <= '1';
         d2 <= '1';
         s1 <= '0';
         s2 <= '0';
         m1 <= 4;
         m2 <= 4;
      elsif (m_state = 2) then   -- backward
         d1 <= '0';
         d2 <= '0';
         s1 <= '0';
         s2 <= '0';
         m1 <= 4;
         m2 <= 4;
      elsif (m_state = 3) then   -- left
         d1 <= '1';
         d2 <= '1';
         s1 <= '1';
         s2 <= '0';
         m1 <= 4;
         m2 <= 4;
      elsif (m_state = 4) then   -- right
         d1 <= '1';
         d2 <= '1';
         s1 <= '0';
         s2 <= '1';
         m1 <= 4;
         m2 <= 4;
      else   -- stop
         d1 <= '1';
         d2 <= '1';
         s1 <= '1';
         s2 <= '1';
         m1 <= 4;
         m2 <= 4;
      end if;
   end process;
   
   u1 : stepmotor port map (clock, '0', d1, s1, m1, q1);
   u2 : stepmotor port map (clock, '0', d2, s2, m2, q2);

end sample;