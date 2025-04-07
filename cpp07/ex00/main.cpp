#include "whatever.hpp"

/*
class TestType{
    public:
        std::string name;
        bool operator<(const TestType &other) const{
            return (this->name < other.name);
        }
        bool operator>(const TestType &other) const{
            return (this->name > other.name);
        }
};
*/


int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}


/*
//Testing complex types
int main(){
    TestType thingA;
    TestType thingB;
    thingA.name = "Hello";
    thingB.name = "World";
    std::cout << "Thing A name: " << thingA.name << std::endl;
    std::cout << "Thing B name: " << thingB.name << std::endl << std::endl;
    swap(thingA, thingB);
    std::cout << "Thing A name: " << thingA.name << std::endl;
    std::cout << "Thing B name: " << thingB.name << std::endl << std::endl;

    std::cout << "Max: " << max(thingA, thingB).name << std::endl;
    std::cout << "Min: " << min(thingA, thingB).name << std::endl;
}
*/