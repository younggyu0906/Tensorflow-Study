library verilog;
use verilog.vl_types.all;
entity jk_counter2 is
    port(
        clk             : in     vl_logic;
        y_out           : out    vl_logic_vector(3 downto 0)
    );
end jk_counter2;
