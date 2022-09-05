#include "Conv.h"

void Conv::run() {
	// vvvvv put your code here vvvvv
   if(rst==1)
   {
       rom_rd.write(0);
       rom_addr.write(0);
       data_out.write(0);
       data_out_signal.write(0);
   }
   else if(count>111)
   {
     if(first<=78)
     {
         if(first%10!=0&&first%10!=9)
         {
             sum=0;
             for(int i=0;i<9;i++)
             {
               idx=first+(i/3)*10+(i%3);
               sum=sum+rom_m[idx]*rom_m[101+i];
             }
             sum+=rom_m[110];
             if(sum<0)
             {
                 data_out.write(0);
                 data_out_signal.write(1);
             }
             else
             {
                 data_out.write(sum);
                 data_out_signal.write(1);
             }
         }
         else
         {
           data_out_signal.write(0);
         }
         first++;
     }
     else
     {
       data_out_signal.write(0);
     }
   }
   else
   {
     rom_rd.write(1);
     rom_addr.write(count);
     count++;
     if(count>111)
       rom_rd.write(0);
     if(count!=1)
     {
       if(data_in==0)
        count-=2;
       else
        rom_m[count-2]=data_in;  
     }
   }
	// ^^^^^ put your code here ^^^^^
}



