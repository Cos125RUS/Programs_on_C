#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle(double = 1.0, double = 1.0);

	double perimeter();
	double area();

	double getLength();
	double getWidth();

	void setLength(double);
	void setWidth(double);

private:
	double length;
	double width;
};

#endif // !RECTANGLE_H

