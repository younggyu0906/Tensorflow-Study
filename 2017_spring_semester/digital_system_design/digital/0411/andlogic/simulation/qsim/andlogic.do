onerror {quit -f}
vlib work
vlog -work work andlogic.vo
vlog -work work andlogic.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.andlogic_vlg_vec_tst
vcd file -direction andlogic.msim.vcd
vcd add -internal andlogic_vlg_vec_tst/*
vcd add -internal andlogic_vlg_vec_tst/i1/*
add wave /*
run -all
