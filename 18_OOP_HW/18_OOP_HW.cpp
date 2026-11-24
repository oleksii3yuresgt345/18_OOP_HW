#include <iostream>
using namespace std;

enum Type { None, Sedan, Hatchback, Universal };
class Body
{
	Type type;
public:
	Body() :type(None) {}
	Body(Type t) :type(t) {}
	void Print()const
	{
		cout << "Body's type : ";
		switch (type)
		{
		case None:cout << "None" << endl;break;
		case Sedan:cout << "Sedan" << endl;break;
		case Hatchback:cout << "Hatchback" << endl;break;
		case Universal:cout << "Universal" << endl;break;
		}
	}

};
class Wheel
{
	float radius;
public:
	Wheel() :radius(0) {}
	Wheel(float r) :radius(r) {}
	void Print()const { cout << "Wheel's radius : " << radius << endl; }
};
class Engine
{
	string type;
	float volume;
public:
	Engine() :type("none"), volume(0) {}
	Engine(string t, float v) :type(t), volume(v) {}
	void Print()const
	{
		cout << "Engine's type : " << type << endl;
		cout << "Engine's volume : " << volume << endl;
	}
};

class Door
{
	string color;
public:
	Door() :color("none") {}
	Door(string c) :color(c) {}
	void Print()const { cout << "Door's color : " << color << endl; }
};

class Headlight
{
	int lightPower;
public:
	Headlight() :lightPower(0) {}
	Headlight(int l) :lightPower(l) {}
	void Print()const { cout << "Headlight's light power : " << lightPower << endl; }
};

class Driver
{
	string name;
	string surname;
	int age;
	int driveYears;
public:
	Driver() :name("none"), surname("none"), age(0), driveYears(0) {}
	Driver(string n, string s, int a, int dy) :name(n), surname(s), age(a), driveYears(dy) {}
	void Show()const
	{
		cout << "-Driver's info-" << endl;
		cout << "Name : " << surname << " " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Years of driving : " << driveYears << endl;
	}
};

class Car
{
	Headlight* lights;
	int countLights;

	Door* doors;
	int countDoors;

	Wheel* wheels;
	int countWheels;

	Engine engine;

	Body body;

	Driver* driver;
public:
	Car() :
		countLights(2),
		countDoors(4), 
		countWheels(4), 
		body(Type::None),
		driver(nullptr)
	{
		lights = new Headlight[countLights];
		doors = new Door[countDoors];
		wheels = new Wheel[countWheels];
	};
	Car(Headlight hl, Door d, Wheel w, string t, float v, Type tp) :
		countLights(2),
		countDoors(4),
		countWheels(4),
		engine(t, v), body(tp)
	{
		lights = new Headlight[countLights];
		doors = new Door[countDoors];
		wheels = new Wheel[countWheels];
		for (int i = 0; i < countLights; i++)
		{
			lights[i] = hl;
		}
		for (int i = 0; i < countDoors; i++)
		{
			doors[i] = d;
		}
		for (int i = 0; i < countWheels; i++)
		{
			wheels[i] = w;
		}
	}
	Car(Headlight hl, Door d, Wheel w, string t, float v, Type tp, Driver* driv) :Car(hl, d, w, t, v, tp)
	{
		driver = driv;
	}
	void Print()const
	{
		for (int i = 0; i < countLights; i++)
		{
			cout << "-" << i + 1 << " Light-" << endl;
			lights[i].Print();
		}
		cout << endl;
		for (int i = 0; i < countDoors; i++)
		{
			cout << "-" << i + 1 << " Door-" << endl;
			doors[i].Print();
		}
		cout << endl;
		for (int i = 0; i < countWheels; i++)
		{
			cout << "-" << i + 1 << " Wheel-" << endl;
			wheels[i].Print();
		}
		cout << endl;
		cout << "-Car's engine-" << endl;
		engine.Print();
		cout << "-Car's body-" << endl;
		body.Print();

		if (driver != nullptr) driver->Show();
		else cout << "Car has no driver!" << endl;

	}
	void AddDriver(Driver* driv)
	{
		driver = driv;
	}
	~Car()
	{
		if (lights != nullptr) delete[]lights;
		if (doors != nullptr) delete[]doors;
		if (wheels != nullptr) delete[]wheels;
	}
	
};
int main()
{
	Driver driver("Taras", "Tarasovuch", 21, 3);
	Driver driver2("Ivan", "Ivanovuch", 45, 20);
	Car car({ 2 }, { "blue" }, { 9.5 }, "V8", 10, Type::Universal);
	car.AddDriver(&driver);
	car.Print();
	car.AddDriver(&driver2);
	car.Print();
}