


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

	T** buffer = new T * [m + 1];

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
	buffer[m] = new T[n]{};
	//6. После добавления строки в массив, количество его строк увеличивается на одну. 
	m++;

}
template <typename T>void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1];

	// 2. КОпируем адреса строк исходного массива в буферный массив указателей:

	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3. УДаляяем исходный массив указателей
	delete[] arr;

	// 4. Говорим что buffer - наш новый массив
	arr = buffer;
	arr[0] = new T[n]{};
	//5. Теперь в нашем массиве есть место для добавления еще одной строки:
	m++;
}
template <typename T>void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [m + 1];

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
	arr[index] = new T[n]{};
}

template <typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
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
	T** buffer = new T * [--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
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
		buffer[i] = arr[i + 1];
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