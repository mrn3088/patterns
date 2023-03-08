#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#ifndef AbstractFactory_hpp
#define AbstractFactory_hpp
class Shape {
public:
	virtual void draw() = 0;
};

class Color {
public:
	virtual void fill() = 0;
};

class AbstractFactory {
public:
	virtual Color* getColor(std::string color) = 0;
	virtual Shape* getShape(std::string shape) = 0;
};

class Rectangle : public Shape {
public:
	void draw() override{
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {
public:
	void draw() override{
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class Circle : public Shape {
public:
	void draw() override{
		std::cout << "Inside Circle::draw() method." << std::endl;
	}
};

class Red : public Color {
public:
	virtual void fill() override {
		std::cout << "Inside Red::fill() method." << std::endl;
	}
};

class Green : public Color {
public:
	virtual void fill() override {
		std::cout << "Inside Green::fill() method." << std::endl;
	}
};

class Blue : public Color {
public:
	virtual void fill() override {
		std::cout << "Inside Blue::fill() method." << std::endl;
	}
};

class ShapeFactory : public AbstractFactory {
public:
	Shape* getShape(std::string aShape) override {
		std::string theShape = "";
		std::transform(aShape.begin(), aShape.end(), std::back_inserter(theShape), toupper);
		if (theShape == "CIRCLE") {
			return new Circle();
		}
		if (theShape == "RECTANGLE") {
			return new Rectangle();
		}
		if (theShape == "SQUARE") {
			return new Square();
		}
		return nullptr;
    }

    Color* getColor(std::string aColor) override {
		return nullptr;
	};
};

class ColorFactory : public AbstractFactory {
public:
	Shape* getShape(std::string aShape) override {
		return nullptr;
    }

    Color* getColor(std::string aColor) override {
		std::string theColor = "";
		std::transform(aColor.begin(), aColor.end(), std::back_inserter(theColor), toupper);
		if (theColor == "RED") {
			return new Red();
		}
		if (theColor == "GREEN") {
			return new Green();
		}
		if (theColor == "BLUE") {
			return new Blue();
		}
		return nullptr;
	};
};

#endif