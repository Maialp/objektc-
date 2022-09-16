#include "dummy.h"

Dummy::Dummy(const Dummy &other){
    this->num = new int{};
    *num = *other.num;
}

 Dummy& Dummy::operator=(Dummy rhs){
    swap(num, rhs.num);
    return *this;
}
 

void dummyTest() {
Dummy a;
*a.num = 4;
Dummy b{a};
Dummy c;
c = a;
cout << "a: " << *a.num << '\n';
cout << "b: " << *b.num << '\n';
cout << "c: " << *c.num << '\n';
*b.num = 3;
*c.num = 5;
cout << "a: " << *a.num << '\n';
cout << "b: " << *b.num << '\n';
cout << "c: " << *c.num << '\n';
}