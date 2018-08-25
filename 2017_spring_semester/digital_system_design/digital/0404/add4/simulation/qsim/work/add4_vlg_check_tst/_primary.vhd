library verilog;
use verilog.vl_types.all;
entity add4_vlg_check_tst is
    port(
        y_out           : in     vl_logic_vector(4 downto 0);
        sampler_rx      : in     vl_logic
    );
end add4_vlg_check_tst;
