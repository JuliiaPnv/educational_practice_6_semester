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
			cout << "<З, К, З, К>" << endl;
		}
		else if (current == 1 || current == 3)
		{
			state = State_GYYR_1;
			cout << "<З, Ж, Ж, К>" << endl;
			state = State_GGRR_1;
			cout << "<З, З, К, К>" << endl;
		}
		else if (current == 2)
		{
			state = State_YRYY_1;
			cout << "<Ж, К, Ж, Ж>" << endl;
			state = State_RRRG_1;
			cout << "<К, К, К, З>" << endl;
		}
		break;
	case State_GGRR_1:
		if (current == 0)
		{
			state = State_GYYR_2;
			cout << "<З, Ж, Ж, К>" << endl;
			state = State_GRGR;
			cout << "<З, К, З, К>" << endl;

		}
		else if (current == 2 || current == 3)
		{
			state = State_YYRY_1;
			cout << "<Ж, Ж, К, Ж>" << endl;
			state = State_RRRG_2;
			cout << "<К, К, К, З>" << endl;
		}
		else if (current == 1)
		{
			state = State_GGRR_2;
			cout << "<З, З, К, К>" << endl;
		}
		break;
	case State_GGRR_2:
		if (current == 0 || current == 1 || current == 2 || current == 3)
		{
			state = State_GYYR_2;
			cout << "<З, Ж, Ж, К>" << endl;
			state = State_GRGR;
			cout << "<З, К, З, К>" << endl;

		}
		break;
	case State_RRRG_2:
		if (current == 0 || current == 1 || current == 2 || current == 3)
		{
			state = State_YRYY_2;
			cout << "<Ж, К, Ж, Ж>" << endl;
			state = State_GRGR;
			cout << "<З, К, З, К>" << endl;
		}
		break;
	case State_RRRG_1:
		if (current == 0)
		{
			state = State_YRYY_2;
			cout << "<Ж, К, Ж, Ж>" << endl;
			state = State_GRGR;
			cout << "<З, К, З, К>" << endl;

		}
		else if (current == 1 || current == 3)
		{
			state = State_YYRY_2;
			cout << "<Ж, Ж, К, Ж>" << endl;
			state = State_GGRR_2;
			cout << "<З, З, К, К>" << endl;
		}
		else if (current == 2)
		{
			state = State_RRRG_2;
			cout << "<К, К, К, З>" << endl;
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
		cout << "Введите количество рассматриваемых случаев появления машин на альфа и бета\nN = ";
		cin >> N;
		int* cases{ new int[N] };
		cout << "\nВведите возможные случаи:\n0 - на альфа и бета нет машин\n1 - на альфа стоит машина, на бета пусто\n"
			"2 - на бета стоит машина, на альфа пусто\n3 - на альфа и бета стоят машины" << endl;
		for (i = 0; i < N; i++)
		{
			cin >> cases[i];
			while (1)
			{
				if (cases[i] < 0 || cases[i] > 3)
				{
					cout << "Такого случая нет, попробуйте ещё раз\n0 - на альфа и бета нет машин\n1 - на альфа стоит машина, на бета пусто\n"
						"2 - на бета стоит машина, на альфа пусто\n3 - на альфа и бета стоят машины" << endl;
					cin >> cases[i];
				}
				else
					break;
			}
		}
		cout << "\nПоследовательность появления машин:" << endl;
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

		cout << "\n\nНачальное состояние светофора:\n<З, К, З, К>\n" << endl;

		States state = State_GRGR;
		for (int i = 0; i < N; ++i)
		{
			const int current = cases[i];
			state = State_Switching(state, current);
		}

		int k;
		cout << "\nЗапустить программу ещё раз? (1 - да, 0 - нет)" << endl;
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
				cout << "Такой команды не существует, попробуйте ещё раз" << endl;
				cin >> k;
			}
		}
		if (k == 0)
			break;
	}
}