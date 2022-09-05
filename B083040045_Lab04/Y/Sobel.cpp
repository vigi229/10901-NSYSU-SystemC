#include "Sobel.h"
// vvvvv put your code here vvvvv
void Sobel::run()
{
  if(count<256*256)
  {
     if(count<256*256)
      i_rd.write(1);
     else
      i_rd.write(0);
     i_addr.write(count);
     output_valid.write(0);
     if(count)
     {
        image[(count-1)/256+1][(count-1)%256+1]=Pixel.read(); 
     }
    count++;
  }
  else
  {
    if(mid<256*256)
    {
      sum=0;
      i_rd.write(0);
      for(int i=0;i<9;i++)
        sum+=image[mid/256+i/3][mid%256+i%3]*kernal[i];
      mid++;
      output_valid.write(1);
      if(sum>=128)
        result.write(255);
      else
        result.write(0);
    }
    else
      output_valid.write(0);
  }
}
// ^^^^^ put your code here ^^^^^
