#include <iostream>
using namespace std;

template <typename T>
class Array {
	T* data;
	int size;
	int n;
public:
	Array() : size(3),n(0){
		this->data = new T[size];
	}
	void grow()
	{
		size *= 2;
		T* arr2 = new T[size];
		for (int i = 0; i < n; i++)
			arr2[i] = data[i];
		delete[]data;
		data = arr2;
	}
	void add(T el)
	{
		if (size == n)
		{
			grow();
		}
		data[n++] = el;
	}
	void shrink()
	{
		if (size > 1)
		{
			size /= 2;
			T* arr2 = new T[n];
			for (int i = 0; i < n; i++)
				arr2[i] = data[i];
			delete[]data;
			data = arr2;
		}
	}

	





	void remove()
	{
		if (--n < size / 2)
			shrink();
	}
	int search(T el)
	{
		for (int i = 0; i < n; i++)
			if (data[i] == el)
				return i;
		return -1;
	}

	void selectionSort() {
	
		for (int i = 0; i < n - 1; i++) {

			
			for (int j = i + 1; j < n; j++) {
				if (data[j] < data[i]) {
					T temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}

	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << data[i];
		}
		cout << endl;
	}

	Array(Array & obj)
	{
		this->size = obj.size;
		this->data = new T[size];
		this->n = obj.n;
		for (int i = 0; i < n; i++)
		{
			this->data[i] = obj->data[i];
		}
	}

	~Array()
	{
		delete[]data;
	}
};


int  main() {

	Array<int> arr;


	arr.add(5);
	arr.add(3);
	arr.add(8);
	arr.add(1);

	cout << "Array after adding elements: ";
	arr.print();

	
	int index = arr.search(3);
	cout << "Index of 3: " << index << endl;

	
	arr.selectionSort();
	cout << "Array after sorting: ";
	arr.print();

	
	arr.remove();
	cout << "Array after removing one element: ";
	arr.print();


	return 0;
}