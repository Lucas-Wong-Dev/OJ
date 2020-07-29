#include <stdio.h>
#include <math.h>

int main()
{
   char str[80];

   sprintf(str, "Pi == %f", M_PI);
   puts(str);
   
   return(0);
}
