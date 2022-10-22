#include <iostream>
using namespace std;

class employee
{
	static int Id;
	int m_id;
	string m_name;
	double m_salary;
public:

	employee()
	{
		m_id = Id++;
		m_name = { "Noname" };
		m_salary = 2345, 5;
	}
	int getId() const { return(m_id); }
	employee(string name, double salary = 0) :m_name(name), m_id(Id++), m_salary(salary) {}

	friend void print(employee& employee);
	~employee()
	{
	}
	void setEmployee(string name, double salary);
	friend class accountant;
};
int employee::Id = 1;
void employee::setEmployee(string name, double salary)
{
	name = m_name;
	salary = m_salary;
}
void print(employee& i)
{
	cout << "Name:" << i.m_name << "\nId: " << i.m_id << "\nSalary: " << i.m_salary << "$\n" << endl;
}
class accountant
{
	double m_newSalary;
public:

	void changeSalary(employee& emp)
	{
		cout << "Enter new salary for " << emp.m_name << endl;
		cin >> emp.m_salary;
		if (emp.m_salary < 0)
		{
			do
			{
				cout << "Return enter:\n" << endl;
				cin >> emp.m_salary;
			} while (emp.m_salary < 0);
		}
		cout << "After taxes:\n" << emp.m_salary - (emp.m_salary * 0.1) << "\n" << endl;
	}
};
int main()
{

	employee polufabricate("polufabricate");
	print(polufabricate);
	accountant a;
	a.changeSalary(polufabricate);

	employee one("Jhon Smith");
	print(one);
	accountant a1;
	a1.changeSalary(one);

	employee two("Rick Martin", 3002);
	print(two);
	accountant a2;
	a2.changeSalary(two);

	employee three("Roronoa Zoro", 3506);
	print(three);
	accountant a3;
	a3.changeSalary(three);

	const int size = 2;
	employee employeeArray[size] = {
	employee("Daniel Radcklif", 3456),
	employee("Martin Iden", 2907) };

	for (int i = 0; i < size; i++)
	{
		print(employeeArray[i]);
		accountant a;
		a.changeSalary(employeeArray[i]);
	}
	return 0;
}
