#include <stdio.h>

int main (int argv, char* argc[])
{

int x = 280;

char* ptr_p = (char*) &x; printf("%d\n", * ptr_p);

return 0;
}
