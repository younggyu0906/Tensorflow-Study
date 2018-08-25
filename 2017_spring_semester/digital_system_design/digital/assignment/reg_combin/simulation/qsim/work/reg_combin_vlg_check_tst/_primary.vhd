library verilog;
use verilog.vl_types.all;
entity reg_combin_vlg_check_tst is
    port(
        reg3            : in     vl_logic_vector(11 downto 0);
        sampler_rx      : in     vl_logic
    );
end reg_combin_vlg_check_tst;
