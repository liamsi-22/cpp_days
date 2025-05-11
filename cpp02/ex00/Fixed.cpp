#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(): _fixed_num(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    _fixed_num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &other)
        _fixed_num = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void )const{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixed_num);
}

void Fixed::setRawBits( int const raw ){
    _fixed_num = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}