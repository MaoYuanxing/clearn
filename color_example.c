#include <stdio.h>
#include "primary.h"

int main(int argc, char **argv)
{
    printf("Additive primary colors are %s\n", primary_additive());
    printf("Subtractive primary colors are %s\n", primary_subtractive());
    printf("Cmyk colors are %s\n", cmyk());
    return 0;
}