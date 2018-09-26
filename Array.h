#ifndef INC_05_DYNAMIC_ARRAY_CLASS_ARRAY_H
#define INC_05_DYNAMIC_ARRAY_CLASS_ARRAY_H

#include <exception>



template<typename T> class Array {
    T* arr = nullptr;
    size_t len=0;
    size_t _capacity=0;

    const static size_t BUFFER_SIZE;

public:
    size_t size() const;
    size_t capacity() const;

private:
    void increment_size();

public:
    T& operator[](size_t) const;
    void push_back(const T&);

    ~Array();
};



template<typename T> T &Array<T>::operator[](size_t index) const{
    if(index>=len) throw std::exception();
    return arr[index];
}

template<typename T> void Array<T>::push_back(const T &v) {
    increment_size();
    arr[len] = v;
    len++;
}

template<typename T> void Array<T>::increment_size() {
    if(_capacity-len != 0) return;
    _capacity+= BUFFER_SIZE;
    T* old = arr;
    arr = new T[_capacity];
    memcpy(arr,old,len* sizeof(T));
    delete[] old;
}

template<typename T> Array<T>::~Array() {
    delete[] arr;
}

template<typename T> size_t Array<T>::size() const {
    return len;
}

template<typename T> size_t Array<T>::capacity() const {
    return _capacity;
}

template<typename T> const size_t Array<T>::BUFFER_SIZE=4;

#endif //INC_05_DYNAMIC_ARRAY_CLASS_ARRAY_H
