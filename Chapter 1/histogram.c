#include <stdio.h>
#define MAXWORDS 100
#define YES 1
#define NO 0

int main()
{
    int c, i, counter, inword, j;
    int ndigit[MAXWORDS];

    inword = NO;
    counter = 0;
    
    for (i = 0; i < MAXWORDS; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) 
        if (c == ' ' || c == '\n' || c == '\t'){
            inword = NO;
            ++counter;
        }   
        else if (inword == NO) {
            if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                inword = YES;
                ++ndigit[counter];
            }
        }
        else
            ++ndigit[counter];
    

    for (i = 0; i < counter; ++i) {
        printf("Length: ");
        for (j = 0; j < ndigit[i]; j++)
            putchar('#');
        putchar('\n');
    }

    return 0;
}