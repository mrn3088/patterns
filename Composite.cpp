#include <iostream>
#include <unordered_set>
class Component {
public:
	virtual Component& operation() = 0;
};

class Leaf : public Component {
public:
	virtual Component& operation() override {
		std::cout << "This is a Leaf" << std::endl;
		return *this;
	}
};

class Composite : public Component {
public:
	virtual Component& operation() override {
		std::cout << "This is a Composite" << std::endl;
		return *this;
	}
	Composite& addChildren(Component* aChild) {
		children.insert(aChild);
		return *this;
	}
	size_t removeChild(Component* aChild) {
		return children.erase(aChild);
	}

protected:
	std::unordered_set<Component*> children;
};