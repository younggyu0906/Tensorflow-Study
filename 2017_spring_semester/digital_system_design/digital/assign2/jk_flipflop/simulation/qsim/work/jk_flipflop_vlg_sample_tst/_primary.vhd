library verilog;
use verilog.vl_types.all;
entity jk_flipflop_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        clr             : in     vl_logic;
        j               : in     vl_logic;
        k               : in     vl_logic;
        pr              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end jk_flipflop_vlg_sample_tst;
