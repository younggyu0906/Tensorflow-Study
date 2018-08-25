library verilog;
use verilog.vl_types.all;
entity hw01 is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        agtb            : out    vl_logic;
        altb            : out    vl_logic
    );
end hw01;
