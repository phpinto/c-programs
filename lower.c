#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF) {
        if(c >= 'A' && c <= 'Z')
            putchar(c + 32);
        else
            putchar(c);
   }

   return 0;
}