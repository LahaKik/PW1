#include "App.h"
#include <Windows.h>


using namespace std;

App::App()
{

}

int App::exec()
{
	Uint defaultSize = 3;
	Matrix matrix(defaultSize);
	int ch;
	while (true)
	{
		system("cls");
		ch = menu();
		switch (ch)
		{
		case 1:
			system("cls");
			{
				Uint size;
				cout << "Enter size of matix:";
				cin >> size;
				cout << endl << "Enter matrix's values:" << endl;
				Matrix tM = Matrix(size, getArrayValues(size));
				matrix = tM;
			}
			break;

		case 2:
			system("cls");
			cout << "Det = " << matrix.Determinant() << endl;
			system("pause");
			break;

		case 3:
			system("cls");
			matrix.SetTransposed();
			cout << "Transposed matrix:" << endl;
			matrix.Print();
			system("pause");
			break;

		case 4:
			system("cls");
			cout << "Rank = " << matrix.ComputeRank() << endl;
			system("pause");
			break;

		case 5:
			system("cls");
			matrix.Print();
			system("pause");
			break;

		case 9:
			return 0;

		default:
			break;
		}
	}

	return 0;
}

int App::menu()
{
	int ch;
	cout << "1 - Input matrix's values" << endl
		 << "2 - Calculate determinant" << endl
		 << "3 - Transpose the matrix" << endl
		 << "4 - Calculate rank" << endl
		 << "5 - Print matrix" << endl
		 << "9 - Exit" << endl;
	cin >> ch;
	return ch;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

number* App::getArrayValues(Uint size)
{

	number* tNum = new number[size*size];
	Uint cnt = 0;
	for (Uint i = 0; i < size; i++)
	{
		for (Uint j = 0; j < size; j++)
		{
			number t;
			gotoxy(j * 5, i * 2 + 3);
			cin >> t;
			cout << "\t";
			tNum[cnt] = t;
			cnt++;
		}
		cout << endl;
	}
	return tNum;
}
