library verilog;
use verilog.vl_types.all;
entity reg_combin_vlg_sample_tst is
    port(
        reg1            : in     vl_logic_vector(3 downto 0);
        reg2            : in     vl_logic_vector(7 downto 0);
        sampler_tx      : out    vl_logic
    );
end reg_combin_vlg_sample_tst;
