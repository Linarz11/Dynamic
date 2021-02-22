#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include "Arrays.h"
#include "Memory.h"
#include"Print.h"
#include "Random.h"


typedef double DataType;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "введите размер массива: "; cin >> n;
	int* arr = new int[n];
	int index;

	FillRand(arr, n);
	Print(arr, n);

	int value;
	//cout << "Введите добавляемое значение: "; cin >> value;

	/*Сделать Алгоритм добавления элемента в массив*/
	//n++;
	//int* brr = new int[n] {};
	//cout << "Value = " << value << "\t" << "&= " << &value << endl;
	//cout << "arr[3]= " << arr[3] << endl;
	//for (int i = 0, i_brr = 0; i < n-1, i_brr<n; i++, i_brr++ )
	//{
	//	 brr[i_brr] = arr[i];
	//	 if (i_brr == n-1)
	//	 brr[i_brr] = value;
	//}
	////brr[n] = value; этот вариант не сработал почечу-то
	//Print(brr, n);

	/*push_back_mutable(arr, n, value);
	Print(arr, n);


	push_front_mutable(arr, n, value);
		Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

		pop_back(arr, n);
		Print(arr, n);

		pop_front(arr, n);
		Print(arr, n);*/
	cout << "Введите индекс, который необходимо удалить: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);

#endif // DYNAMIC_MEMORY_1

	int m; //КОличество строк
	int n; //КОличество столбцов (элементов строки)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введиет количество элементов строки: "; cin >> n;

	DataType** arr = Allocate<DataType>(m, n);

	// 3. Работа с двумерным динамическим массивом
	FillRand(arr, m, n);
	Print(arr, m, n);
	cout <<"Добавляем строку в конец: " << endl;
	push_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "Добавляем строку в начало: " << endl;

	push_row_front(arr, m, n);
	Print(arr, m, n);
	
	int index;
	cout << "Введите индекс строки куда  нужно вставить новую строку: " << endl; cin >> index;
	insert_row(arr, m, n, index);
	Print(arr, m, n);
	cout << "УДаляем последнюю строку: " << endl;

	pop_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "УДаляем первую строку: " << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	
	cout << "Добавляем столбец в конец массива: " << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавляем столбец в начало массива: " << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);
	cout << "Введите индекс добавляемого столбца: " << endl; cin >> index;

	insert_col(arr, m, n, index);
	Print(arr, m, n);
	
	Clear(arr, m);
	

}



