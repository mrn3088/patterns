class Foo {
public:
	Foo& getInstance(){
		if (foo == nullptr) {
			return *(foo = new Foo());
		} else {
			return *foo;
		}
	}
private:
	Foo() = default;
	Foo* foo = nullptr;
};


