#include "Neuron_arg.h"

void Neuron::neuron() {
 
	// vvvvv put your code here vvvvv

  i1=input1.read();
  i2=input2.read();
  t=i1+i2-5;
  count=0.5+0.25*t-(1/48)*t*t*t+(1/480)*t*t*t*t*t;
  if(count>=1)
    output.write(1);
  else if(count<=0)
    output.write(0);
  else
    output.write(count);
	// ^^^^^ put your code here ^^^^^
}