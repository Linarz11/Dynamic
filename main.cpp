#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);
void insert(int*& arr, int& n, int value, int index);
void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
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


}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void push_back_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;

}

void push_front_mutable(int*& arr, int& n, int value)
{
	// 1. Создаем буферный массив нужного размера
	int* buffer = new int[n + 1]{};

	//2. копируем значения из исходного массива в буферный со смещением на один элемент
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3. Удаляем исходный массив
	delete[] arr;
	//4. Подменяем указатель на адрес нового массива
	arr = buffer;
	//5. Добавляем значение в начало массива
	arr[0] = value;
	//6. Увеличиваем размер массива
	n++;
}

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	//for (int i = 0; i < index; i++)
	//{
	//	buffer[i] = arr[i];
	//	// ДОписать тернарный вид
	//	
	//}
	//for (int i = index; i < n; i++)
	//{
	//	buffer[i + 1] = arr[i];
	//}
	for (int i = 0; i < n; i++)
	{
		(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		//(i<index ? buffer[i] :buffer[i+1]) = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
}

void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
