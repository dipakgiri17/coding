; multiplication of two 8-bit number.
; considering carry.


MVI A, 0x1F
MVI B, 0x02
MVI C, 0x03
MVI D, 0x00 ; FOR CARRY
MVI E, 0x00 ; TEMP VARIABLE TO STORE A

LOOP: ADD B
  JNC NOCARRY
  MOV E, A
  RAL 
  ANI 0x01
  ADD D
  MOV D, A ; CARRY
  MOV A, E
      
 NOCARRY: DCR C
   JNZ LOOP
   JMP END

END: LXI H, 0x8500 
MOV M, D 
HLT
