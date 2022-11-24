* TINY Compilation to TM Code
* File: test/teste_example.tm
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* Begin of execution.
* Ignored Void Declaration
* FuncK
* Ignored Integer Declaration
* -> if
t0 = * -> Op
* -> Const
  2:  r_0 = 3;	load const
* <- Const
* -> Id
  3:  r_1 = a;	load id value
* <- Id
  4:    SUB  0,1,0 	op ==
  5:    JEQ  0,2(7) 	br if true
  6:    LDC  0,0(0) 	false case
  7:    LDA  7,1(7) 	unconditional jmp
  8:    LDC  0,1(0) 	true case
* <- Op
if_true t0 goto L0* -> assign
* -> Const
  9:  r_2 = 5;	load const
* <- Const
a = t0* <- assign
goto L10L24576: * -> assign
* -> Const
 11:  r_3 = 2;	load const
* <- Const
a = t0* <- assign
* <- if
* End of execution.
 12:   HALT  0,0,0 	
