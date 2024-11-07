#include <bits/stdc++.h>
#include "CarManager.cpp"
using namespace std;

class App
{
private:
	CarManager carManager;
	
public:
	void showMenu()
	{
		int choice;
		do
		{
			cout << "\n===== MENU QUAN LY O TO =====\n";
			cout << "1. Them o to\n";
			cout << "2. Xoa o to\n";
			cout << "3. Hien thi danh sach o to\n";
			cout << "4. Sap xep o to theo gia\n";
			cout << "5. Tim o to co gia cao nhat\n";
			cout << "6. Tim o to co gia thap nhat\n";
			cout << "7. Tim o to theo ma\n";
			cout << "0. Thoat!\n";
			cout << "\n";
			cin >> choice;
			
			switch(choice)
			{
				case 1:
				{
					Car car;
					cin >> car;
					carManager.addCar(car);
					break;
				}
				
				case 2:
				{
					string id;
					cout << "Nhap ma o to can xoa: ";
					cin >> id;
					carManager.removeCarById(id);
					break;	
				}
				
				case 3:
				{
					carManager.displayCars();
					break;
				}
				
				case 4:
				{
					carManager.sortCars();
					cout << "Danh sach sau khi sap xep:\n";
					carManager.displayCars();
					break;
				}
				
				case 5:
				{
					cout << "O to co gia cao nhat:\n"<< carManager.findMaxPriceCar() << "\n";
					break;
				}
				
				case 6:
				{
					cout << "O to co gia thap nhat:\n" << carManager.findMinPriceCar() << "\n";
					break;
				}
				
				case 7:
				{
					string id;
					cout << "Nhap ma o to can tim: ";
					cin >> id;
					Car *car = carManager.findCarById(id);
					if(car)
					{
						cout << "Thong tin o to:\n" << *car << "\n";
					}
					else
					{
						cout << "Khong tim thay ma o to!\n";
					}
					break;
				}
				
				case 0:
				{
					cout << "Thoat chuong trinh!\n";
					break;
				}
				
				default:
				{
					cout << "Lua chon khong hop le!\n";
				}
			
			}
		}
		while(choice != 0);
	}
};

int main()
{
	App app;
	app.showMenu();
	return 0;
}
