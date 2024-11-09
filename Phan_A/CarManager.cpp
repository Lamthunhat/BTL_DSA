#include<bits/stdc++.h>
#include "Car.cpp"
using namespace std;

class CarManager
{
private:
	list<Car> cars;
	
public:
	//Them o to vao danh sach
	void addCar(Car &car)
	{
		cars.push_back(car);
	}
	
	//Xoa o to theo ma
	void removeCarById(string &id) 
	{
        auto it = find_if(cars.begin(), cars.end(), [&](Car &car)
		{ 
			return car.getId() == id; 
		});

        if (it != cars.end()) 
		{
            cars.erase(it);
            cout << "Da xoa thanh cong.\n";
        } 
		else 
		{
            cout << "Khong tim thay ma o to.\n";
        }
    }
	
	//Xuat danh sach o to
	void displayCars()
	{
		//Neu danh sach o to dang trong
		if(cars.empty())
		{
			cout << "\nDanh sach o to hien dang trong.\n";
		}
		else
		{			 
			for(auto &car : cars)
			{
				cout << car << "\n";
			}	
		}
	}
	
	//Sap xep danh sach o to theo gia
	void sortCars()
	{
		cars.sort();
	}
	
	//Tim o to co gia cao nhat
	Car findMaxPriceCar()
	{
		return *max_element(cars.begin(), cars.end());
	}
	
	//Tim o to co gia thap nhat
	Car findMinPriceCar()
	{
		return *min_element(cars.begin(), cars.end());
	}
	
	//Tim kiem o to theo ma
	Car *findCarById(string &id)
	{
		for(auto &car : cars)
		{
			if(car.getId() == id)
			{
				return &car;
			}
		}
		return nullptr;
	}
};
