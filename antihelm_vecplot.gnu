set term png
set nokey
set xlabel 'x/m'
set ylabel 'y/m'
set title 'Plot of B field vectors in plane. Arrow length is meaningless.'
set output 'helm_vecplot.png'
plot './helmvector.txt' u 1:2:3:4 with vectors

