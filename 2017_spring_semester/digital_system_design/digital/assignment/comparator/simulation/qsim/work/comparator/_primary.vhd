library verilog;
use verilog.vl_types.all;
entity comparator is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        a_out           : out    vl_logic;
        b_out           : out    vl_logic;
        s_out           : out    vl_logic
    );
end comparator;
