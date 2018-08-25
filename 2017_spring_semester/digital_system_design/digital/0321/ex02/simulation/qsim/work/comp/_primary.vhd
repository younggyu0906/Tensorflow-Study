library verilog;
use verilog.vl_types.all;
entity comp is
    port(
        a               : in     vl_logic_vector(1 downto 0);
        b               : in     vl_logic_vector(1 downto 0);
        equal           : out    vl_logic
    );
end comp;
