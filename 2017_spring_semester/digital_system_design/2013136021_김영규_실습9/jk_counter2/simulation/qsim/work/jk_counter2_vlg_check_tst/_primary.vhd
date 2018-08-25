library verilog;
use verilog.vl_types.all;
entity jk_counter2_vlg_check_tst is
    port(
        y_out           : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end jk_counter2_vlg_check_tst;
