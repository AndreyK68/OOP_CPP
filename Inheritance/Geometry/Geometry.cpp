#include<iostream>
#include<Windows.h>
using namespace std;
namespace Geometry
{
	enum Color // это набор целочисленных именованных констант
// А- цвет фона
//А - цвет шрифта
	{
		CONSOLE_DEFAULT = 0x07,
		CONSOLE_RED = 0xCC,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,
	};

	class Shape
	{
	protected:
		Color color;// Любую фигуру можно нарисовать, 
		//но только каким-то определённым цветом.
	public:
		Color get_color()const
		{
			return this->color;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		Shape(Color color = Color::CONSOLE_DEFAULT) :color(color) {}
		virtual ~Shape() {}

		virtual double get_area() const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw()const = 0;
	};
	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return this->side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			{
				this->side = side;
			}
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw() const
		{
			//#define SIMPLE_DRAW
					//TODO: Color
#ifdef SIMPLE_DRAW



			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, get_color());
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
#endif //SIMPLE_DRAW
			// обработчик окана:
			HWND hwnd = GetConsoleWindow();
			//контекст устройства
			HDC hdc = GetDC(hwnd);
			// создаём карандаш и кисть, котор будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));

			// Берём созданные каранд. и кисть
			SelectObject(hdc, hBrush);
			SelectObject(hdc, hPen);
			//Рисуем квадрат:
			::Rectangle(hdc, 150, 150, side, side);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}

	};
	class Rectangle :public Shape
	{

	};
	class Triangle :public Shape
	{
	public:
		Triangle(Color color) : Shape(color) {}
		~Triangle() {}
		virtual double get_height()const = 0;
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		double set_side(double side)
		{
			if (side <= 0)
			{
				side = 1;
			}
			this->side = side;
			return this->side;
		}
		EquilateralTriangle(double side, Color color) : Triangle(color)
		{
			set_side(side);
		}
		~EquilateralTriangle()

		{


		}
		double get_height()const
		{
			return sqrt(3) / 2 * side;
		}
		double get_area()const
		{
			return get_height() * side / 2;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			unsigned int start_x = 280;
			unsigned int start_y = 150;

			POINT points[] =
			{
				{start_x, start_y + side},
			{start_x + side, start_y + side},
			{start_x + side / 2, start_y + side - get_height()}

			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));


			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);

		}
	};
}

void main()
{
	setlocale(LC_ALL, "Russian");
	//Shape shape(Color::CONSOLE_BLUE);
	//cout << hex << shape.get_color() << endl;

	Geometry::Square square(250, Geometry::Color::CONSOLE_GREEN);
	cout << "Длина стороны:   " << square.get_side() << endl;
	cout << "Площадь квадрата:   " << square.get_area() << endl;
	cout << "Периметр квадрата:   " << square.get_perimeter() << endl;
	square.draw();

	Geometry::EquilateralTriangle e3(100, Geometry::Color::CONSOLE_GREEN);
	cout << "Длина стороны:   " << e3.get_side() << endl;
	cout << "Площадь квадрата:   " << e3.get_area() << endl;
	cout << "Периметр квадрата:   " << e3.get_perimeter() << endl;
	e3.draw();

	//cin.get();
	//Geometry::Rectangle rect;
}