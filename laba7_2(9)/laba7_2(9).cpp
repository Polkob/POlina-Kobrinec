#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>

#define FNAME "Student.txt"
#define FNAMEbin "Student.bin"

#define FILE_OPEN_ERROR "Error open file"
#define STRING_LENGTH 20

using namespace std;

bool BinaryFlag = 0;
bool File = 0;

class Student {
public:
	string m_name;
	string m_university;
	string m_age;

	Student() {}
	Student(string _name, string _uni, string _age) {
		m_name = _name;
		m_university = _uni;
		m_age = _age;
	}
	~Student() {}

	void Info() {
		cout << "My name is " << m_name << endl;
		cout << "I'm study in " << m_university;
	}
};

class AllStudents
{
public:
	vector<Student> student;

	AllStudents() {}
	
	void LoadFile() {
		try {
			ifstream inf(FNAME);

			if (inf.bad() || !inf.is_open()) {
				inf.close();

				throw FILE_OPEN_ERROR;
			}

			student.clear();

			while (!inf.eof()) {
				Student t;
				if (!getline(inf, t.m_name) ||
					!getline(inf, t.m_university) ||
					!getline(inf, t.m_age))
					break;

				student.push_back(t);
			}

			inf.close();
			
		}
		catch (string e) {
			cout << e;
			
		}
	}

	void LoadTextFileBinary()
	{
		student.clear();
		ifstream inf;
		Student st;

		inf.open(FNAME, ios::binary);

		while (getline(inf, st.m_name,'\r')) {
			if (inf.eof())
				break;

			inf.get();
			getline(inf, st.m_university, '\r');

			inf.get();
			getline(inf, st.m_age, '\r');

			inf.get();

			student.push_back(st);
		}
		inf.close();
	}

	void LoadBinary() {
		student.clear();
		ifstream inf;
		Student st;

		inf.open(FNAMEbin , ios::binary);

		while (getline(inf, st.m_name,'\n')) {
			if (inf.eof())
				break;
		
			getline(inf, st.m_university,'\n');

			getline(inf, st.m_age,'\n');


			student.push_back(st);
			
		}
		inf.close();

	}

	void ReadRecord(int index = -1) {

		if (index == -1) {
			cout << "\nВсего " << student.size() << " записей:" << endl << endl;

			for (int i = 0; i < student.size(); i++) {
				cout << i + 1 << ". "
					<< student[i].m_name << "  "
					<< student[i].m_university << "  "
					<< student[i].m_age << endl;
			}
		}
		else {
			cout << index + 1 << ". "
				<< student[index].m_name << "  "
				<< student[index].m_university << "  "
				<< student[index].m_age << endl;
		}
	}

	void Add() {
		Student tmp;

		cout << "\n\n\t\t[ Добавление новой записи ]\n\n";

		cout << "Введите имя студента: ";
		cin >> tmp.m_name;

		cout << "Введите университет, в котором учится студент: ";
		cin >> tmp.m_university;

		cout << "Введите возраст студента: " << endl;
		cin >> tmp.m_age;

		student.push_back(tmp);
		cout << "Новая запись с порядковым номером "
			<< student.size() << " добавлена!" << endl << endl;
		cin.get();

		
			try {
				ofstream outf( FNAME);

				if (outf.bad() || !outf.is_open()) {
					outf.close();
					throw FILE_OPEN_ERROR;
				}

				outf.write(tmp.m_name.c_str(), tmp.m_name.size());
				outf.write("\n", 1);
				outf.write(tmp.m_university.c_str(), tmp.m_university.size());
				outf.write("\n", 1);
				outf.write(tmp.m_age.c_str(), tmp.m_age.size());
				outf.write("\n", 1);

				outf.close();
			}
			catch (string e) {
				cout << e;
			}
		

		this->saveToFile();
	}

	void saveToFile() {
		try {
			ofstream fout(FNAME);

			if (fout.bad() || !fout.is_open())
			{
				throw FILE_OPEN_ERROR;
				fout.close();
			}

			for (int i = 0; i < student.size(); i++)
			{
				fout << student[i].m_name << endl
					<< student[i].m_university << endl
					<< student[i].m_age << endl;
			}

			fout.close();
			
		}
		catch (string e) {
			cout << e;
			
		}
	}

	void AddBinary() {
		Student tmp;

		cout << "\n\n\t\t[ Добавление новой записи ]\n\n";

		cout << "Введите имя студента: ";
		cin >> tmp.m_name;

		cout << "Введите университет, в котором учится студент: ";
		cin >> tmp.m_university;

		cout << "Введите возраст студента: " << endl;
		cin >> tmp.m_age;

		student.push_back(tmp);
		cout << "Новая запись с порядковым номером "
			<< student.size() << " добавлена!" << endl << endl;
		cin.get();


		try {
			ofstream outf(FNAMEbin,ios::binary | ios::app);

			if (outf.bad() || !outf.is_open()) {
				outf.close();
				throw FILE_OPEN_ERROR;
			}

			outf.write(tmp.m_name.c_str(), tmp.m_name.size());
			outf.write("\n", 1);
			outf.write(tmp.m_university.c_str(), tmp.m_university.size());
			outf.write("\n", 1);
			outf.write(tmp.m_age.c_str(), tmp.m_age.size());
			outf.write("\n", 1);

			outf.close();
		}
		catch (string e) {
			cout << e;
		}


		this->saveToFileBinary();
	}


