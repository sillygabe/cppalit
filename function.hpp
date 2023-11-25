#include "error.hpp"

template <typename ReturnType, class... Args>
class Function
{
private:
    ReturnType (*func) (Args...);
    bool assigned = false;
public:

    Function()
    {
        this->assigned = false;
        this->func = nullptr;
    }

    Function(ReturnType (*newfunc) (Args...))
    {
        this->assigned = true;
        this->func = newfunc;
    }

    ReturnType Execute(Args... args)
    {
        if (!this->assigned) ThrowError("Function not assigned");
        return this->func(args...);
    }
};
