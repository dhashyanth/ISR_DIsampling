# ISR_DIsamplng
Assingment
A function with the prototype `int ISRDIsampling();` is used in an ISR (Interrupt Service
Routine) to poll the condition of 8 GPIO pins at 100Hz, a variable `g_ReadDIpinSts` defined
globally contains the status of each of these GPIO pins at any given time, this variable is
updated elsewhere.
A variable `g_AppDIpinSts` defined in global scope is to be updated by function `int
ISRDIsampling();` to showcase the actual status of each pin.
Complete function: `int ISRDIsampling();` such that each GPIO state is preserved in variable
`g_AppDIpinSts` for at least 10 ISR calls before it is reset by the ISR.
