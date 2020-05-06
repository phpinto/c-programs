#include <stdio.h>
#define TABLENGTH 4
#define YES 1
#define NO 0

int main()
{
    int c, spaceCount, inBlank, numTabs, numSpaces;
    spaceCount = 0;
    inBlank = NO;
    
    while((c = getchar()) != EOF)
        if (c == ' ' && inBlank == NO) {
            spaceCount = 1;
            inBlank = YES;
        }
        else if (c == ' ' && inBlank == YES) {
            ++spaceCount;
        }
        else  if (c != ' ' && inBlank == YES){
            numTabs = spaceCount / TABLENGTH;
            numSpaces = spaceCount % TABLENGTH;
            for (int i = 0; i < numTabs; i++) {
                putchar('\t');
            }
            for (int i = 0; i < numSpaces; i++) {
                putchar('#');
            }
            putchar(c);
            spaceCount = 0;
            inBlank = 0;
        }
        else putchar(c);

    return 0;
}

