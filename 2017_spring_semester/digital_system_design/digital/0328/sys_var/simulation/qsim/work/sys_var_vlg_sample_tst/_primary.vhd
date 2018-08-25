library verilog;
use verilog.vl_types.all;
entity sys_var_vlg_sample_tst is
    port(
        i               : in     vl_logic;
        j               : in     vl_logic;
        k               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end sys_var_vlg_sample_tst;
