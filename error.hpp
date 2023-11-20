#include <stdlib.h>
#include <stdio.h>
#include "colors.hpp"
#pragma once

void ThrowError(const char * ErrorMessage)
{
    printf("%sERROR FOUND:%s %s\n", RED_TEXT, RESET_TEXT, ErrorMessage);
    exit(1);
}

void Assert(bool Statement, const char * ErrorMessage = "Something went wrong...")
{
    if (!Statement)
    {
        printf("%sASSERTION ERROR:%s %s\n", RED_TEXT, RESET_TEXT, ErrorMessage);
        exit(1);
    }
}