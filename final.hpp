#include <stdio.h>
#include "array.hpp"
#include "colors.hpp"
#include "set.hpp"
#include "hashmap.hpp"
#include "string.hpp"
#include "function.hpp"
#include "defs.hpp"

String Input(const char * InputText = "")
{
    printf("%s", InputText);
    char * inp = (char *) malloc(sizeof(char) * 40);
    scanf("%s", inp);
    return inp;
}

void PrintLine(String ToPrint)
{
    printf("%s\n", ToPrint.GetChars());
}

template <typename T>
void PrintArray(Array<T> arr, String Sep = " ")
{
    for (T elem : arr)
    {
        Print(elem, Sep);
    }
}

template <typename T>
void Swap(T &Element1, T &Element2)
{
    T buff = Element1;
    Element1 = Element2;
    Element2 = buff;
}

/*
Array<String> SplitString(String ToSplit, String Sep)
{

}
*/