#include<stdio.h>

struct  str1
{
    int i;
    char c;
};

int main()
{
    struct str1 var1 = {100,'A'};
    printf("Structure 1 contents: i=%d, c=%c", var1.i,var1.c);
}
