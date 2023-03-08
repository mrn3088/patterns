#include <iostream>
#include <ios>
template <typename Derived>
class Foo{
	void fun() {
		static_cast<Derived>(*this).fun();
	}
};

class Sub: public Foo<Sub> {
	void fun() {		
		std::cout << "fun" << std::endl;
	}
};


/**
 * HUM 2 20.0+
 * CSE 105 8.5
 * CSE 168 13.5
 * CSE 150B 7.0
 * CSE 120 10.5
 */