#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(std::string zombieName);
        void announce( void );
        ~Zombie();
};