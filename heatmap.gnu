#short script containing the necessary command to plot a heatmap of the 1:2
#plane, with associated :3 magnitudes

reset
set terminal png 
set output 'antihelmholtz.png'
set pm3d
set view map
set logscale cb
set cbrange [1e-18:2]
splot 'antihelmholtz.txt' u 1:2:3 with pm3d

