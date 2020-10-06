reset
set terminal png 
set output 'devplane.png'
set pm3d
set view map

#set cbrange [0:2]
splot 'devplane.txt' u 1:2:3 with pm3d

