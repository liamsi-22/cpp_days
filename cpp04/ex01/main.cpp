#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    int i = 0;
    Animal* Animal_arr[4];
    while(i < 4)
    {
        if (i < 2)
            Animal_arr[i] = new Dog();
        else
            Animal_arr[i] = new Cat();
        i++;
    }
    i = 0;
    while(i < 4)
    {
        std::cout << Animal_arr[i]->getType() << "\t";
        Animal_arr[i++]->makeSound();
    }
    i = 0;
    while(i < 4)
        delete Animal_arr[i++];
}

// int main()
// {
//     const Cat i = Cat();
//     Cat x(i);

//     std::cout << i.brain->ideas[0] << std::endl;
//     std::cout << x.brain->ideas[0] << std::endl;
//     x = i;
//     i.brain->ideas[0] = "HI";
//     std::cout << i.brain->ideas[0] << std::endl;
//     std::cout << x.brain->ideas[0] << std::endl;
//     return 0;
// }