	void saveToFileBinary() {
		try {
			ofstream outf(FNAMEbin, ios::binary | ios::trunc); // open and clear file
			outf.close();

			outf.open(FNAMEbin, ios::binary | ios::app);

			if (outf.bad() || !outf.is_open()) {
				outf.close();

				throw FILE_OPEN_ERROR;
			}

			for (int i = 0; i < student.size(); i++)
			{
				outf.write(student[i].m_name.c_str(), student[i].m_name.size());
				outf.write("\n", 1);
				outf.write(student[i].m_university.c_str(), student[i].m_university.size());
				outf.write("\n", 1);
				outf.write(student[i].m_age.c_str(), student[i].m_age.size());
				outf.write("\n", 1);
			}

			outf.close();
			
		}
		catch (string e) {
			cout << e;	
		}
	}

	void AddTextFileBinary() {
		Student tmp;

		cout << "\n\n\t\t[ Добавление новой записи ]\n\n";

		cout << "Введите имя студента: ";
		cin >> tmp.m_name;

		cout << "Введите университет, в котором учится студент: ";
		cin >> tmp.m_university;

		cout << "Введите возраст студента: " << endl;
		cin >> tmp.m_age;

		student.push_back(tmp);
		cout << "Новая запись с порядковым номером "
			<< student.size() << " добавлена!" << endl << endl;
		cin.get();

			try {
				ofstream outf(FNAME, ios::binary | ios::app);

				if (outf.bad() || !outf.is_open()) {
					outf.close();
					throw FILE_OPEN_ERROR;
				}

				outf.write(tmp.m_name.c_str(), tmp.m_name.size());
				outf.write("\n", 1);
				outf.write(tmp.m_university.c_str(), tmp.m_university.size());
				outf.write("\n", 1);
				outf.write(tmp.m_age.c_str(), tmp.m_age.size());
				outf.write("\n", 1);

				outf.close();
			}
			catch (string e) {
				cout << e;
			}
		
		this->saveToTextFileBinary();
	}
	void saveToTextFileBinary() {
		try {
			ofstream outf(FNAME, ios::binary, ios::trunc); // open and clear file
			outf.close();

			outf.open(FNAME, ios::binary | ios::app);

			if (outf.bad() || !outf.is_open()) {
				outf.close();

				throw FILE_OPEN_ERROR;
			}

			for (int i = 0; i < student.size(); i++)
			{
				outf.write(student[i].m_name.c_str(), student[i].m_name.size());
				outf.write("\n", 1);
				outf.write(student[i].m_university.c_str(), student[i].m_university.size());
				outf.write("\n", 1);
				outf.write(student[i].m_age.c_str(), student[i].m_age.size());
				outf.write("\n", 1);
			}

			outf.close();

		}
		catch (string e) {
			cout << e;
		}
	}

	void Delete() {
		cout << "\n\n\t\t[ Удаление записи ]\n\n";

		char ans = 'n';
		int id = this->Find();

		if (id == -1)
		{
			cout << "Удаление не удалось!" << endl;
			return;
		}

		cout << endl;
		
			student.erase(student.begin() + id);
			cout << "Запись с порядковым номером "
				<< id + 1 << " удалена!" << endl << endl;
			cin.get();

		    this->saveToFile();
	}

	void DeleteBinary() {
		cout << "\n\n\t\t[Удаление записи]\n\n";

		char ans = 'n';
		int id = this->Find();

		if (id == -1)
		{
			cout << "Удаление не удалось!" << endl;
			return;
		}

		cout << endl;

		student.erase(student.begin() + id);
		cout << "Запись с порядковым номером "
			<< id + 1 << " удалена!" << endl << endl;
		cin.get();

		this->saveToFileBinary();
	}

	int Find() {
		int sel;

		cout << "Вам нужно найти запись:" << endl
			<< "1. По порядковому номеру" << endl
			<< "2. По имени" << endl
			<< "\n\n > ";

		cin >> sel;
		cout << endl;

		if (sel == 2) {
			string val;

			bool isFind = false;

			while (!isFind) {
				cout << "Введите значение для поиска: ";
				cin.clear();
				rewind(stdin);
				getline(cin, val);

				for (int i = 0; i < student.size(); i++) {
					if (student[i].m_name == val) {
						isFind = true;
						this->ReadRecord(i);
						return i;
					}
				}
				!isFind && cout << endl << "Студент не найден. Повторите попытку." << endl << endl;
			}

			cout << endl;
		}

		int number;
		bool fail = false;

		cout << "Введите порядковый номер записи: ";
		cin >> number;

		if (number < 1 || number > student.size()) {
			cout << "\n Записи с таким порядковым номером не существует\n" << endl;
			return -1;
		}
		else this->ReadRecord(number - 1);

		return number - 1;
	}

	int ReadReverse() {
		cout << "\nРеверсивный вывод:\n" << endl;
		for (int i = student.size() - 1; i >= 0; i--) {
			cout << i + 1 << ". "
				<< student[i].m_name << "  "
				<< student[i].m_university << "  "
				<< student[i].m_age << endl;
		}

		return 1;
	}
};

int main()
{
	system("chcp 1251");
	system("cls");

	AllStudents Full;

	cout << "\tРабота с текстовым файлом\n" << endl;
	Full.LoadFile();
	Full.ReadRecord();
	Full.Add();
	Full.ReadRecord();
	Full.Delete();
	Full.ReadRecord();
	Full.ReadReverse();
	

	cout << "\n\tРабота с бинарным файлом\n" << endl;
	Full.LoadBinary();
	Full.ReadRecord();
	Full.AddBinary();            
	Full.ReadRecord();
	Full.DeleteBinary();
	Full.ReadRecord();
	Full.ReadReverse();
	

	cout << "\n\tРабота с текстовым файлом в бинарном режиме\n" << endl;
	Full.LoadTextFileBinary();
	Full.ReadRecord();
	Full.AddTextFileBinary();
	Full.ReadRecord();
	Full.Delete();
	Full.ReadRecord();
	Full.ReadReverse();


	return 0;
}