#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define FileSource  "source.txt"
#define FileOutput "output.txt"

vector<int> Count(string source, char c)
{
	system("cls");
	ifstream inp;
	inp.open(source, ios_base::in);
	if (!inp.is_open())
		throw exception("Ошибка открытия файла\n");

	cout << "[ОТКРЫТИЕ ВХОДНОГО ФАЙЛА]\n\n";
	
	string line;
	int counter;
	vector<int> vec;
	while (getline(inp, line, '\n'))
	{
		counter = 0;
		if (inp.eof())
			break;

		for (auto l : line)
			if (l == c) counter++;

		vec.push_back(counter);
		cout << "Номер строки: " << vec.size() << "\n";
		cout << "Число символов '"<< c <<"' в строке : " << counter << "\n\n";
	}
	inp.close();
	cout << "[ЗАКРЫТИЕ ВХОДНОГО ФАЙЛА]\n\n\n";
	return vec;
}

void Result(string out_file_name, vector<int> vc)
{
	ofstream out;
	out.open(out_file_name, ios_base::out | ios_base::trunc);
	if (!out.is_open())
		throw exception("Ошибка открытия файла\n");
	cout << "[ОТКРЫТИЕ ВЫХОДНОГО ФАЙЛА]\n\n";

	for (auto count : vc)
	{
		out << count << "\n";
	}
	cout << "[ЗАВЕРШЕНИЕ ОБРАБОТКИ]\n\n";
	out.close();
	cout << "[ЗАКРЫТИЕ ФАЙЛА]\n";

}


int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		cout << "Введите символ в строке:\n";
		char c;
		cin >> c;

		vector<int> vec;
		vec = Count(FileSource, c);
		Result(FileOutput, vec);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

}