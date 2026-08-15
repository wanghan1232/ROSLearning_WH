#include "HelloWorld.hpp"

#include <iostream>

HelloWorld::HelloWorld(std::string name, int age)
    : name(name), age(age) {
}

void HelloWorld::myPrint() {
    std::cout << "Hello World, my name is " << name
              << ", my age is " << age << "." << std::endl;
}
