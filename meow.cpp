#include <iostream>

class Kitty
{
    public:
        int age;
        std::string Breed;
};
void foo();


int main()
{
    for(int i = 0; i < 100 ; i++)
        std::cout << "viow meow\n";

    Kitty cat;
    cat.age = 12;

    foo();

    std::cout << cat.age;
    
    
}

void foo()
{
    std::cout<< "\nFoo maxing";
}