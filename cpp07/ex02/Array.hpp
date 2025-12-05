
#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T> &other);
        Array<T> &operator=(const Array<T> &other);
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;
        ~Array();
};

template <typename T>
Array<T>::Array(): array(0), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n): _size(n){
    array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other){
    array = new T[other._size]();
    _size = other._size;
    for (unsigned int i = 0; i < _size; ++i)
        array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this != &other)
    {
        if (array)
            delete[] array;
        array = new T[other._size]();
        for (unsigned int i = 0; i < other._size; ++i)
            array[i] = other.array[i];
        _size = other._size;
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index){
        if (index >= this->_size)
            throw std::out_of_range("Index out of range");
        return (array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
        if (index >= this->_size)
            throw std::out_of_range("Index out of range");
        return (array[index]);
}

template <typename T>
unsigned int Array<T>::size() const{
    return (this->_size);
}

template <typename T>
Array<T>::~Array(){
    delete[] array;
}