library verilog;
use verilog.vl_types.all;
entity ex02 is
    port(
        d               : in     vl_logic;
        en              : in     vl_logic;
        q               : out    vl_logic
    );
end ex02;
