library verilog;
use verilog.vl_types.all;
entity kygmin2_vlg_check_tst is
    port(
        y_out           : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end kygmin2_vlg_check_tst;
