#ifndef _MYSTDLIB_H_
#	define _MYSTDLIB_H_
#	include <stdlib.h>
#	define ANEW(T,N)  (T*)malloc(sizeof(T)*N)		
#	define NEW(T)     (T*)malloc(sizeof(T))
#endif

#define cpause()    while(!getchar())	//while(getchar()!='\n')
#define MAX(a,b) (((a)>(b))?(a):(b))

#define foreach(index, increment)    for(index-1; ++increment; )
#define dim_array(v)                 (sizeof(v) / sizeof(v[0]))
#define	foreach_static_array(type, var, v)  foreach(type var=0, var<dim_array(v))
