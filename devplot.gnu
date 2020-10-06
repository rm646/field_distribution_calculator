 set term png
 set output 'deviation_n1.png'
 unset key
 plot './deviation.txt' u 1:2 w l, './deviation.txt' u 1:3 w l, './deviation.txt' u 1:4 w l