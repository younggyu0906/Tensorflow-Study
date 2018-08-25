library verilog;
use verilog.vl_types.all;
entity kygmin1_vlg_check_tst is
    port(
        seg1            : in     vl_logic_vector(6 downto 0);
        seg2            : in     vl_logic_vector(6 downto 0);
        seg3            : in     vl_logic_vector(6 downto 0);
        segsel1         : in     vl_logic;
        segsel2         : in     vl_logic;
        segsel3         : in     vl_logic;
        y_out           : in     vl_logic_vector(2 downto 0);
        sampler_rx      : in     vl_logic
    );
end kygmin1_vlg_check_tst;
