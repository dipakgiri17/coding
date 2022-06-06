; factorial in 8085

mvi h, 80
mvi l, 00

mov b, m
mov d, 01 ; to store result

fact: call mul
dcr
jnz fact
inx h
mov m, d
hlt


mul: mov e, d
xra a  ; a = 0

ml: add d
dcr e
jnz ml
mov d, a
ret

; input - 05(H)
; output - 78(H)