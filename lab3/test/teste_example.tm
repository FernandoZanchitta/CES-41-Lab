* TINY Compilation to TM Code
* File: test/teste_example.tm
* Standard prelude:
  0:     LD  6,0(0) 	load maxaddress from location 0
  1:     ST  0,0(0) 	clear location 0
* End of standard prelude.
* Ignored Void Declaration
* FuncK
* Ignored Integer Declaration
* Ignored Integer Declaration
* Vark
* Ignored Integer Declaration
* Vark
* -> if
* -> Op
* -> Id
  2:     LD  0,3(5) 	load id value
* <- Id
  3:     ST  0,0(6) 	op: push left
* -> Id
  4:     LD  0,2(5) 	load id value
* <- Id
  5:     LD  1,0(6) 	op: load left
  6:    SUB  0,1,0 	op ==
  7:    JEQ  0,2(7) 	br if true
  8:    LDC  0,0(0) 	false case
  9:    LDA  7,1(7) 	unconditional jmp
 10:    LDC  0,1(0) 	true case
* <- Op
t11 = * -> Op
* -> Id
 12:     LD  0,1(5) 	load id value
* <- Id
 13:     ST  0,0(6) 	op: push left
* -> Id
 14:     LD  0,2(5) 	load id value
* <- Id
 15:     LD  1,0(6) 	op: load left
 16:    SUB  0,1,0 	op ==
 17:    JEQ  0,2(7) 	br if true
 18:    LDC  0,0(0) 	false case
 19:    LDA  7,1(7) 	unconditional jmp
 20:    LDC  0,1(0) 	true case
* <- Op
if_true t11 goto L11* -> assign
* -> Id
 21:     LD  0,3(5) 	load id value
* <- Id
* -> Const
 22:    LDC  0,1(0) 	load const
* <- Const
* <- assign
goto L23L11: * -> assign
* -> Id
 24:     LD  0,3(5) 	load id value
* <- Id
* -> Const
 25:    LDC  0,0(0) 	load const
* <- Const
* <- assign
L23: * -> assign
* -> Id
 26:     LD  0,3(5) 	load id value
* <- Id
* -> Const
 27:    LDC  0,1(0) 	load const
* <- Const
* <- assign
* <- if
* End of execution.
 28:   HALT  0,0,0 	
