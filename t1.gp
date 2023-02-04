#!/usr/bin/gnuplot

set terminal pngcairo
set output 'p1.png'

set datafile separator ","

set title "Pressure  1 MAP"

set xlabel "Staion number"

set nokey
Shadecolor = "#80E0A080"

plot "step_2.csv" using 1:3:4 with filledcurve fc rgb Shadecolor title "Shaded error region", "step_2.csv" using 1:2 smooth mcspline lw 2
