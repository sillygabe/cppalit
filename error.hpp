#include <stdlib.h>
#include <stdio.h>
#include "colors.h"
#pragma once

void ThrowError(const char * ErrorMessage)
{
    printf("%sERROR FOUND:%s %s\n", RED_TEXT, RESET_TEXT, ErrorMessage);
    exit(1);
}

void Assert(bool Statement)
{
    if (!Statement)
    {
        ThrowError("Assertion error");
    }
}