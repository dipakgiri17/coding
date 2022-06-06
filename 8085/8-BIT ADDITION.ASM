; Add two 8-bit numbers. considering carry.
; Store output at 8550H

MVI A, 0xFF ; Load numbers
MVI B, 0xFF
ADD B ; Add A and B, then store at A.

LXI H, 0x8000
MOV M, A ; Store the result store result in Memory

RAL
ANI 1
INX H
MOV M, A ; Store carry in Memory location 8001

HLT ; Terminate the program.
<<<<<<<< HEAD:8085/addition of two 8 bit numbers(considering carry).asm

; if we add FF and FF the result should be FE with carry 1.
========
>>>>>>>> c7287bafccd29429313a414ea60ea57b57f60eec:8085/8-BIT ADDITION.ASM
