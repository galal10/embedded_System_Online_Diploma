# ARM Course - 1st lab
## After Reset
  We work in Thread mode with privileged access using the main stack.

![1](https://github.com/galal10/embedded_System_Online_Diploma/assets/67324703/f7cb767c-82bd-49ae-bfba-a4e48715159f)

## After Interrupt is happened 
  The mode turned to Handler mode in Privileged access using the main stack.
  The vector number is 23 but according to the cortexM3 user manual, ISR will be
  (16 + 23 = 39)

![3](https://github.com/galal10/embedded_System_Online_Diploma/assets/67324703/e0e6132f-09d1-4f8a-9fef-774dd2cbec3f)

## LR register
  During the execution of an interrupt service routine, LR holds a special 
  value to indicate whether MSP or PSP is used. 
  "in our case study, we used the Main stack"

![4](https://github.com/galal10/embedded_System_Online_Diploma/assets/67324703/b5b491f7-27ec-47ea-8134-d3a956fad883)
