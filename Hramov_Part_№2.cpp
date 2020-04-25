#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

struct Plane {

	string Country;
	int CapacityPeople;
	float Speed;
};

void randString(string& str) {
	static const char alphabet[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	str = "     ";


	for (int i = 0; i < str.length(); i++) {
		int r = rand() % (sizeof(alphabet) - 1);
		str[i] = alphabet[r];
	}
	str[str.length()] = 0;
}

void showPlane(const Plane p) {
	cout << p.Country << "\t"
		<< p.CapacityPeople << "\t"
		<< p.Speed << endl;
}

int findStudentsMark(const Plane p[], const int l, const float key) {
	int count = 0;
	for (int i = 0; i < l; i++) {
		if (p[i].CapacityPeople > key) {
			showPlane(p[i]);
			count++;
		}
	}
	return count;
}

void selectionSort(Plane planes[], int Size) {
	int j = 0;
	Plane tmp;

	for (int i = 0; i < Size; i++) {
		// ищем номер наименьшего элемента среди элементов от i-го до конца
		j = i;

		for (int k = i; k < Size; k++) {
			if (planes[j].Speed > planes[k].Speed) {
				j = k;
			}
		}
		// меняем местами наибольший элемент и текущий
		tmp = planes[i];
		planes[i] = planes[j];
		planes[j] = tmp;
	}
}

void write2File(const Plane p[], const int l) {
	ofstream f;
	f.open("data.txt");


	for (int i = 0; i < l; i++)
		f << p[i].Country << "\t"
		<< p[i].CapacityPeople << "\t"
		<< p[i].Speed << endl;
	f.close();
}


int main() {
	
	setlocale(LC_ALL,"Ru");
	

	int const Size = 15;
	Plane planes[Size];

	for (int i = 0; i < Size; i++)
	{
		planes[i].CapacityPeople =  80 + rand() % 150;
		planes[i].Speed = 725 + rand() % 250;
		randString(planes[i].Country);
		showPlane(planes[i]);

	}
	float Speed = 15.0;
	cout << endl << "Find all who more than " << Speed << endl;
	int findCount = findStudentsMark(planes, Size, Speed);
	cout << "Total " << findCount << " elements" << endl;
	

	cout << endl << "<<<<<<<Sorted>>>>>>>>> " << endl;
	selectionSort(planes, Size);


	for (int i = 0; i < Size; i++)
		showPlane(planes[i]);


	write2File(planes, Size);


	return 0;
}


