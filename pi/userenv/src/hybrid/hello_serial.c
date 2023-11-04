#include <stdio.h>

int main( argc, argv )
int  argc;
char **argv;
{
    int rank, size;
    rank=0;
    size=1;
    printf( "Hello world from process %d of %d\n", rank, size );
    return 0;
}
