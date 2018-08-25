library verilog;
use verilog.vl_types.all;
entity add4 is
    port(
        a               : in     vl_logic_vector(3 downto 0);
        b               : in     vl_logic_vector(3 downto 0);
        c               : in     vl_logic;
        y_out           : out    vl_logic_vector(4 downto 0)
    );
end add4;
