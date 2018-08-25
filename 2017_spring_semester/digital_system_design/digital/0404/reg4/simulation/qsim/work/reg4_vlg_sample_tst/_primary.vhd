library verilog;
use verilog.vl_types.all;
entity reg4_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        data_in         : in     vl_logic_vector(3 downto 0);
        reg_in          : in     vl_logic_vector(3 downto 0);
        reg_out         : in     vl_logic_vector(3 downto 0);
        sampler_tx      : out    vl_logic
    );
end reg4_vlg_sample_tst;
