onerror {quit -f}
vlib work
vlog -work work KYGLJY_Robot.vo
vlog -work work KYGLJY_Robot.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.KYGLJY_Robot_vlg_vec_tst
vcd file -direction KYGLJY_Robot.msim.vcd
vcd add -internal KYGLJY_Robot_vlg_vec_tst/*
vcd add -internal KYGLJY_Robot_vlg_vec_tst/i1/*
add wave /*
run -all
