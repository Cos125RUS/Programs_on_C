#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle(double = 1.0, double = 1.0, double = 1.0, double = 1.0, double = 1.0, double = 1.0, double = 1.0, double = 1.0);

	double perimeter();
	double area();
	double getLength();
	double getWidth();

	void setPoint(double, double, double, double, double, double, double, double);
	bool isTriangle(double, double, double, double, double, double, double, double);

	bool square();

	void setPerimeterCharacter(char);
	void setFillCharacter(char);

	void draw();
private:
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	double x4;
	double y4;
	char charPerimeter;
	char charFill;
};

#endif // !RECTANGLE_H

