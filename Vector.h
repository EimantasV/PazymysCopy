#pragma once
template <typename T> class Vector
{

public:
    typedef T *iterator;
    Vector()
    {
        arr = new T[1];
        _first = arr;
        _last = _first;
        _capacity = 1;
        current = 0;
    }
    
    T &operator[](int i) { return arr[i]; }

    void clear()
    {
        T* temp = new T[1];
        delete[] arr;
        arr = temp;

        _first = arr;
        _last = arr;
        current = 0;
        _capacity = 1;
    }

    iterator erase(iterator first, iterator last);

    void push_back(T data)
    {
        if (current == _capacity) {
            T* temp = new T[2 * _capacity];
 
            for (int i = 0; i < _capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            _capacity *= 2;
            arr = temp;
        }
 
        arr[current] = data;
        current++;
        _first = arr;
        _last = arr+current;
    }
    
    iterator begin()
    {
        return _first;
    }
    iterator end()
    {
        return _last;
    }
    void resize (int newSize)
    {
        if(newSize>=_capacity)
        {
            T* temp = new T[newSize];

            for (int i = 0; i < current; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
        }
        _first = arr;
        _last = arr + newSize;
        current = newSize;
    }
 
    T get(int index)
    {
        if (index < current)
            return arr[index];
    }
 

    int size() { return current; }
 
    int capacity() { return _capacity; }
 
private:

    T* arr;
    int _capacity;
    int current;
    iterator _first; // index 0
    iterator _last;
};

template <class T>
typename Vector<T>::iterator Vector<T>::erase(iterator first, iterator last)
{
    int i = 0;
    int temp = 0;
    auto it = (*this).begin();
    for (it; it != first; it++, i++)
        ;
    for (it = first; it != last; it++, temp++, i++)
        ;
    for (auto it = last; it != (*this).end(); it++, i++)
        arr[i - temp] = arr[i];
    current -= temp;
    _first = arr;
    _last = arr+current;
    
    return last;
}