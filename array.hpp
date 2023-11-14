#include <stdlib.h>
#include "error.hpp"

template <typename T>
class Array
{
private:
    int size;
    T* arr;
public:
    Array()
    {
        this->size = 0;
        this->arr = (T*) malloc(0 * sizeof(T));
    }

    //Convert C array to a normal array
    void SetOrigin(T arr[], int size)
    {
        this->arr = arr;
        this->size = size;
    }

    void Append(T element)
    {
        this->arr = (T*) realloc(this->arr, ++this->size);
        this->arr[this->size - 1] = element;
    }   

    T &operator[](const int pos)
    {   
        if (pos > this->size - 1) ThrowError("Array index too high");
        if (pos < 0) ThrowError("Array index too low");
        
        return this->arr[pos];
    }   

    void Reverse()
    {
        int a = 0, b = this->size - 1; T buff;

        while (a < this->size / 2)
        {
            buff = this->arr[a];
            this->arr[a] = this->arr[b];
            this->arr[b] = buff;
            a++; b--;
        }
    }

    int GetSize() {return this->size;}
};

