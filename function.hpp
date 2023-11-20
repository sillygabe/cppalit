template <typename ReturnType, class... Args>
class Function
{
private:
    ReturnType (*func) (Args...);
public:
    Function(ReturnType (*newfunc) (Args...))
    {
        this->func = newfunc;
    }
    ReturnType Execute(Args... args)
    {
        return this->func(args...);
    }
};

#define Func Function
#define Def Function