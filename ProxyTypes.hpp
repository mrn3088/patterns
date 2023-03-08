struct FooProxy;

struct Foo {
	FooProxy doThat() {return FooProxy(*this);}
};

struct FooProxy {
	FooProxy(Foo& aFoo):foo(aFoo){}
	operator Foo&() {
		return foo;
	}
	Foo &foo;
};

int main() {
	Foo theFoo;
	theFoo.doThat();
}