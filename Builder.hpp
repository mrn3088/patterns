#include <iostream>
#include <string>

class Product
{
public:
	void SetPartA(const std::string &partA)
	{
		partA_ = partA;
	}

	void SetPartB(const std::string &partB)
	{
		partB_ = partB;
	}

	void SetPartC(const std::string &partC)
	{
		partC_ = partC;
	}

	void Show() const
	{
		std::cout << "PartA: " << partA_ << std::endl;
		std::cout << "PartB: " << partB_ << std::endl;
		std::cout << "PartC: " << partC_ << std::endl;
	}

private:
	std::string partA_;
	std::string partB_;
	std::string partC_;
};

class Builder
{
public:
	virtual ~Builder() = default;
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual std::unique_ptr<Product> GetProduct() = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
	void BuildPartA() override
	{
		product_.SetPartA("PartA1");
	}

	void BuildPartB() override
	{
		product_.SetPartB("PartB1");
	}

	void BuildPartC() override
	{
		product_.SetPartC("PartC1");
	}

	std::unique_ptr<Product> GetProduct() override
	{
		return std::make_unique<Product>(product_);
	}

private:
	Product product_;
};

class ConcreteBuilder2 : public Builder
{
public:
	void BuildPartA() override
	{
		product_.SetPartA("PartA2");
	}

	void BuildPartB() override
	{
		product_.SetPartB("PartB2");
	}

	void BuildPartC() override
	{
		product_.SetPartC("PartC2");
	}

	std::unique_ptr<Product> GetProduct() override
	{
		return std::make_unique<Product>(product_);
	}

private:
	Product product_;
};

class Director
{
public:
	void SetBuilder(std::unique_ptr<Builder> builder)
	{
		builder_ = std::move(builder);
	}

	std::unique_ptr<Product> Construct()
	{
		builder_ -> BuildPartA();
		builder_ -> BuildPartB();
		builder_ -> BuildPartC();
		return builder_ -> GetProduct();
	}

private:
	std::unique_ptr<Builder> builder_;
};

