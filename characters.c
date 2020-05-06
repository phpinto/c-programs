#include <stdio.h>

int main()
{
   int c;
   int blankCount;
   
   blankCount = 0;

   while((c = getchar()) != EOF) {
       if (c == ' ') {
           if (blankCount == 0) 
               putchar(c);
           ++blankCount;
       }
       else {
           putchar(c);
           blankCount = 0;
       }
   }

   while((c = getchar()) != EOF) {
       if (c == '\t') {
           putchar('>');
           putchar('\b');
           putchar('-');
       }
       else if (c == '\b') {
           putchar('<');
           putchar('\b');
           putchar('-');
       }
       else
            putchar(c);
   }

   return 0;
}