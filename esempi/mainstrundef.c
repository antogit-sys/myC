#include <stdio.h>
#include "../myLibc/strundef.h"

int main(void)
{
	
	String sout=new_init();
	String sin=new_init();
	
	str_input(sout);
	puts(sout);
	
	str_fout(sout,"fileC.txt");
	str_fin(sin,"fileC.txt");
	
	printf("sin: %s",sin);
	
return 0;
}

