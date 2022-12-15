#include <iostream>
#include <iterator>
#include <cstddef>
#include <string>
using namespace std;

template<typename T>
class Node
{
public:
	T GetValue() { return value; }

	Node(T value = T())
	{
		prev = nullptr;
		this->value = value;
	}

	template<class T> friend class Stack;

private:
	Node* prev;
	T value;
};



template<typename T>
class Stack
{
public:
	Stack(bool unique = false);
	~Stack();

	T& Getsize() { return size; }

	void Push(T data);
	T Pop();
	int Find(T data);
	T& operator[](const int index);
	//T& operator++(const int index)
	void Clear();
	void Remove(const int index);


	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Node<T>;
		using pointer = Node<T>*;
		using reference = Node<T>&;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		// Prefix increment
		Iterator& operator++() { m_ptr = m_ptr->prev; return *this; }

		// Postfix increment
		Iterator operator++(int) { Iterator tmp = *this; m_ptr = m_ptr->prev; return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};

	Iterator begin() { return Iterator(top); }
	Iterator end() { return Iterator(nullptr); }

	void Print()
	{
		for (auto i : *this)
			cout << i.value << " ";
		cout << endl;
	}
	
private:
	Node<T>* top;
	int size;
	bool unique;


};

template<typename T>
Stack<T>::Stack(bool unique)
{
	size = 0;
	top = nullptr;
	this->unique = unique;
}

template<typename T>
Stack<T>::~Stack()
{
	Clear();
}

template<typename T>
void Stack<T>::Push(T data)
{
	if (!unique || (unique && Find(data) == -1))
	{
		Node<T>* node = new Node<T>(data);
		if (top == nullptr)
		{
			top = node;
			node->prev = nullptr;
		}
		else
		{
			node->prev = top;
			top = node;
		}
		size++;
	}
	else
		throw exception("Not unique value\n");

}

template<typename T>
T Stack<T>::Pop()
{
	Node<T>* temp_top = top;
	T temp = top->value;

	top = top->prev;
	delete temp_top;
	size--;
	return temp;
}

template<typename T>
int Stack<T>::Find(T data)
{
	Node<T>* temp = this->top;
	for (int i = 0; i < size; i++)
	{
		if (temp->value == data)
			return i;
		temp = temp->prev;
	}
	return -1;
}

template<typename T>
T& Stack<T>::operator[](const int index)
{
	int  counter = 0;
	Node<T>* current = this->top;
	while (current != nullptr)
	{
		if (counter == index)
			return current->value;
		current = current->prev;
		counter++;
	}
}

template<typename T>
void Stack<T>::Clear()
{
	while (size)
	{
		Pop();
	}
}


template<typename T>
void Stack<T>::Remove(const int index)
{
	if (index < size)
	{
		if (index == 0)
			Pop();
		else
		{
			Node<T>* todelete = this->top;
			Node<T>* iterator = this->top;
			for (int i = 0; i < index; i++)
			{
				iterator = todelete;
				todelete = todelete->prev;
			}

			iterator->prev = todelete->prev;
			delete todelete;

			size--;
		}
	}
	else
		throw exception("Index out of range");
}

template <typename T>
void Menu()
{
	cout << "Уникальные или любые элементы? (1 - уникальные/2 - любые)\n";
	int c;
	cin >> c;
	bool flag = c == 1;
	Stack<T> st = *(new Stack<T>(flag));
	try
	{
		flag = true;
		T temp;
		int index;
		while (flag)
		{
			rewind(stdin);
			cin.clear();
			cout << "1. Добавить элемент\n" << "2. Снять элемент\n" << "3. Удалить элемент\n" << "4. Найти\n" << "5. Очистить стек\n" << "6. Просмотр\n" << "7. Выход\n";
			int choice;
			cin >> choice;
			system("CLS");
			switch (choice)
			{
			case(1):
			{
				cout << "Введите элемент: \n";
				cin >> temp;
				st.Push(temp);
				
				break;
			}
			case(2):
			{
				cout << "Снять элемент: " << st.Pop() << endl;
				break;
			}
			case(3):
			{
				cout << "Введите индекс: ";
				cin >> index;
				st.Remove(index);
				
				break;
			}
			case(4):
			{
				cout << "Введите элемент: ";
				cin >> temp;
				cout << "Индекс элемента: " << st.Find(temp) << endl;
				break;
			}
			case(5):
			{
				st.Clear();
				break;
			}
			case(6):
			{
				cout << "Элементы стека: ";
				st.Print();
				break;
			}
			case(7):
			{
				flag = false;
				break;
			}
			default:
				break;
			}
			cout << "\nPress enter\n";
			rewind(stdin);
			getchar();
			system("cls");

		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

}




int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "С каким типом хотите работать?" << endl;
	cout << "1) int\n" << "2) double\n" << "3) char\n";

	int choice;
	cin >> choice;
	switch (choice)
	{
	case(1):
	{
		Menu<int>();
		break;
	}
	case(2):
	{
		Menu<double>();
		break;
	}
	case(3):
	{
		Menu<char>();
		break;
	}
	default:
		break;
	}
}

