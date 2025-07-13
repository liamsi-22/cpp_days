// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


// int main(){
//     Animal* animal = new Dog();
//     std::cout << "My type is " << animal->getType() << " i can ";
//     animal->makeSound();
//     delete animal;
//     animal = new Cat();
//     std::cout << "My type is " << animal->getType() << " i can ";
//     animal->makeSound();
//     delete animal;    
// }

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();

    
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* cat = new WrongCat();
    std::cout << meta->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    meta->makeSound();
    cat->makeSound();
    return (0);
}