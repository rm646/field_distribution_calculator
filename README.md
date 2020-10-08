## Introduction

I wrote this code sometime in 2012 I think. It's designed to calculate the
electromagnetic field produced by a current loop and a pair of Helmholtz coils.
I'm sharing it now so that: 1) I can show that I've written c++, and
2) as inspiration to write better code in future.

## Implementation notes

I created a struct called field_point which held two Vec3 objects as its
members: one for a position and one for a vector associated with that position.
I used arrays of these structs to describe my current distribution and field
distribution. I also used a parametrisation which allowed me to easily choose
how to grid the space, and moved the description of the current distribution
to a header file so that it can be swapped out in future.
Calculating the field was done by adding elemental contributions and using the
Biot-Savart law. The code is in 'biot2.cpp' and the two header files
'fpointdef.h' and 'ver2loop.h'. A number of gnuplot scripts are included to
generate field heatmaps.

## Usage

After selecting which current loops to include and whether to output the vector
magnetic field, the magnitude, or the deviation from the theoretical values by
commenting out bits in the main function, I compiled with:
```
g++ biot2.cpp -o biot2
```
Then ran and dumped the space separated values output in a file, e.g.
```
./biot2 > output.tsv
```
Finally, I plotted the results with various gnuplot scripts.
