library verilog;
use verilog.vl_types.all;
entity ringCount_vlg_check_tst is
    port(
        count           : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end ringCount_vlg_check_tst;
