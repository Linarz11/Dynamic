#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>T** Allocate(const int m, const int n);
template <typename T>void Clear(T** arr, const int m);

template <typename T> void Random(T& variable);

void FillRand(int arr[], const int n, int maxRand = 100, int minRand=0);
void FillRand(float arr[], const int n, int maxRand = 100, int minRand = 0);
void FillRand(double arr[], const int n, int maxRand = 100, int minRand = 0);
void FillRand(char arr[], const int n, int maxRand = 100, int minRand = 0);

void FillRand(int** arr, const int m, const int n);
void FillRand(float** arr, const int m, const int n);
void FillRand(double** arr, const int m, const int n);
void FillRand(char** arr, const int m, const int n);


template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int m, const int n);

template <typename T>void push_back_mutable(T*& arr, int& n, T value);
template <typename T>void push_front_mutable(T*& arr, int& n, T value);
template <typename T>void insert(T*& arr, int& n, T value, int index);

template <typename T>void push_row_back(T**& arr, int& m, const int n);
template <typename T>void push_row_front(T**& arr, int& m, const int n);
template <typename T>void insert_row(T**& arr, int& m, const int n, int index);

template <typename T>void push_col_back(T** arr, const int m, int& n);
template <typename T>void push_col_front(T** arr, const int m, int& n);
template <typename T>void insert_col(T** arr, const int m, int& n, int index);
template <typename T>void pop_col_back(T** arr, const int m, int& n);

template <typename T>void pop_row_back(T**& arr, int& m, const int n);
template <typename T>void pop_row_front(T**& arr, int& m, const int n);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int index);

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
template <typename T>
T** Allocate(const int m, const int n)
{
	//1. создаем массив указателей
	T** arr = new T* [m];
	//2. Выделяем память для строк двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	return arr;
}
template <typename T>
void Clear(T** arr, const int  m)
{
	// 4. УДаление двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		delete[]arr[i];
	}
	delete[] arr;
}

template<typename T>
void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T(); // Записываем в переменную значение по умолчанию
	}
}

void FillRand(int arr[], const int n, int maxRand, int minRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = rand() % 100;
		Random(arr[i]);
	}
}
void FillRand(float arr[], const int n, int maxRand, int minRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = float(rand() % 100)/10;
		Random(arr[i]);
	}
}
void FillRand(double arr[], const int n, int maxRand, int minRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = double(rand() % 100)/10;
		Random(arr[i]);

	}
}
void FillRand(char arr[], const int n, int maxRand, int minRand)
{
	for (int i = 0; i < n; i++)
	{
		//arr[i] = rand() % 100;
		Random(arr[i]);
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = rand() % 100;
			Random(arr[i][j]);
		}
	}
}
void FillRand(float** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = float(rand() % 100)/10;
			Random(arr[i][j]);

		}
	}
}
void FillRand(double** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = double(rand() % 100)/10;
			Random(arr[i][j]);

		}
	}
}
void FillRand(char** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = rand() % 100;
			Random(arr[i][j]);

		}
	}
}

template <typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template <typename T>void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T>void push_back_mutable(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;

}
template <typename T>void push_front_mutable(T*& arr, int& n, T value)
{
	// 1. Создаем буферный массив нужного размера
	T* buffer = new T[n + 1]{};

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
template <typename T>void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
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

template <typename T>void push_row_back(T**& arr, int& m, const int n)
{
	// 1. Создаем буферный массив указателей

T** buffer = new T* [m + 1];

	// 2. КОпируем адреса строк исходного массива в буферный массив указателей:

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//3. УДаляяем исходный массив указателей
	delete[] arr;

	// 4. Говорим что buffer - наш новый массив
	arr = buffer;
	//5. Теперь в нашем массиве есть место для добавления еще одной строки:
	buffer[m] = new T[n] {};
	//6. После добавления строки в массив, количество его строк увеличивается на одну. 
	m++;

}
template <typename T>void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [m + 1];

	// 2. КОпируем адреса строк исходного массива в буферный массив указателей:

	for (int i = 0; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3. УДаляяем исходный массив указателей
	delete[] arr;

	// 4. Говорим что buffer - наш новый массив
	arr = buffer;
	arr[0] = new T[n] {};
	//5. Теперь в нашем массиве есть место для добавления еще одной строки:
	m++;
}
template <typename T>void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T* [m + 1];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	m++;
	arr[index] = new T[n] {};
}

template <typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[m];
	delete[] arr;
	arr = buffer;

}

template <typename T>
void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//1. Создаем буферную строку нужного размера
		T* buffer = new T[n + 1]{};
		//2. Копируем исходную строку в буферную
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		//3. УДаляем исходную строку
		delete[] arr[i];
		//4. Подменяем адрес
		arr[i] = buffer;
	}
	n++;
}

template <typename T>
void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete arr[i];
		arr[i] = buffer;
	}
	n++;
}
template <typename T>
void insert_col(T** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

template <typename T>
void pop_col_back(T** arr, const int m, int& n)
{

}

template <typename T>
void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr[0];
	delete[]arr;
	arr = buffer;
}


template <typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

}

template <typename T>
void pop_front(T*& arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
}
template <typename T>
void erase(T*& arr, int& n, T index)
{
	T* buffer = new T[--n];
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


