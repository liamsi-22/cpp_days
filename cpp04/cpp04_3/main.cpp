// #include "ICharacter.hpp"
#include "Character.hpp"

// #include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

// #include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}





// #include <iostream>
// #include "Character.hpp"
// #include "Cure.hpp"
// #include "Ice.hpp"
// #include "MateriaSource.hpp"

// int main()
// {
//     // Test MateriaSource (which should hold AMateria types)
//     std::cout << "Creating MateriaSource..." << std::endl;
//     MateriaSource source;

//     // Test creating and adding Materia to MateriaSource
//     std::cout << "Adding Ice and Cure Materia to MateriaSource..." << std::endl;
//     AMateria* ice = new Ice();
//     AMateria* cure = new Cure();
//     source.learnMateria(ice);
//     source.learnMateria(cure);

//     // Test creating Character and equipping Materia
//     std::cout << "Creating Character 'hero'..." << std::endl;
//     Character hero("hero");

//     // Equip Materia to character
//     std::cout << "Equipping 'hero' with Ice Materia..." << std::endl;
//     // hero.equip(ice);
//     std::cout << "Equipping 'hero' with Cure Materia..." << std::endl;
//     // hero.equip(cure);

//     // Test using the Materia
//     std::cout << "\nUsing equipped Materia..." << std::endl;
//     // Character target("target");
//     // hero.use(0, target); // Using Ice
//     // hero.use(1, target); // Using Cure

//     // Test cloning
//     std::cout << "\nTesting cloning of Materia..." << std::endl;
//     // AMateria* clonedIce = ice->clone();
//     // AMateria* clonedCure = cure->clone();
//     // std::cout << "-------Cloned Materia Types: " << clonedIce->getType() << " and " << clonedCure->getType() << std::endl;

//     // Clean up
//     delete ice;
//     delete cure;
//     // delete clonedIce;
//     // delete clonedCure;
// }
