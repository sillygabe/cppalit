#include <stdlib.h>
#include "error.hpp"
#include <string.h>

class Hash
{
private:
    int value = 0;
public:

    Hash()
    {
        this->value = 0;
    }

    Hash(int value)
    {
        this->value = value;
    }

    Hash(int values[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            this->value += values[i];
        }
    }

    Hash(const char * values)
    {
        for (int i = 0; i < strlen(values); i++)
        {
            this->value += (int) values[i];
        }
    }   

    int GetValue()
    {
        return this->value;
    }

    operator int()
    {
        return this->value;
    }
};

template <typename T, typename P>
class HashMap
{
private:
    int size;
    int * keys;
    P * elements;
public:

    template <typename R>
    static Hash GetHash(R key)
    {
        Hash elem;
        try
        {
            elem = (Hash) key;
        }
        catch(...)
        {
            elem = 0;
            ThrowError("No hash method converter found for the class");
        }
        return elem;
    }

    HashMap()
    {
        this->size = 0;
        this->keys = (int *) malloc(0);
        this->elements = (P *) malloc(0);
    }

    bool HasKey(T key)
    {
        Hash elem = HashMap::GetHash(key);
        for (int i = 0; i < this->size; i++)
        {
            if (elem.GetValue() == this->keys[i])
            {
                return true;
            }
        }
        return false;
    }

    void Update(T key, P value)
    {
        Assert(!this->HasKey(key), "Key already in the hashmap");
        this->keys = (int*) realloc(this->keys, ++this->size);
        this->elements = (P*) realloc(this->elements, this->size);
        this->keys[this->size - 1] = Hash(key).GetValue();
        this->elements[this->size - 1] = value;
    }

    P& operator[](const T key)
    {
        const int ConKey = Hash(key).GetValue();
        for (int i = 0; i < this->size; i++)
        {
            if (ConKey == this->keys[i])
            {
                return this->elements[i];
            }
        }
        ThrowError("Wrong key");
        return this->elements[0];
    }

    P& operator[](const int hashpos)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (hashpos == this->keys[i])
            {
                return this->elements[i];
            }
        }
        ThrowError("Wrong key");
        return this->elements[0];
    }

    int GetSize()
    {
        return this->size;
    }

    int * begin()
    {
        return &(this->keys[0]);
    }

    int * end()
    {
        return &(this->keys[size]);
    }
};

#define Dict HashMap
#define Dictionary HashMap
#define Table HashMap