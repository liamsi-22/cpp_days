#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional_bits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& f){
    os << f.toFloat();
    return (os);
}

Fixed::Fixed(): _fixed_num(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){
	std::cout << "Int constructor called" << std::endl;
    _fixed_num = num << _fractional_bits;
}

Fixed::Fixed(const float floating_num){
	std::cout << "Float constructor called" << std::endl;
    _fixed_num = roundf(floating_num * (1 <<_fractional_bits));
}

Fixed::Fixed(const Fixed& other){
    std::cout << "Copy constructor called" << std::endl;
    _fixed_num = other._fixed_num;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called " << std::endl;
    if (this != &other)
        _fixed_num = other._fixed_num;
    return (*this);
}

float Fixed::toFloat( void ) const{
    return ((float)_fixed_num / (1 <<_fractional_bits));
}

int Fixed::toInt( void ) const{
    return (_fixed_num >> _fractional_bits);
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