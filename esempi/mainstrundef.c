#include <stdio.h>
#include "../myLibc/strundef.h"

int main(void)
{
	
	String strout=new_init();
	String strin=new_init();
	
	str_input(strout);
	puts(strout);
	
	str_fout(strout,"fileC.txt");
	str_fin(strin,"fileC.txt");
	
	printf("in: %s",strin);
	
return 0;
}

