#include <stdlib.h>
#include <string.h>
#include "error.hpp"

class String
{
private:
    char * Content = (char *) malloc(0 * sizeof(char));
public:

    int GetSize()
    {
        return strlen(this->Content);
    }

    char * GetCString()
    {
        return this->Content;
    }

    String(char From)
    {
        this->Content = (char *) malloc(1 * sizeof(char));
        this->Content[0] = From;
    }

    String()
    {
        this->Content = (char *) "";
    }

    String(const char * FromCString)
    {
        this->Content = (char *) FromCString;
    }

    String operator+(String other)
    {
        char * buffer = (char *) malloc(this->GetSize() + other.GetSize());
        buffer = strcat(this->Content, other.Content);
        return (String) buffer;
    }

    void operator+=(String other)
    {
        char * buffer = (char *) malloc(this->GetSize() + other.GetSize());
        buffer = strcat(this->Content, other.Content);
        this->Content = buffer;
    }

    char &operator[](int pos)
    {
        if (pos > this->GetSize() - 1) ThrowError("Array index too high");
        if (pos < 0) ThrowError("Array index too low");

        return this->Content[pos];
    }

    bool operator==(String other)
    {
        return (!strcmp(this->Content, other.Content));
    }
    
    bool operator!=(String other)
    {
        return !(this->operator==(other));
    }

    int Count(String ToCount) {
        Assert(ToCount != "");
        int count = 0;
        const char* ptr = this->Content;

        while ((ptr = strstr(ptr, ToCount.GetCString())) != NULL) {
            count++;
            ptr += ToCount.GetSize();
        }

        return count;
    }

    void Reverse()
    {
        int a = 0, b = this->GetSize() - 1; char buff;

        while (a < this->GetSize() / 2)
        {
            buff = this->Content[a];
            this->Content[a] = this->Content[b];
            this->Content[b] = buff;
            a++; b--;
        }
    }

    void Replace(String ToReplace, String Replacement, int Times = -1)
    {
        if (Times < -1 || Times > this->GetSize())
        {
            ThrowError("Size is too low/high");
        }

        char* NewString = (char*) malloc(strlen(this->Content) * sizeof(char));
        char* Save = this->Content;
        int pos;

        while ((Times > 0 || Times < 0) && (pos = strstr(Save, ToReplace.GetCString()) - Save) >= 0)
        {
            strncat(NewString, Save, pos);
            strcat(NewString, Replacement.GetCString());
            Save += pos + strlen(Replacement.GetCString());
            Times--;
        }

        strcat(NewString, Save);
        this->Content = NewString;
    }
};  