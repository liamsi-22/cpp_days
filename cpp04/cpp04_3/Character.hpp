#ifndef CHARACTER_HPP
#define  CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

typedef struct s_garbage{
    AMateria*   data;
    struct s_garbage* next;
} t_garbage;

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
        t_garbage* _garbageList;

    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);

        std::string const & getName() const;
        
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        ~Character();
};

#endif