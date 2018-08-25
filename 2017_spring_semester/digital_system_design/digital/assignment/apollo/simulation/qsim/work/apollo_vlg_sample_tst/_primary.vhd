library verilog;
use verilog.vl_types.all;
entity apollo_vlg_sample_tst is
    port(
        battery_voltage : in     vl_logic_vector(31 downto 0);
        sampler_tx      : out    vl_logic
    );
end apollo_vlg_sample_tst;
