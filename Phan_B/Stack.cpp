#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> stack;

public:
    //Them mot phan tu vao ngan xep
    void push(T value)
    {
        stack.push_back(value);
    }

    //Loai bo phan tu tren cung
    void pop()
    {
        if (!stack.empty())
            stack.pop_back();
    }

    //Tra ve phan tu tren cung
    T top()
    {
        if (!stack.empty())
            return stack.back();
        return T(); //Tra ve gia tri mac dinh neu ngan xep rong
    }

    //Kiem tra xem Stack co dang rong khong
    bool empty()
    {
        return stack.empty();
    }
};

