library verilog;
use verilog.vl_types.all;
entity ringCount is
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        count           : out    vl_logic_vector(7 downto 0)
    );
end ringCount;
