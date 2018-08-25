onerror {quit -f}
vlib work
vlog -work work comparator.vo
vlog -work work comparator.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.comparator_vlg_vec_tst
vcd file -direction comparator.msim.vcd
vcd add -internal comparator_vlg_vec_tst/*
vcd add -internal comparator_vlg_vec_tst/i1/*
add wave /*
run -all
