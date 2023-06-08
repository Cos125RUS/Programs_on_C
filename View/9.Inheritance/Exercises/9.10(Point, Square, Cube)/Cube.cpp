#include "Cube.h"

Cube::Cube(double l, int x, int y, int c) : Square(l, x, y) { z = c; }

double Cube::area() const { return 12 * line ; }

double Cube::volume() const { return Square::area() * line ; }

ostream& operator<<(ostream& output, const Cube& c)
{
	output << "��� ���-�� ���� ��������� ����� ������ ��������� =)\n" 
		<< "��� ����� ����� �����: (" << c.x  << "," << c.y << "," << c.z << ")" << endl;

	return output;
}