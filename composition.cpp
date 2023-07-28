#include <iostream>
using namespace std;

class Battery
{

public:
	string company;
	Battery(string company)
	{
		this->company = company;
	}
};

class Engine
{
};

class Car
{
private:
	string name, model, color;
	Battery *bat;
	Engine *eng;

public:
	Car(string name, string model, string color, Battery *bat)
	{
		this->name = name;
		this->model = model;
		this->color = color;
		this->bat = bat;
		eng = new Engine();
	}
	void showDetail()
	{
		cout << "Name" << name << endl;
		cout << "Model" << model << endl;
		cout << "color" << color << endl;
		cout << "Battery" << bat->company;
	}
	~Car()
	{
		delete bat, eng;
	}
};

int main()
{
	Battery b1("Exide");
	Car c1("a", "b", "c", &b1);
	c1.showDetail();
}