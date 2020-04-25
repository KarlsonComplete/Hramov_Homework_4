/*#include <iostream>
#include <ctime>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void selectionSort(float data[], int len) {
	int j = 0;
	float tmp = 0;


	for (int i = 0; i < len; i++) {
		// ищем номер наименьшего элемента среди элементов от i-го до конца
		j = i;


		for (int k = i; k < len; k++) {
			if (data[j] > data[k]) {
				j = k;
			}
		}
		// меняем местами наибольший элемент и текущий
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}

	cout << "==========SORTED:=========" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}
}

void bubbleSort(float data[], int len) {
	float tmp = 0;
	// идём по массиву
	for (int i = 0; i < len; i++) {
		// делаем проверки в оставшейся части массива
		for (int j = len - 1; j >= i + 1; j--) {
			if (data[j] < data[j - 1]) {  // сравниваем соседние элементы
				// делаем перестановку
				tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
			}
		}
	}
	cout << "==========SORTED:=========" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	int ValueInput;
	int const Size = 10;
	float data[Size];

	for (int i = 0; i < Size; i++)
	{
		data[i] = -10 + rand() % 31;
	}

	for (int i = 0; i < Size; i++)
	{
		cout << data[i] << endl;
	}
	
	cout << "Введите каким методом вы хотите сделать сортировку: " << endl
		<< "1.Выбором" << endl
		<< "2.Пузырьковым" << endl;
	cin >>ValueInput;

	switch (ValueInput)
	{
		case 1:
			selectionSort(data, Size);
			break;
		case 2:
			bubbleSort(data, Size);
			break;
	default:
		break;
	}

	system("pause");
}*/

