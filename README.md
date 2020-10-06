## Introduction

I wrote this code sometime in 2012 I think. It's designed to calculate the
electromagnetic field produced by a current loop and a pair of Helmholtz coils.
I'm sharing it now so that: 1) I can show that I've written c++, and
2) as inspiration to write better code in future.

## Notes

I created a struct called field_point which held two Vec3 objects as its
members: one for a position and one for a vector associated with that position.
I used arrays of these structs to describe my current distribution and field
distribution. I also used a parametrisation which allowed me to easily choose
how to grid the space, and moved the description of the current distribution
to a header file so that it can be swapped out in future.
Calculating the field was done by adding elemental contributions and using the
Biot-Savart law. I quite enjoyed this task, although the code got a little
scrappy towards the end. The code is
in 'biot2.cpp' and the two header files 'fpointdef.h' and 'ver2loop.h'.
A number of gnuplot scripts are included to generate field heatmaps.
