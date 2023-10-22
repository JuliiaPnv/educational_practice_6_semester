#include <iostream>
#include <cmath>

using namespace std;

enum States
{
	State_GRGR,
	State_GYYR_1,
	State_GGRR_1,
	State_GGRR_2,
	State_GYYR_2,
	State_YYRY_1,
	State_YRYY_1,
	State_RRRG_1,
	State_RRRG_2,
	State_YYRY_2,
	State_YRYY_2
};

States State_Switching(States state, int current)
{
	switch (state)
	{
	case State_GRGR:
		if (current == 0)
		{
			state = State_GRGR;
			cout << "<�, �, �, �>" << endl;
		}
		else if (current == 1 || current == 3)
		{
			state = State_GYYR_1;
			cout << "<�, �, �, �>" << endl;
			state = State_GGRR_1;
			cout << "<�, �, �, �>" << endl;
		}
		else if (current == 2)
		{
			state = State_YRYY_1;
			cout << "<�, �, �, �>" << endl;
			state = State_RRRG_1;
			cout << "<�, �, �, �>" << endl;
		}
		break;
	case State_GGRR_1:
		if (current == 0)
		{
			state = State_GYYR_2;
			cout << "<�, �, �, �>" << endl;
			state = State_GRGR;
			cout << "<�, �, �, �>" << endl;

		}
		else if (current == 2 || current == 3)
		{
			state = State_YYRY_1;
			cout << "<�, �, �, �>" << endl;
			state = State_RRRG_2;
			cout << "<�, �, �, �>" << endl;
		}
		else if (current == 1)
		{
			state = State_GGRR_2;
			cout << "<�, �, �, �>" << endl;
		}
		break;
	case State_GGRR_2:
		if (current == 0 || current == 1 || current == 2 || current == 3)
		{
			state = State_GYYR_2;
			cout << "<�, �, �, �>" << endl;
			state = State_GRGR;
			cout << "<�, �, �, �>" << endl;

		}
		break;
	case State_RRRG_2:
		if (current == 0 || current == 1 || current == 2 || current == 3)
		{
			state = State_YRYY_2;
			cout << "<�, �, �, �>" << endl;
			state = State_GRGR;
			cout << "<�, �, �, �>" << endl;
		}
		break;
	case State_RRRG_1:
		if (current == 0)
		{
			state = State_YRYY_2;
			cout << "<�, �, �, �>" << endl;
			state = State_GRGR;
			cout << "<�, �, �, �>" << endl;

		}
		else if (current == 1 || current == 3)
		{
			state = State_YYRY_2;
			cout << "<�, �, �, �>" << endl;
			state = State_GGRR_2;
			cout << "<�, �, �, �>" << endl;
		}
		else if (current == 2)
		{
			state = State_RRRG_2;
			cout << "<�, �, �, �>" << endl;
		}
		break;
	}
	return state;
}



int main() {
	setlocale(LC_ALL, "Rus");
	int N, i;
	while (1)
	{
		cout << "������� ���������� ��������������� ������� ��������� ����� �� ����� � ����\nN = ";
		cin >> N;
		int* cases{ new int[N] };
		cout << "\n������� ��������� ������:\n0 - �� ����� � ���� ��� �����\n1 - �� ����� ����� ������, �� ���� �����\n"
			"2 - �� ���� ����� ������, �� ����� �����\n3 - �� ����� � ���� ����� ������" << endl;
		for (i = 0; i < N; i++)
		{
			cin >> cases[i];
			while (1)
			{
				if (cases[i] < 0 || cases[i] > 3)
				{
					cout << "������ ������ ���, ���������� ��� ���\n0 - �� ����� � ���� ��� �����\n1 - �� ����� ����� ������, �� ���� �����\n"
						"2 - �� ���� ����� ������, �� ����� �����\n3 - �� ����� � ���� ����� ������" << endl;
					cin >> cases[i];
				}
				else
					break;
			}
		}
		cout << "\n������������������ ��������� �����:" << endl;
		for (int i = 0; i < N; i++)
		{
			if (cases[i] == 0)
				cout << "<0, 0>  ";
			else if (cases[i] == 1)
				cout << "<1, 0>  ";
			
			else if (cases[i] == 2)
				cout << "<0, 1>  ";
			else if (cases[i] == 3)
				cout << "<1, 1>  ";
		}

		cout << "\n\n��������� ��������� ���������:\n<�, �, �, �>\n" << endl;

		States state = State_GRGR;
		for (int i = 0; i < N; ++i)
		{
			const int current = cases[i];
			state = State_Switching(state, current);
		}

		int k;
		cout << "\n��������� ��������� ��� ���? (1 - ��, 0 - ���)" << endl;
		cin >> k;
		while (1)
		{
			if (k == 0)
			{
				delete[] cases;
				cases = nullptr;
				break;
			}
			else if (k == 1)
			{
				delete[] cases;
				cases = nullptr;
				cout << "\n";
				break;
			}
			else
			{
				cout << "����� ������� �� ����������, ���������� ��� ���" << endl;
				cin >> k;
			}
		}
		if (k == 0)
			break;
	}
}