library verilog;
use verilog.vl_types.all;
entity logic2_vlg_sample_tst is
    port(
        xin             : in     vl_logic_vector(1 downto 0);
        sampler_tx      : out    vl_logic
    );
end logic2_vlg_sample_tst;
