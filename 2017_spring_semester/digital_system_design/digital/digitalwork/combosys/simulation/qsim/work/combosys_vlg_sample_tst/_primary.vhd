library verilog;
use verilog.vl_types.all;
entity combosys_vlg_sample_tst is
    port(
        in1             : in     vl_logic;
        in2             : in     vl_logic;
        in3             : in     vl_logic;
        in4             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end combosys_vlg_sample_tst;
