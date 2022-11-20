#include <iostream>
#include <exception>
using namespace std;


class MyException:public exception
{
public:
    static void ErrorInputSize()
    {
        cout << "Ошибка ввода размера массива!" << endl;
    }
    static void ErrorInputElement()
    {
        cout << "Ошибка ввода элемента массива!" << endl;
    }
    static void ErrorIndex()
    {
        cout << "Ошибка ввода индекса элемента массива!"<< endl;
    }

};
template <class T>
class Array
{
private:
	T* m_array;
	int size;
public:
    
    Array() {}

    Array(int size) {
        this->size = size;

            if (!(m_array = (T*)malloc(size * sizeof(T))))
                throw exception("Ошибка при выделении памяти!");
      
    }

    Array(T* _arr, int size) {
        try {
            if (size < 0)
                throw MyException();
        }
        catch (const MyException& ex)
        {
            MyException::ErrorInputSize();
        }
        this->size = size;

        if (!(m_array = (T*)malloc(size * sizeof(T))))
            throw exception("Ошибка при выделении памяти!");

        for (int i = 0; i < size; i++) {
            m_array[i] = _arr[i];
        }
        
    }
    void Insert(int index, T value)
    {
        if (size <= index || index < 0)
            throw exception("Неправильный индекс для добавления элемента.");
        m_array[index] = value;
    }

    void View() 
    {
        for (int i = 0; i < size; i++) {
            cout <<"Элемент["<< i<<"] = " << m_array[i]<<endl;
        }
        cout << endl;
    }
    void Delete()
    {
        int index;
        cout << "Введите индекс элемента для удаления: " << endl;
        if (!(cin >> index))
            throw MyException();
        try {
            if (index >= size || index < 0)
                throw MyException();
        }
        catch (const MyException& ex)
        {
            MyException::ErrorIndex();
        }
        m_array[index] = 0;
    }
    void Search()
    {
        int elem;
        cout << " Введите элемент для поиска индекса:" << endl;
        try {
            int  temp = 0;
            if (!(cin >> elem))
                throw MyException();
            for (int i = 0; i < size; i++)
            {
                if (m_array[i] == elem)
                {
                    cout << "Данный элемент под индексом " << i << endl;
                    temp++;
                }
            }
            if(temp == 0) 
                cout << " Элемент не найден." << endl; 
        }
        catch (const MyException& ex)
        {
            MyException::ErrorInputElement();
        }
    }
    void Compare()
    {
        int index1, index2;
        cout << "Введите индексы элементов для сравнения: " << endl;
        try {
            if (!(cin >> index1))
                throw MyException();
            if (!(cin >> index2))
                throw MyException();
            if (index1 >= size || index2 >= size)
                throw 1;

            if (m_array[index1] > m_array[index2]) cout << m_array[index1] << " больше " << m_array[index2] << endl;
            if (m_array[index1] < m_array[index2]) cout << m_array[index1] << " меньше " << m_array[index2] << endl;
            if (m_array[index1] == m_array[index2]) cout << "Элементы равны" << endl;
        }
        catch (const MyException& ex)
        {
            MyException::ErrorIndex();
        }
        catch (...)
        {
            cout << "Элементов с таким индексом не существует!" << endl;
        }
    }

};

void _terminate() {
    cout << "Terminate" << endl;
    abort();
}

void _unexpected() {
    cout << "Unexpected " << endl;
    abort();
}

int main()
{
    system("chcp 1251");
    system("cls");
    set_terminate(_terminate);
    set_unexpected(_unexpected);
    cout << "Введите размер массива: " << endl;
    int size;
    if (!(cin >> size))
        throw exception("Ошибка ввода!");

    Array<int> m_array(size);

    cout << "Введите элементы:" << endl;
    for (int i = 0; i < size; i++)
    {
        int tmp;
        try {
            if (!(cin >> tmp))
                throw MyException();
        }
        catch (const MyException& ex)
        {
            MyException::ErrorInputElement();
        }
        m_array.Insert(i, tmp);
    }

    m_array.View();

    m_array.Delete();

    system("cls");

    m_array.Search();

    m_array.View();

    m_array.Compare();


	return 0;
}