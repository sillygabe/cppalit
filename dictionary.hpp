#include <stdlib.h>
#include "error.hpp"

template <typename T, typename P>
class Dictionary
{
private:
    size_t size;
    T* keys;
    P* values;
public:
    Dictionary()
    {
        this->keys = (T*) malloc(0 * sizeof(T));
        this->values = (P*) malloc(0 * sizeof(P));
        this->size = 0;
    }

    void Update(T key, P element)
    {
        this->keys = (T*) realloc(this->keys, ++this->size);
        this->keys[this->size - 1] = key;

        this->values = (P*) realloc(this->values, this->size);
        this->values[this->size - 1] = element;
    }   

    P &operator[](const T pos)
    {
        int index = -1;
        T n = (T) pos;
        for (int i = 0; i < this->GetSize(); i++)
        {
            if (this->keys[i] == n)
            {
                index = i;
                break;
            }
        }
        if (index != -1) return this->values[index];
        else 
        {
            ThrowError("Wrong key value");
            return this->values[0];
        }
    }

    int GetSize()
    {
        return this->size;
    }
};

#define Dict Dictionary