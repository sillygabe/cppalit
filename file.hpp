#include <cstdlib>
#include <stdio.h>

class File
{
private:
    FILE* ReadFile;
    FILE* WriteFile;
    bool Initialised = false;
public:
    File(char * ToOpen)
    {
        this->WriteFile = fopen(
            (const char *) ToOpen,
            "w"
        );
        this->ReadFile = fopen(
            (const char *) ToOpen,
            "r"
        );
        this->Initialised = true;
    }

    File(const char * ToOpen)
    {
        this->WriteFile = fopen(
            ToOpen,
            "w"
        );
        this->ReadFile = fopen(
            ToOpen,
            "r"
        );
        this->Initialised = true;
    }

    char * Read()
    {
        if (this->Initialised)
        {
            char * Buffer = (char *) malloc(20);
            fscanf(this->ReadFile, "%s", Buffer);
            return Buffer;
        } else {
            return (char *) "";
        }
    }

    void Write(char * ToWrite)
    {
        if (this->Initialised)
        {
            fprintf(this->WriteFile, "%s", ToWrite);
        }
    }

    void Close()
    {
        fclose(this->ReadFile);
        fclose(this->WriteFile);
        this->Initialised = false;
    }

};

//Just a wrapper for easier to understand code
File Open(const char * ToOpen)
{
    return File(ToOpen);
}