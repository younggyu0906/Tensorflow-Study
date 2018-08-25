library verilog;
use verilog.vl_types.all;
entity logic is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        c               : in     vl_logic;
        d               : in     vl_logic;
        y_out           : out    vl_logic
    );
end logic;
