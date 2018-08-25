library verilog;
use verilog.vl_types.all;
entity logic2 is
    port(
        xin             : in     vl_logic_vector(1 downto 0);
        y_out           : out    vl_logic_vector(3 downto 0)
    );
end logic2;
