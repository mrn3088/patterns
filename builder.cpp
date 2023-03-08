#include "Builder.hpp"
int main()
{
	Director director;
	std::unique_ptr<Builder> builder1 = std::make_unique<ConcreteBuilder1>();
	std::unique_ptr<Builder> builder2 = std::make_unique<ConcreteBuilder2>();

	director.SetBuilder(std::move(builder1));
	std::unique_ptr<Product> product1 = director.Construct();
	product1->Show();

	director.SetBuilder(std::move(builder2));
	std::unique_ptr<Product> product2 = director.Construct();
	product2->Show();

	return 0;
}
