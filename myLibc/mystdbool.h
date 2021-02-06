/**************
 * mystdbool.h*
 **************/

/*C99 in poi*/
#if __STDC_VERSION__ >= 199901L
#	ifndef _MYSTDBOOL_H
#		define _MYSTDBOOL_H
#		ifndef _STDINT_H_
#               	define _STDINT_H_
#			include <stdint.h>
#		endif		
#		define _myBool int8_t 
		typedef _myBool mybool;
#		define TRUE	1
#		define FALSE	0
#	endif
#endif

/*C90*/
#if __STDC_VERSION__ >= 199409L
#	ifndef _MYSTDBOOL_H
#		define _MYSTDBOOL_H
		typedef enum{TRUE,FALSE}mybool;
#	endif
#endif

/*C89*/
#if __STDC_VERSION__ < 199409L
#	ifndef _MYSTDBOOL_H
#		define _MYSTDBOOL_H
		typedef int mybool;
#		define TRUE  1
#		define FALSE 0
#	endif
#endif
