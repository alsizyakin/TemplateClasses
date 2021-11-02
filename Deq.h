#if !defined DEQUE
#define DEQUE

#include <exception>
#include <vector>

template<teypename T>
class Deque{

private:

vector<T> front;
vector<T> back;

public:
bool Empty() const{

};

size_t Size() const{

};

T& operator[](size_t index) {

};

const T& operator[](size_t index) const{

};

T& At(size_t index){

};


const T& At(size_t index) const{

};

void PushFront(T font_el){

};

void PushBack(T back_el){

};

}


#endif