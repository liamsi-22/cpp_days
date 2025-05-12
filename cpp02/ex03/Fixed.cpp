#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional_bits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& f){
    os << f.toFloat();
    return (os);
}

Fixed::Fixed(): _fixed_num(0){}

Fixed::Fixed(const int num): _fixed_num(num << _fractional_bits){}

Fixed::Fixed(const float floating_num): _fixed_num(roundf(floating_num * (1 <<_fractional_bits))){}

Fixed::Fixed(const Fixed& other): _fixed_num(other._fixed_num){}

Fixed& Fixed::operator=(const Fixed& other){
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

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed fixed;
    fixed.setRawBits(_fixed_num + other.getRawBits());
    return (fixed);
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed fixed;
    fixed.setRawBits(_fixed_num - other.getRawBits());
    return (fixed);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed fixed;
    long long result = (_fixed_num * other.getRawBits());
    result >>= _fractional_bits;
    fixed.setRawBits((int)result);
    return (fixed);
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed fixed;
    long long result = (long long)_fixed_num << _fractional_bits;
    result /=  other.getRawBits();
    fixed.setRawBits((int)result);
    return (fixed);
}

Fixed Fixed::abs() const {
    return (this->toFloat() < 0) ? Fixed(-this->toFloat()) : *this;
}

Fixed& Fixed::operator++(){
    _fixed_num++;
    return (*this);
}

Fixed& Fixed::operator--(){
    _fixed_num--;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    _fixed_num++;
    return (tmp);
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    _fixed_num--;
    return (tmp);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}


const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

float Fixed::toFloat( void ) const{
    return ((float)_fixed_num / (1 <<_fractional_bits));
}

int Fixed::toInt( void ) const{
    return (_fixed_num >> _fractional_bits);
}

int Fixed::getRawBits( void )const{
    return (_fixed_num);
}

void Fixed::setRawBits( int const raw ){
    _fixed_num = raw;
}

Fixed::~Fixed(){}