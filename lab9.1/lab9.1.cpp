//Варіант 9.


#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці

using namespace std;
enum Group { COMPUTERSINCE, INFORMATIC, MATHANDECONOMIC, FISICSNDINFORMATIC, TUTISIONWORK };
string Namegrup[] = { "комп. науки","Інформатика","Мат. та економіка","Фізика та інф.","«Трудове навчання" };


struct student
{
	string prizv{};
	unsigned curs;
	Group group;
	int firstmark;
	int secondmark;
	union
	{
		int prog;
		int chmesod;
		int workjob;

	};
	

};
void Create(student* p, const int N);
void Print(student* p, const int N);
int count5(student* p, const int N);
int searchStudent(student* p, const int N);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

	student* p = new student[N];
	Create(p, N);
	Print(p, N);
	cout << "Кількість  оцінок <5>  - " << count5(p, N);
	cout << endl;
	cout << "Обчислити кількість студентів, які отримали з фізики і математики оцінки «5» " << searchStudent(p, N);
	cout << endl;

	return 0;
}
int searchStudent(student* p, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].firstmark == 5 && p[i].secondmark == 5)
		{
			count++;
		}
	}
	return count;
}
int count5(student* p, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].firstmark == 5 || p[i].secondmark == 5 || p[i].chmesod == 5 || p[i].workjob == 5 || p[i].prog == 5)
		{
			count++;
		}
	}
	return count;
}
void Create(student* p, const int N)
{
	int groupN;
	for (int i = 0; i < N; i++)
	{
		cout << "Працівник № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс "; cin >> p[i].curs;

		cout << " група (0 - компютерні науки, 1 - інформатика, 2 - математика і економіка, 3 - фізика і математика, 4 - трудове навчання): ";
		cin >> groupN;
		cout << " оцінка з фізики "; cin >> p[i].firstmark;
		cout << " оцінка з математики "; cin >> p[i].secondmark;
		p[i].group = (Group)groupN;
		switch (p[i].group)
		{
		case COMPUTERSINCE:
			cout << "оцінка з програмування"; cin >> p[i].prog;
			break;
		case INFORMATIC:
			cout << "оцінка з чисельних методів "; cin >> p[i].chmesod;

			break;
		case MATHANDECONOMIC:
		case FISICSNDINFORMATIC:
		case TUTISIONWORK:
			cout << "оцінка з педагогіки "; cin >> p[i].workjob;
			break;
		}
		cout << endl;
	}
}
void Print(student* p, const int N)
{
	cout << "=================================================================================="
		<< endl;
	cout << "| № | Прізвище       | Курс | група             | 1 оцінка | 2 оцінка | 3 оцінка |"
		<< endl;
	cout << "----------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].curs << " "
			<< "| " << setw(18) << left << Namegrup[p[i].group];
		switch (p[i].group)
		{
		case COMPUTERSINCE:
			cout << "| " << p[i].firstmark << "        |" << " " << p[i].secondmark << "        |" << p[i].secondmark << "         |";
			cout << endl;
			break;
		case INFORMATIC:
			cout << "| " << p[i].firstmark << "        |" << " " << p[i].secondmark << "        |" << p[i].chmesod << "         |";
			cout << endl;
			break;
		case MATHANDECONOMIC:
		case FISICSNDINFORMATIC:
		case TUTISIONWORK:
			cout << "| " << p[i].firstmark << "        |" << " " << p[i].secondmark << "        |" << p[i].workjob << "         |";
			cout << endl;
			break;
		}
	}
	cout << "=================================================================================="
		<< endl;
	cout << endl;
}