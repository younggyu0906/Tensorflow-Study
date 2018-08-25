library verilog;
use verilog.vl_types.all;
entity laundry_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        l_start         : in     vl_logic;
        pollution       : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end laundry_vlg_sample_tst;
