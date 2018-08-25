library verilog;
use verilog.vl_types.all;
entity reg_combin is
    port(
        reg1            : in     vl_logic_vector(3 downto 0);
        reg2            : in     vl_logic_vector(7 downto 0);
        reg3            : out    vl_logic_vector(11 downto 0)
    );
end reg_combin;
