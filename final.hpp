#include <stdio.h>
#include <stdlib.h>
#include "array.hpp"
#include "string.hpp"
#include "colors.h"
#include "set.hpp"
#include "dictionary.hpp"

char * Input(const char * InputText = "")
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

void PrintLine(String ToPrint)
{
    printf("%s\n", ToPrint.GetCString());
}

template <typename T>
void Swap(T &Element1, T &Element2)
{
    T buff = Element1;
    Element1 = Element2;
    Element2 = buff;
}