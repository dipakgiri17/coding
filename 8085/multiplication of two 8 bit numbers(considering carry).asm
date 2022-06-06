; multiplication of two 8 bit numbers(considering carry)

mvi a, 00
mvi b, 02
mvi c, 03

loop: add b
dcr c
jnz loop
hlt

