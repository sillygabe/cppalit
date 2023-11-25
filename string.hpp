#include <stdlib.h>
#include <string.h>
#include "error.hpp"

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
        int length = snprintf(NULL, 0, "%d", num);         
        char* str = (char *) malloc(length + 1);

        snprintf(str, length + 1, "%d", num); 

        this->content = str;
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

    void Replace(const char* ToReplace, const char* ReplaceStr, int Times = -1)
    {

        if (Times < -1)
        {
            return;
        }

        char* NewString = (char*)malloc(strlen(this->content) * sizeof(char));
        char* Save = this->content;
        int pos;

        while (Times != 0 && (pos = strstr(Save, ToReplace) - Save) >= 0)
        {
            strncat(NewString, Save, pos);
            strcat(NewString, ReplaceStr);
            Save += pos + strlen(ToReplace);
            Times--;
        }

        strcat(NewString, Save);
        this->content = NewString;
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