library verilog;
use verilog.vl_types.all;
entity system is
    port(
        k1              : in     vl_logic;
        k2              : in     vl_logic;
        k3              : in     vl_logic;
        y_out           : out    vl_logic
    );
end system;
