; multiplication of two 8-bit number.
; considering carry.


MVI A, 00

MVI B, 0xFF
MVI C, 0x03

MVI D, 00 ; FOR CARRY
MVI E, 00 ; TEMP VARIABLE TO STORE A

LOOP: ADD B

  MOV E, A
  RAL 
  ANI 01
  ADD D
  MOV D, A ; CARRY
  MOV A, E

  DCR C
  JNZ LOOP

LXI H, 0x8500
MOV M, A
INX H
MOV M, D

HLT
