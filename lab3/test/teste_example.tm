* TINY Compilation to TM Code
* File: test/teste_example.tm
* Begin of execution.
* Ignored Void Declaration
* FuncK
* Ignored Integer Declaration
* -> assign
* -> Id
  0:  r_0 = a;	load id value
* <- Id
* -> Op
* -> Const
  1:  r_0 = 1;	load const
* <- Const
  2:     ST  0,0(6) 	op: push left
* -> Const
  3:  r_0 = 2;	load const
* <- Const
  4:     LD  1,0(6) 	op: load left
  5:  r_0  = c + d;	op +
* <- Op
* <- assign
* <- if
* End of execution.
 28:   HALT  0,0,0 	
