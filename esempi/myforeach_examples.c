#include <stdio.h>
#include <stdlib.h>
#include "../myLibc/_general.h"
int main(void)
{
	int *v1=ANEW(int,10);
	int *v2=ANEW(int,10);
	int v3[10];
	
	/*for normale*/
	puts("for =");
	for(size_t i=0; i<10; ++i){
		v1[i]=i;
		printf("%d ",*(v1+i));	
	}
	
	/*foreach funzionante su tutto*/
	putchar('\n');
	putchar('\n');
	puts("foreach =");
	foreach(size_t i=0, i<10){
		v2[i]=i;
		printf("%d ",*(v2+i));	
	}
	
	/*foreach funzionante solo per array statici*/
	putchar('\n');
	putchar('\n');
	puts("foreach_static_array =");
	foreach_static_array(size_t,i, v3){
		v3[i]=i;
		printf("%d ",v3[i]);	
	}
		
return EXIT_SUCCESS;
}

