onerror {quit -f}
vlib work
vlog -work work rcaAdder.vo
vlog -work work rcaAdder.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.rcaAdder_vlg_vec_tst
vcd file -direction rcaAdder.msim.vcd
vcd add -internal rcaAdder_vlg_vec_tst/*
vcd add -internal rcaAdder_vlg_vec_tst/i1/*
add wave /*
run -all
