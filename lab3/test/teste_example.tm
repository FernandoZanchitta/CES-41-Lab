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
* -> assign
* -> Id
  2:     LD  0,3(5) 	load id value
* <- Id
* -> Id
  3:     LD  0,4(5) 	load id value
* <- Id
* <- assign
* End of execution.
  4:   HALT  0,0,0 	
