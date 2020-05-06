#include <stdio.h>

int main()
{
    long nc;
    int c, blanks, tabs, new_lines;

    new_lines = 0;
    tabs = 0;
    blanks = 0;

    nc = 0;

    while (getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);
    

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++new_lines;
        else if (c == '\t')
            ++tabs;
        else if (c == ' ')
            ++blanks;
    }

    printf("New Lines; %d, Tabs: %d, Blanks: %d\n", new_lines,tabs,blanks);     


    return 0;
}