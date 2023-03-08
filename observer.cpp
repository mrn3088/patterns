#include "Observer.hpp"
int main() {
	ConcreteObserver *co = new ConcreteObserver();
	ConcreteSubject *cb = new ConcreteSubject();
	cb -> registerObserver(co);
	cb -> notifyObservers();
}