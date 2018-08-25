library verilog;
use verilog.vl_types.all;
entity reg4 is
    port(
        clk             : in     vl_logic;
        data_in         : in     vl_logic_vector(3 downto 0);
        reg_in          : inout  vl_logic_vector(3 downto 0);
        reg_out         : inout  vl_logic_vector(3 downto 0)
    );
end reg4;
