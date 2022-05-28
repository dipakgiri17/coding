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
