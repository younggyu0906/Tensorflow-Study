library verilog;
use verilog.vl_types.all;
entity combosys is
    port(
        in1             : in     vl_logic;
        in2             : in     vl_logic;
        in3             : in     vl_logic;
        in4             : in     vl_logic;
        o1              : out    vl_logic;
        o2              : out    vl_logic;
        o3              : out    vl_logic
    );
end combosys;
