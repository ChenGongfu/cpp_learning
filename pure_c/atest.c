#include <stdio.h>
#include "message.c"

#undef MESSAGE

#ifndef MESSAGE
   #define MESSAGE "Hello, World! from atest.c"
#endif

#ifdef DEBUG
    printf("DEBUG");
#endif

int main()
{   
    printf("Message :%s\n", MESSAGE );
    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    return 0;
}


