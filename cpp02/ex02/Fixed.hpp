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

        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);


        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);


        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);


        static const Fixed& max(const Fixed& other, const Fixed& other2);
        static Fixed& max(Fixed& other, Fixed& other2);

        static const Fixed& min(const Fixed& other, const Fixed& other2);
        static Fixed& min(Fixed& other, Fixed& other2);



        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        ~Fixed();
};
