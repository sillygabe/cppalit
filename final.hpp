#include <stdio.h>
#include <stdlib.h>
#include "array.hpp"
#include "colors.h"
#include "set.hpp"
#include "dictionary.hpp"
#include "string.hpp"

String Input(const char * InputText = "")
{
    printf("%s", InputText);
    char * inp = (char *) malloc(sizeof(char) * 40);
    scanf("%s", inp);
    return inp;
}

void PrintLine(const char * ToPrint)
{
    printf("%s\n", ToPrint);
}

template <typename T>
void Swap(T &Element1, T &Element2)
{
    T buff = Element1;
    Element1 = Element2;
    Element2 = buff;
}