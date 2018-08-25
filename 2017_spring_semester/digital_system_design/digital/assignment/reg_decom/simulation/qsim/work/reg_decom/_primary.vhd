library verilog;
use verilog.vl_types.all;
entity reg_decom is
    port(
        reg1            : out    vl_logic_vector(3 downto 0);
        reg2            : out    vl_logic_vector(7 downto 0);
        reg3            : in     vl_logic_vector(11 downto 0)
    );
end reg_decom;
