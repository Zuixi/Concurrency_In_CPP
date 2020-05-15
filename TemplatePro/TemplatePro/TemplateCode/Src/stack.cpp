
#include "../Include/stack.h"

using namespace ClassTemplate;

template<class T>
void Stack<T>::push(T const& elem)
{
    elements.push_back(elem);
}

template<class T>
void Stack<T>::pop()
{
    assert(!elements.empty());
    elements.pop_back();    // remove last element
}

template<class T>
T const& Stack<T>::top() const
{
    assert(!elements.empty());
    return elements.back();
}