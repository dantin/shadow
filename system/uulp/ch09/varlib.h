#ifndef __VARLIB_H__

#define __VARLIB_H__

int VLenviron2table( char ** );
int VLexport( char * );
char *VLlookup( char * );
void VLlist( void );
int VLstore( char *, char * );
char **VLtable2environ( void );
int VLenviron2table( char ** );

#endif
