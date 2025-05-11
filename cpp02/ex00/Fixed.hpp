#include <iostream>


class Fixed
{
    private:
        int _fixed_num;
        static const int _fractional_bits;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        ~Fixed();
};
