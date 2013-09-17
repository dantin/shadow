#ifndef __UTMPLIB_H__
#define __UTMPLIB_H__

#include <utmp.h>

int utmp_open( char *filename );
struct utmp *utmp_next( void );
int utmp_reload( void );

#endif
