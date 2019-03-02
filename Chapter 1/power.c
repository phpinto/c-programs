#include <stdio.h>
#define YES 1
#define NO 0
#define MAXNUMLENGTH 100

double toDouble(char * s, int length) {
    int i, x, stage;
    double result, result2, divCount;
    
    i = stage = 0;
    x = 1;
	result = result2 = 0.0;
	divCount = 1.0;

    if (s[0] == '-') {
        i = 1;
        x = -1;
    }
    
    for (i; i < length; i++) {
        if ((s[i] != '.') && stage == 0) 
            result = (result*10) + (s[i]-'0');
        else if (s[i] == '.')
            stage = 1;
        else if (stage == 1) {
            result2 = (result2) + ((s[i]-'0')/(10.0*divCount));
            divCount = divCount*10;
        }
    }

    return ((result + result2) * x);
}

int toInt(char * s, int length) {
    int result, i, x;

    i = result = 0;
    x = 1;

    if (s[0] == '-') {
        i = 1;
        x = -1;
    }

    for (i; i < length; i++) {
        if (s[i] == '.')
            return (result * x);
        if ((s[i] >= '0') && (s[i] <= '9')) 
            result = (result*10) + (s[i]-'0');
    }

    return (result * x);
}

double toDoubleTruncate(char * s, int length) {
    double result;
    int i, x;

    i = 0;
    x = 1;

    if (s[0] == '-') {
        i = 1;
        x = -1;
    }

    result = 0.0;

    for (i; i < length; i++) {
        if (s[i] == '.')
            return (result * x);
        if ((s[i] >= '0') && (s[i] <= '9')) 
            result = (result*10.0) + (s[i]-'0');
    }

    return (result * x);
}

double power(double x, int n) {
    int i;
    double result;

    result = x;

    if (n == 0 && x != 0)
        return 1;
    else if (x == 0 && n != 0)
        return 0;
    else if (n > 0) {
        for (i = 1; i < n; i++) 
            result = result * x;
    }
    else {
        for (i = 1; i < (n * -1); i++) 
            result = result * x;
        result = 1/result;
    }    
    
    return result;
}

int main()
{
    int inNumber, i, counter, c, rhs;
    double lhs, result;
    char array[MAXNUMLENGTH];

    inNumber = NO;
    counter = rhs = 0;
    lhs =  0.0;

    for (i = 0; i < MAXNUMLENGTH; i++)
        array[i] = ' ';

    while((c = getchar()) != EOF)
        if (inNumber == NO && c == '-') {
            inNumber = YES;
            array[counter] = c;
            ++counter;
        }
        else if ((c >= '0' && c <= '9') || (c == '.')) {
            inNumber = YES;
            array[counter] = c;
            ++counter;
        }
        else if (c == '^') {

            lhs = toDouble(array, counter);
            counter = 0;
            inNumber = NO;
        }
        else if (c == '\n') {
            rhs = toInt(array,counter);
            result = power(lhs,rhs);
            printf("%f\n",result);
            counter = 0;
            inNumber = NO;
        }

    return 0;
}

