#!/usr/bin/gnuplot

set terminal pngcairo transparent enhanced font "arial,10" fontscale 1.0 size 600, 400
set output 'pm3d.8.png'
set border 4095 front lt black linewidth 1.000 dashtype solid
set view map scale 1
set samples 50, 50
set isosamples 50, 50
unset surface
set style data lines
set xyplane relative 0
set title "HEIGHT MAP "
set xlabel "latitude"
set xrange [ -100 : 100 ] noreverse nowriteback

set ylabel "longitude"
set yrange [ -100 : 100 ] noreverse nowriteback

set zrange [ 0 : 200 ] noreverse nowriteback

set pm3d implicit at b

set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front noinvert bdefault
NO_ANIMATION = 1

set size square
set datafile separator ","

splot 'results.csv' using 2:3:1 with pm3d

