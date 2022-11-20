#include <iostream>
#include <string>

using namespace std;

template <typename T>

void Sort(T* mas, int dl)
{
    int size = dl;
    double temp;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << "   ";
    }
    cout << endl;
   for(int i=0; i<size-1; i++)
       for (int j = size-2; j >= i; j--)
       {
           if (mas[j] > mas[j + 1]) {
               temp = mas[j];
               mas[j] = mas[j + 1];
               mas[j + 1] = temp;
           }
       }
    cout << "Массив после сортировки:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << "   ";
    }
    cout << endl << endl;
}

template<>
void Sort<char>(char* mas, int dl)
{
    int len = dl;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << "   ";
    }
    cout << endl;
    for (int i = 0; i < len - 1; i++)
        for (int j = len - 2; j >= i; j--)
        {
            if (mas[j] < mas[j + 1]) {
                char c = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = c;
            }
        }
    cout << "Массив после сортировки:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << "   ";
    }
    cout << endl << endl;
}

template<>
void Sort<string>(string* mas, int dl)
{
    int len = dl;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < len - 1; i++)
        for (int j = len - 2; j >= i; j--)
        {
            if (mas[j] < mas[j + 1]) {
                string c = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = c;
            }
        }
    cout << "Массив после сортировка:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << ", ";
    }
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int arr1[] = { 3,24,46,9,10,34,145,89 };
    double arr2[] = { 78.5, 4.7 ,3.2 ,34.6};
    char arr3[] = {'%','5','*','х','%','д','8','ф'};
    string arr4[] = { "polina", "katia","vlad", "danila"};

    Sort(arr1, sizeof(arr1) / sizeof(*arr1));
    Sort(arr2, sizeof(arr2) / sizeof(*arr2));
    Sort(arr3, sizeof(arr3) / sizeof(*arr3));
    Sort(arr4, sizeof(arr4) / sizeof(*arr4));

    return 0;
}