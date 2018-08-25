library verilog;
use verilog.vl_types.all;
entity reg4_vlg_check_tst is
    port(
        reg_in          : in     vl_logic_vector(3 downto 0);
        reg_out         : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end reg4_vlg_check_tst;
