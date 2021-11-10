#include <iostream>
#include "time.h"
#include <conio.h>
#include <stdio.h>

using namespace std;


class Date
{
	int day;
	int mouth;
	int year;

public:

	Date(int day, int mouth, int year):day{day},mouth{mouth},year{year}
	{}
	Date(int year) :Date(1, 1, year)
	{}

	friend void displayDate(Date date);
};

void displayDate (Date date)
{
	cout << date.day << "." << date.mouth << "." << date.year << "\n";
}

Date baseDate()
{
	return 2000;
}

class Array
{
	int size;
	int* array;

public:

	explicit
	Array(int size = 10);
	~Array();

	int getSize()const;
	int getValue(int index)const;
	void setValue(int index,int Value);
	void display(int index)const;
};

Array::Array(int size)
{
	this->size = size;
	array = new int[size];
}

Array::~Array()
{
	delete[] array;
}

int Array::getSize() const
{
	return size;
}

int Array::getValue (int index)const
{
	return array[index];
}

void Array::setValue(int index, int Value)
{
	array[index]= Value;
}

void Array::display (int index) const
{
	cout << array[index] << " ";
}

void display(const Array& array)
{
	for (int i = 0; i < array.getSize(); i++)
	{
		array.display(i);
	}
	cout << "\n";
}

class Point
{
	double x;
	double y;

public:

	Point() {};
	Point(double x, double y) :x{ x }, y{ y }{}
	void display() 	const //����� ����� �� �����
	{
		cout << "(" << x << ";" << y << ")";
	}

	void read() //������ �����
	{
		cout << "x= ";
		cin >> x;
		cout << "y= ";
		cin >> y;
	}
	static bool isEqual(const Point& point1, const Point& point2)	//��������� ���� �����(��� �������)
	{
		return point1.x == point2.x && point1.y == point2.y;
	}
	static Point add(const Point& point1, const Point& point2)	//�������� ���� ��������
	{
		return Point(point1.x + point2.x, point1.y + point2.y);
	}
	static Point mult(const Point& point1, double value)	// ��������� ������� �� �����
	{
		return Point(point1.x * value, point1.y * value);
	}
	static double distance(const Point& point1, const Point& point2)	// ���������� ����� �������
	{
		return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
	}
	static double legth(const Point& point)	//������ �������
	{
		return distance(point, Point());
	}

	friend bool operator==(const Point& point1, const Point& point2)
	{
		return isEqual(point1,point2);
	}

	friend Point operator+(const Point& point1, const Point& point2)
	{
		return add(point1, point2);
	}

	friend Point operator*(const Point& point1, double value)
	{
		return mult(point1, value);
	}

	friend ostream& operator<<(ostream& output, const Point& point)
	{
		output << "(" << point.x << ";" << point.y << ")";
		return output;
	}

};




int main()
{
	setlocale(LC_ALL, "Rus");

	//displayDate(2021);
	//Date date{ 2010 };
	//displayDate( date );
	//Date date2000{ baseDate() };
	//displayDate(date2000);

	//cout << "������������ ������ ����� �����\n";
	//int size = 4;
	//Array array(size);
	//for (int i = 0; i < size; i++)
	//{
	//	array.setValue(i, size - i);
	//}
	//display(array);
	//cout << "!!!\n";
	//display(3);

	Point point1(1, 1);
	Point point2;
	Point point3(1, 1);
	if (point1 == point3)
	{
		cout << "����� 1 � ����� 3 �����\n";
	}
	cout << "\n�����1\n";
	point1.display();
	cout << "\n";
	cout << "\n������� ����� 2\n";
	point2.read();
	cout << "����� 2\n";
	point2.display();
	cout << "\n";
	cout << "����� 1 + ����� 2= " << point1 + point2 << "\n";
	cout << "���������� ����� ������� 1 � 2\n";
	cout << "�����: " << Point::distance(point1, point2);
	cout << "\n��������� ����� 1 � 2\n" << point1 * 5;




	return 0;
}