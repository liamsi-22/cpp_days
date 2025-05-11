#include <iostream>
#include <exception>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;

    public:
        Array():_array(NULL), _size(0){};

        Array(size_t  n):_array(new T[n]()), _size(n){};

        Array(const Array& other){
            _size =other._size;
            _array = new T[_size]();
            for (size_t i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        }

        Array& operator=(const Array& other){
            if (this != &other)
            {
                delete[] _array;
                _size =other._size;
                _array = new T[_size]();
                for (size_t i = 0; i < _size; ++i)
                    _array[i] = other._array[i];
            }
            return (*this);
        }

        T& operator[](size_t index){
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return (_array[index]);
        }

        size_t size() const{
            return (_size);
        }

        ~Array(){
            delete[] _array;
        }
};


