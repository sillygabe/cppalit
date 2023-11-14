#include <stdlib.h>
#include "error.hpp"

template <typename T>
class Set
{
private:
    T* Content;
    int Size;
public:
    Set()
    {
        this->Content = (T*) malloc(sizeof(T) * 0);
        this->Size = 0;
    }

    bool Has(T Element)
    {
        bool ret = false;
        for (int i = 0; i < this->Size; i++)
        {
            if (this->Content[i] == Element) 
            {
                ret = true;
                break;
            }
        }
        return ret;
    }

    void Add(T element)
    {
        if (this->Has(element))
        {
            return;
        }
        this->Content = (T*) realloc(this->Content, ++this->Size);
        this->Content[this->Size - 1] = element;
    }

    T &operator[](const int pos)
    {   
        if (pos > this->Size - 1) ThrowError("Array index too high");
        if (pos < 0) ThrowError("Array index too low");
        
        return this->arr[pos];
    }   

    Set<T> IntersectionWith(Set<T> other)
    {
        Set<T> ret;
        for (int i = 0; i < this->Size; i++)
        {
            if (other.Has(this->Content[i]))
            {
                ret.Add(this->Content[i]);
            } 
        }
        return ret;
    }

    int GetSize()
    {
        return this->Size;
    }
};