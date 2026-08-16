#ifndef HELLOWORLD_HPP
#define HELLOWORLD_HPP

#include <string>

class HelloWorld {
private:
    std::string name;
    int age;

public:
    HelloWorld(std::string name, int age);
    void myPrint();
};

#endif
