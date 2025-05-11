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

Fixed::Fixed(const int num): _fixed_num(num << _fractional_bits){
    std::cout << "parameterized constructor called" << std::endl;
}

Fixed::Fixed(const float floating_num):  _fixed_num(roundf(floating_num * (1 <<_fractional_bits))){
        std::cout << "parameterized constructor called" << std::endl;
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



bool Fixed::operator>(const Fixed& other){
    return (_fixed_num > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other){
    return (_fixed_num < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other){
    return (_fixed_num >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other){
    return (_fixed_num <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other){
    return (_fixed_num == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other){
    return (_fixed_num != other.getRawBits());
}


Fixed Fixed::operator+(const Fixed& other){
    Fixed fixed;
    fixed._fixed_num = _fixed_num + other.getRawBits();
    return (fixed);
}

Fixed Fixed::operator-(const Fixed& other){
    Fixed fixed;
    fixed._fixed_num = _fixed_num - other.getRawBits();
    return (fixed);
}

// Fixed Fixed::operator*(const Fixed& other){
//     long long result = static_cast<long long>(_fixed_num) * other._fixed_num;
//     return Fixed(result >> _fractional_bits); // Shift right to scale back
// }

Fixed Fixed::operator*(const Fixed& other){
    Fixed fixed;
    long long result = ((long long)_fixed_num * other.getRawBits()) >> _fractional_bits;
    fixed.setRawBits(result);
    return (fixed);
}


//this one
Fixed Fixed::operator/(const Fixed& other){
    Fixed fixed;
    long long result = (_fixed_num << _fractional_bits) / other.getRawBits();
    fixed.setRawBits(result);
    return (fixed);
}



Fixed& Fixed::operator++(){
    _fixed_num += 1;
    return (*this);
}

Fixed& Fixed::operator--(){
    _fixed_num -= 1;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed tmp = *this;
    _fixed_num += 1;
    return (tmp);
}

Fixed Fixed::operator--(int){
    Fixed tmp = *this;
    _fixed_num -= 1;
    return (tmp);
}



const Fixed& Fixed::max(const Fixed& other, const Fixed& other2){
    if (other.getRawBits() > other2.getRawBits())
        return (other);
    else
        return (other2);
}

Fixed& Fixed::max(Fixed& other, Fixed& other2){
    if (other.getRawBits() > other2.getRawBits())
        return (other);
    else
        return (other2);
}


const Fixed& Fixed::min(const Fixed& other, const Fixed& other2){
    if (other.getRawBits() > other2.getRawBits())
        return (other);
    else
        return (other2);
}

Fixed& Fixed::min(Fixed& other, Fixed& other2){
    if (other.getRawBits() > other2.getRawBits())
        return (other);
    else
        return (other2);
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