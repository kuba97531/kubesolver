#include <stdio.h>
#include <stdarg.h>
int print_info = 1;

void disable_info_messages(void) {
    print_info = 0;
}
void info(char* format, ...)
{
   printf("INFO:");
   va_list arglist;
   va_start( arglist, format );
   vprintf( format, arglist );
   va_end( arglist );
   printf("\n");
}