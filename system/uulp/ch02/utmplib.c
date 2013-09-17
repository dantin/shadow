#include <utmp.h>

#define NRECS 16
#define NULLUT ( ( struct utmp * ) NULL )
#define UTSIZE ( sizeof( struct utmp ) )

static char utmpbuf[ NRECS * UTSIZE ];
