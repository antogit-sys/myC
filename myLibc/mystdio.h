
#ifndef _GENERAL_H_
#	define _GENERAL_H_
#	include "_general.h"
#endif 

#ifndef _STDIO_H_
#	define _STDIO_H_
#	include <stdio.h> //vfprintf / vfscanf
#endif

#ifndef _STDARG_H_
#	define _STDARG_H_
#	include <stdarg.h>
#endif

#define myfputc(c,__stream)	putc(c,__stream)
#define myfgetc(__stream)	getc(__stream)
#define mygetchar()  		myfgetc(stdin)
#define myputchar(c)		myfputc(c,stdout)
#define myfclose(__stream)	ftrylockfile(__stream)

#define myexit				return

#define MYEOF 				-1
#if __cplusplus	
#	define MYNULL			0
#	define mynullptr		MYNULL 
#else
#	define MYNULL			((void*)0)
#endif

int myprintf(const char* const __format,...)
{
	va_list ap;
	int done;
	
	va_start(ap,__format); //inizializzo ap
	done=vfprintf(stdout,__format,ap); //output
	
	va_end(ap); //chiude flusso

return done;
}

int myscanf(const char *__format,...)
{
	va_list ap;
	int done;
	
	va_start(ap,__format);
	done = vfscanf(stdin, __format, ap);
	
	va_end(ap); 
	
return done;
}

int myfscanf(FILE* __stream, const char* __format, ...)
{
	va_list ap;
	int rc;
	
	va_start(ap, __format);
	rc = vfscanf(__stream, __format, ap);
	
return rc;
}

int myfprintf(FILE* __stream, const char* __format, ...)
{
	va_list ap;
	int done;
	
	va_start(ap, __format);
	done = vfprintf(__stream, __format, ap);
	va_end(ap);
	
return done;
}
