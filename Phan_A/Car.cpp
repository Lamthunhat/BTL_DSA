#include<bits/stdc++.h>
using namespace std;

class Car
{
private:
	string id, name;
	int year;
	double price;		
	
public:
	// Ham khoi tao
	Car()
	{
		id = " ";
		name = " ";
		year = 0;
		price = 0.0;
	}
	
	//Ham khoi tao co tham so
	Car(string id, string name, int year, double price)
	{
		this->id = id;
		this->name = name;
		this->year = year;
		this->price = price;
	}
	
	//Nhap thong tin o to
	friend istream &operator>>(istream &is, Car &car)
	{
		cout << "Nhap ma o to: ";
		is >> car.id;
		cout << "Nhap ten o to: ";
		is.ignore();
		getline(is, car.name);
		cout << "Nhap nam san xuat: ";
		is >> car.year;
		cout << "Nhap gia: ";
		is >> car.price;
		return is;
	}
	
	//Xuat thong tin o to
	friend ostream &operator<<(ostream &os, Car car)
	{
		os << car.id <<" | " << car.name << " | " << car.year << " | " << car.price;
		return os;
	}
	
	//So sanh theo gia
	bool operator<(Car &other)
	{
		return price < other.price;
	}
	
	//Lay id de su dung trong CarManager
	string getId()
	{
		return id;
	}
};