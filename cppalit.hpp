#include <stdio.h>
#include "array.hpp"
#include "colors.hpp"
#include "set.hpp"
#include "hashmap.hpp"
#include "string.hpp"
#include "function.hpp"
#include "defs.hpp"
#include "file.hpp"

String Input(const char * InputText = "")
{
    printf("%s", InputText);
    char * inp = (char *) malloc(sizeof(char) * 40);
    scanf("%s", inp);
    return inp;
}

void Print(String ToPrint, String Sep = "\n")
{
    printf("%s", (ToPrint + Sep).GetChars());
}

template <typename T>
void PrintArray(Array<T> arr, String Sep = " ")
{
    for (auto elem : arr)
    {
        Print((String) elem, Sep);
    }
}

template <typename T>
void Swap(T &Element1, T &Element2)
{
    T buff = Element1;
    Element1 = Element2;
    Element2 = buff;
}