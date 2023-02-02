#!/usr/bin/gnuplot

set terminal pngcairo
set output 't1.png'


set datafile separator ","


set title "T1 MAP "
set xlabel "latitude"
set yrange [-20 : 50]

set xlabel "station"
set xrange [7005 : 7790]



set ylabel "temp"


plot "step_2.csv" using 1:2:3:4 with yerrorlines
