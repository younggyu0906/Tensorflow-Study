library verilog;
use verilog.vl_types.all;
entity jk_flipflop is
    port(
        clk             : in     vl_logic;
        j               : in     vl_logic;
        k               : in     vl_logic;
        pr              : in     vl_logic;
        clr             : in     vl_logic;
        y_out           : out    vl_logic
    );
end jk_flipflop;
