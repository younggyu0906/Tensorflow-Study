onerror {quit -f}
vlib work
vlog -work work laundry.vo
vlog -work work laundry.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.laundry_vlg_vec_tst
vcd file -direction laundry.msim.vcd
vcd add -internal laundry_vlg_vec_tst/*
vcd add -internal laundry_vlg_vec_tst/i1/*
add wave /*
run -all
