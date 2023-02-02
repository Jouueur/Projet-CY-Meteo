#!/usr/bin/gnuplot

set terminal pngcairo
set output 'p1.png'

set datafile separator ","

set title "Pressure  1 MAP"

set xlabel "station"
set ylabel "pressure"


set ylabel "temp"

plot "step_2.csv" using 1:2:3:4 with yerrorlines
