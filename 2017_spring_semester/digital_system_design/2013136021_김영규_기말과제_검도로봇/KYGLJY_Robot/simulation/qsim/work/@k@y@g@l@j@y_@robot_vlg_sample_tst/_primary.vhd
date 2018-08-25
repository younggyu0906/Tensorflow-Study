library verilog;
use verilog.vl_types.all;
entity KYGLJY_Robot_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        HS_Echo         : in     vl_logic;
        IR1_input       : in     vl_logic;
        IR2_input       : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end KYGLJY_Robot_vlg_sample_tst;
