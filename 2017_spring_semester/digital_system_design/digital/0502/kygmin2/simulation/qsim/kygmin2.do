onerror {quit -f}
vlib work
vlog -work work kygmin2.vo
vlog -work work kygmin2.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.kygmin2_vlg_vec_tst
vcd file -direction kygmin2.msim.vcd
vcd add -internal kygmin2_vlg_vec_tst/*
vcd add -internal kygmin2_vlg_vec_tst/i1/*
add wave /*
run -all
