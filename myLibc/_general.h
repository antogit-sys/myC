#ifndef _MYSTDLIB_H_
#	define _MYSTDLIB_H_
#	include <stdlib.h>
#	define ANEW(T,N) 		(T*)malloc(sizeof(T)*N)		
#	define NEW(T)			(T*)malloc(sizeof(T))
#endif

#define cpause()	while(!getchar())	//while(getchar()!='\n')
