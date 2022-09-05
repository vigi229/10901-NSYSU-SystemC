#include "ALU.h"


void ALU::run()
{
	// vvvvv put your code here vvvvv
  op=OpCode.read()[0];
  opa=OpCode.read()[2];
  opb=OpCode.read()[1];
  a=A.read();
  ai=A.read();
  b=B.read();
  bi=B.read();
  if(op==0&&opa==0&&opb==0)
   {
        AND=a&b;
        Result.write(AND);
        Overflow=0;
        Zero=0;
   }
   else if(op==1&&opa==0&&opb==0)
   {
         OR=a|b;
         Result.write(OR);
         Overflow=0;
         Zero=0;
   }
   else if(op==0&&opa==0&&opb==1)
   {
        ADD=ai+bi;
        if((ai<0&&bi<0&&ADD>0)||(ai>0&&bi>0&&ADD<0))
          Overflow=1;
        else
          Overflow=0;
        Zero=0;
        Result.write(ADD);
   }
   else if(op==1&&opa==0&&opb==1)
   {
         SUB=ai-bi;
         if((ai>0&&bi<0&&SUB<0)||(ai<0&&bi>0&&SUB>0))
          Overflow=1;
         else
          Overflow=0;
          Zero=0;
          Result.write(SUB);
   }
   else if(op==0&&opa==1&&opb==0)
   {
         if(ai<bi)
         {
             SET=1;
             Zero=0;
         }
         else
          {
             SET=0;
             Zero=1;
         }
         Overflow=0;
         Result.write(SET);
   }
   else if(op==1&&opa==1&&opb==0)
   {
         NOR=~(a|b);
         Result.write(NOR);
         Overflow=0;
         Zero=0;
   }
	// ^^^^^ put your code here ^^^^^
}