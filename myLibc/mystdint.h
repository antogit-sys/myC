/*
 *  stdint.h
 ****************/

#ifndef _STDINT_H_
#   define _STDINT_H_
#endif

typedef char myInt8;
typedef short int myInt16;
typedef int myInt32;

#if INTPTR_MAX == INT16_MAX
	typedef unsigned short mysize_t;
#elif INTPTR_MAX == INT32_MAX
	typedef unsigned int mysize_t;
#elif INTPTR_MAX == INT64_MAX
	typedef unsigned long long mysize_t;
#endif
