; division of two 8 bit numbers

mvi a, 06
mvi b, 02
mvi a, 00


loop: inrc
sub b
jnz loop

hlt