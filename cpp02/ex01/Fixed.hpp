#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed;

std::ostream& operator<<(std::ostream& os, const Fixed& f);

class Fixed
{
    private:
        int _fixed_num;
        static const int _fractional_bits;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float floating_num);

        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        ~Fixed();
};

#endif