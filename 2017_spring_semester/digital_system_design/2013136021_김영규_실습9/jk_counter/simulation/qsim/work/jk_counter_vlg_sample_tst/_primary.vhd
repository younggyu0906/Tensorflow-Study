library verilog;
use verilog.vl_types.all;
entity jk_counter_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end jk_counter_vlg_sample_tst;
