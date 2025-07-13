#include "Character.hpp"
#include "AMateria.hpp"

Character::Character():_name("Default"),_garbageList(NULL){
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name): _name(name), _garbageList(NULL){
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    std::cout << "Character " << _name << " constructor is being called " << std::endl;
}

Character::Character(const Character& other): _name( other._name), _garbageList(NULL){
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }

    const t_garbage* src = other._garbageList;
    t_garbage* dest = NULL;
    while (src)
    {
        t_garbage* newNode = new t_garbage;
        newNode->data = src->data->clone();
        newNode->next = NULL;

        if (!_garbageList)
        {
            _garbageList = newNode;
            dest = _garbageList;
        }
        else
        {
            dest->next = newNode;
            dest = dest->next;
        }
        src = src->next;
    }
    std::cout << "copy constructor " << _name << " is being called" << std::endl;
}



Character& Character::operator=(const Character& other){
    if (this == &other)
        return *this;

    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i])
            delete _inventory[i];
    }

    t_garbage* tmp = _garbageList;
    while (tmp)
    {
        t_garbage* next = tmp->next;
        delete tmp->data;
        delete tmp;
        tmp = next;
    }
    _garbageList = NULL;

    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }

    const t_garbage* src = other._garbageList;
    t_garbage* dest = NULL;
    while (src)
    {
        t_garbage* newNode = new t_garbage;
        newNode->data = src->data->clone();
        newNode->next = NULL;

        if (!_garbageList)
        {
            _garbageList = newNode;
            dest = _garbageList;
        }
        else
        {
            dest->next = newNode;
            dest = dest->next;
        }
        src = src->next;
    }
    _name = other._name;
    std::cout << "assignment " << _name << " operator is being called" << std::endl;
    return (*this);
}


std::string const & Character::getName() const{
    return (_name);
}


void Character::equip(AMateria* m){
    if (!m)
        return ;
    int i;
    for (i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            break;
        }
    }

    if (i == 4)
        std::cout << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 3)
    {
        std::cout << "wrong index" << std::endl;
        return ;
    }

    if (!_inventory[idx])
        return;

    t_garbage* newNode = new t_garbage;
    newNode->data = _inventory[idx];
    newNode->next = NULL;
    
    t_garbage* next = _garbageList;
    while (next && next->next)
        next = next->next;
    if (!next)
        _garbageList = newNode;
    else
        next->next = newNode;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3)
    {
        std::cout << "wrong index" << std::endl;
        return ;
    }
    if (_inventory[idx])
        _inventory[idx]->use(target);
}


Character::~Character(){
    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i])
            delete  _inventory[i];
        _inventory[i] = NULL;
    }
    t_garbage* tmp = NULL;
    while (_garbageList)
    {
        tmp = _garbageList;
        _garbageList = _garbageList->next;
        delete tmp->data;
        delete tmp;
    }
    _garbageList = NULL;
    std::cout << "Character " << _name << " destructor is being called" << std::endl;
}