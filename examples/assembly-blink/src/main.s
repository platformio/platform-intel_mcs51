.module blink

.area HOME (CODE)
.area XSEG (DATA)
.area PSEG (DATA)
.area INTV (ABS)
.org 0x0000
_int_reset:
	ljmp main

.area CSEG (ABS, CODE)
.org 0x0090
main:
	cpl P3.2
	acall delay
	cpl P3.3
	acall delay
	cpl P3.4
	acall delay
	cpl P3.5
	acall delay
	nop
	nop
	nop
	nop
	sjmp main

delay:
	mov r4, #0x00
	mov r3, #0x00
wait:
	djnz r4, wait
	djnz r3, wait
	ret