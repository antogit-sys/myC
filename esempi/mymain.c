#include "../myLibc/mystdio.h"
int main(void)
{
	int *p=MYNULL;
	p=NEW(int);
	
	*p=2;
	myprintf("%d",*p);
	myputchar('\n');
	
	printf("press the key...");
	pause();
	int *array=ANEW(int,10);
	for(size_t i=0;i<10;++i){
		*(array+i)=i;
		myprintf("%d",array[i]);
	}
		
return 0;
}
