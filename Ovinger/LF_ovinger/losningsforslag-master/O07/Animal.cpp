#include "Animal.h"
#include "Graph.h" // For Vector_ref, støttehjul fram til vi lærer om pekere

using namespace Graph_lib;

string Animal::toString() const {
    return "Animal: " + name + ", " + to_string(age);
}

string Dog::toString() const {
    return "Dog: " + name + ", " + to_string(age);
}

string Cat::toString() const {
    return "Cat: " + name + ", " + to_string(age);
}

void testAnimal() {
    Vector_ref<Animal> animals;

    Cat tiger{"Tiger", 5};
    animals.push_back(tiger);
    Dog fido{"Fido", 3};
    animals.push_back(fido);
    Cat max{"Max", 7};
    animals.push_back(max);
    Dog buster{"Buster", 15};
    animals.push_back(buster);
    Cat kitty{"Kitty", 12};
    animals.push_back(kitty);
    Dog coco{"Coco",4};
    animals.push_back(coco);

    for (int i = 0; i < animals.size(); ++i) {
        cout << animals[i].toString() << '\n';
    }
}
