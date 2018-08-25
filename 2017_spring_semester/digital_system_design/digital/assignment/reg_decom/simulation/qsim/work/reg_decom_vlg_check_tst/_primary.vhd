library verilog;
use verilog.vl_types.all;
entity reg_decom_vlg_check_tst is
    port(
        reg1            : in     vl_logic_vector(3 downto 0);
        reg2            : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end reg_decom_vlg_check_tst;
