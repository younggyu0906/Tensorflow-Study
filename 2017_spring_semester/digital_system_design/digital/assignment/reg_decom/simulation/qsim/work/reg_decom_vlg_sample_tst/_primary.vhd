library verilog;
use verilog.vl_types.all;
entity reg_decom_vlg_sample_tst is
    port(
        reg3            : in     vl_logic_vector(11 downto 0);
        sampler_tx      : out    vl_logic
    );
end reg_decom_vlg_sample_tst;
