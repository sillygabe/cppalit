#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "error.hpp"

char * EvalDigit(int num)
{
    char * ret;
    switch (num % 10)
    {
    case 0: ret = (char *)"0"; break;
    case 1: ret = (char *)"1"; break;
    case 2: ret = (char *)"2"; break;
    case 3: ret = (char *)"3"; break;
    case 4: ret = (char *)"4"; break;
    case 5: ret = (char *)"5"; break;
    case 6: ret = (char *)"6"; break;
    case 7: ret = (char *)"7"; break;
    case 8: ret = (char *)"8"; break;
    case 9: ret = (char *)"9"; break;
    default: ThrowError("wtf man did you invent a new digit or what"); break;
    }
    return ret;
}

class String
{
private:
    char * content;
public:

    char * GetChars()
    {
        return this->content;
    }

    int GetSize()
    {
        return strlen(this->content);
    }

    String()
    {
        this->content = (char *) malloc(0);
    }

    String(char input)
    {
        this->content = (char *) malloc(2);
        this->content[0] = input; this->content[1] = '\0';
    }

    String(const char * input)
    {
        this->content = (char *) malloc(strlen(input) + 1);
        this->content = strcpy(this->content, (char *) input);
    }

    String(int num)
    {
        this->content = (char *) malloc(0);
        while (num != 0)
        {
            this->operator+=(EvalDigit(num));
            num /= 10;
        }
        this->Reverse();
    }

    String operator+(String other)
    {
        return strcat(this->content, other);
    }

    void operator+=(String other)
    {
        this->content = strcat(this->content, other);
    }

    char &operator[](const int pos)
    {   
        if (pos > this->GetSize() - 1) ThrowError("Array index too high");
        if (pos < 0) ThrowError("Array index too low");
        
        return this->content[pos];
    }   

    operator char*()
    {
        return this->content;
    }

    operator const char*()
    {
        return (const char *) this->content;
    }

    bool operator==(String other)
    {
        return (!strcmp(this->content, other.content));
    }

    bool operator!=(String other)
    {
        return (strcmp(this->content, other.content));
    }

    void Reverse()
    {
        int a = 0, b = this->GetSize() - 1; char buff;
        while (a < this->GetSize() / 2)
        {
            buff = this->operator[](a);
            this->content[a] = this->content[b];
            this->content[b] = buff;
            a++; b--;
        }
    }

    char * begin()
    {
        return &(this->content[0]);
    }

    char * end()
    {
        return &(this->content[this->GetSize()]);
    }

    int Count(String substring) {
        Assert(substring != String(""), "Cannot count \"\" in a string");
        int count = 0;
        const char* ptr = this->content;

        while ((ptr = strstr(ptr, substring)) != NULL) {
            count++;
            ptr += strlen(substring);
        }

        return count;
    }
};

/*
String Format(String ToFormat, ...)
{
    va_list args; va_start(args, ToFormat);

}
*/