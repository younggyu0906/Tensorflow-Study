library verilog;
use verilog.vl_types.all;
entity signal_lamp is
    port(
        reset           : in     vl_logic;
        clk             : in     vl_logic;
        xlamp0          : out    vl_logic_vector(4 downto 0);
        xlamp1          : out    vl_logic_vector(4 downto 0);
        xlamp2          : out    vl_logic_vector(4 downto 0);
        xlamp3          : out    vl_logic_vector(4 downto 0);
        ylamp0          : out    vl_logic_vector(4 downto 0);
        ylamp1          : out    vl_logic_vector(4 downto 0);
        ylamp2          : out    vl_logic_vector(4 downto 0);
        ylamp3          : out    vl_logic_vector(4 downto 0)
    );
end signal_lamp;
