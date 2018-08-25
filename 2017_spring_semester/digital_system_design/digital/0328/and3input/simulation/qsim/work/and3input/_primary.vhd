library verilog;
use verilog.vl_types.all;
entity and3input is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        c               : in     vl_logic;
        o               : out    vl_logic
    );
end and3input;
