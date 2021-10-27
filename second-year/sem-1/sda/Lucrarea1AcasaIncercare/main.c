#include <stdio.h>
#include <stdlib.h>
#include  "timer.h"

void functie_test()
{
int i,j,k; 
for(i=1;i<=200000;i++) 
	for(j=1;j<=20000;j++) 
		if(i%2)k=i; 
}






void main(void)
{ float timp;
FILE *f = fopen("fisier.txt","w");
//generate_a();
starton(); 
functie_test();
timp=startoff(); 
printf("%f",timp);
fprintf(f,"%f",timp);
fclose(f);
} 