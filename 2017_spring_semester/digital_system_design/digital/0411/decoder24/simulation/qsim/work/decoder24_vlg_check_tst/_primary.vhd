library verilog;
use verilog.vl_types.all;
entity decoder24_vlg_check_tst is
    port(
        y               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end decoder24_vlg_check_tst;
