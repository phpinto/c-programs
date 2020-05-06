#include <stdio.h>
#define YES 1
#define NO 0
 
int main()
{
   int c, nl, nw, nc, inword;

   inword = NO;
   nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t'){
            inword = NO;
            putchar('\n');
        }   
        else if (inword == NO) {
            if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                ++nw;
            }
            inword = YES;
            putchar(c);
        }
        else
            putchar(c);
    }

    printf("%d %d %d\n", nl, nw, nc);

   return 0;
}