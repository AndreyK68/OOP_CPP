#include<iostream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------\n"

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_firt_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//				Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << ", " << age;
		print_year_suffix(age);
		cout << endl;
	}
protected:
	void print_year_suffix(unsigned int age)const
	{
		if (age%20 >= 5 && age%20 <= 20)cout << " лет";
		else if (age % 10 >= 5 || age % 10 == 0)cout << " лет";
		else if (age % 10 > 1 && age % 10 < 5) cout << " года";
		else cout << " год";
	}
};

class Student : public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}

	//				Constructors
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SCostructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", группа: " << group << ", успеваемость: " << rating << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//			Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//			Methos:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", опыт преподавания: " << experience;
		print_year_suffix(experience);
		cout << endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	void set_diploma_theme(const string& diploma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_theme
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diploma_theme(diploma_theme);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methods:
	void print()const
	{
		Student::print();
		cout << "Тема дипломного проекта: " << diploma_theme << endl;
	}
};

//#define INHERITANCE
#define POLYMORPHISM
////#define FOR_SIZEOF

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE
	cout << "Наследование" << endl;
	Human vasya("Тупенко", "Василий", 22);
	vasya.print();

	cout << delimiter << endl;
	Student student("Иванов", "Федор", 25, "РПО", "ВБУ_011", 90);
	student.print();

	cout << delimiter << endl;
	Teacher	teacher("Einstein", "Albert", 142, "Astronomy", 112);
	teacher.print();

	cout << delimiter << endl;
	Graduate graduate("Musk", "Elon", 34, "Car building", "VBU_011", 98, "Колонизация марса");
	graduate.print();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Student("Галлямутдинова", "Альбина", 25, "РПО", "ВБУ_011", 95),
		new Graduate("Ремизов", "Дмитрий", 27, "РПО", "ВБУ_011", 95, "Фиг его значет ;-)"),
		new Teacher("Einstein", "Albert", 142, "Astronomy", 112),
		new Student("Сорокина", "Мария", 22, "РПО", "ВБУ_011", 98)
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		delete group[i];
	}

#endif // POLYMORPHISM

#ifdef FOR_SIZEOF
#define DataType unsigned long long int

	//typedef double DataType;	//Директива typedef создает псевдоним для существующего типа данных.
	DataType arr[] = { 2,3,5,8,13,21,34 };
	for (int i = 0; i < sizeof(arr) / sizeof(DataType); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif // FOR_SIZEOF

}

//virtual type name(parameters) = 0;
//virtual type name(parameters) modifiers = 0;
//virtual type name(parameters) const = 0;