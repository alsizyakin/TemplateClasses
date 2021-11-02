#ifndef DEQUE
#define DEQUE

#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Deque
{

private:
    vector<T> front;
    vector<T> back;

public:
    Deque()
    {
        front = {};
        back = {};
    }

    bool Empty() const
    {
        return (front.empty() && back.empty());
    };

    size_t Size() const
    {
        return (front.size() + back.size());
    };

    T &operator[](size_t index)
    {
        if (front.empty() || index > (front.size() - 1))
        {
            return back[index - front.size()];
        }
        return front[front.size() - 1 - index];
    };

    const T &operator[](size_t index) const
    {
        if (front.empty() || index > (front.size() - 1))
        {
            return back[index - front.size()];
        }
        return front[front.size() - 1 - index];
    };

    T &At(size_t index)
    {
        if (index > (back.size() + front.size() - 1))
        {
            throw out_of_range("index is too large");
        }
        if (front.empty() || index > (front.size() - 1))
        {
            return back[index - front.size()];
        }
        return front[front.size() - 1 - index];
    };

    const T &At(size_t index) const
    {
        if (index > (back.size() + front.size() - 1))
        {
            throw out_of_range("index is too large");
        }
        if (front.empty() || index > (front.size() - 1))
        {
            return back[index - front.size()];
        }
        return front[front.size() - 1 - index];
    };

    T &Front()
    {
        if (front.empty())
        {
            return back[0];
        }
        return front.back();
    }

    const T &Front() const
    {
        if (front.empty())
        {
            return back[0];
        }
        return front.back();
    }

    T &Back()
    {
        if (back.empty())
        {
            return front[0];
        }
        return back.back();
    }

    const T &Back() const
    {
        if (back.empty())
        {
            return front[0];
        }
        return back.back();
    }

    void PushFront(T front_el)
    {
        front.push_back(front_el);
    };

    void PushBack(T back_el)
    {
        back.push_back(back_el);
    };
};

#endif
