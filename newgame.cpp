#include <iostream>
#include <cstdio>
#include <conio.h>
#include <string>
using namespace std;

int scale = 3;
class Charector
{
  public:
	int x = 0;
	int y = 0;
	string human[3] = {{" 0"}, {"/|\\"}, {"/ \\"}};
	int pool= 50;
	void ChangeX(int d);
	void ChangeY(int d);
	void PrintHuman();
};
int main(int argc, char *argv[])
{
	char c;
	Charector pers;
	pers.PrintHuman();
	while ((c = getch()) != ' ')
	{
		system("cls");
		switch (c)
		{
		case 'D':
		case 'd':
			pers.ChangeX(1);
			break;
		case 'A':
		case 'a':
			pers.ChangeX(-1);
			break;
		case 'W':
		case 'w':
			pers.ChangeY(-1);
			break;
		case 'S':
		case 's':
			pers.ChangeY(1);
			break;
		}
		system("cls");
		pers.PrintHuman();
	}
	return 0;
}

void Charector ::ChangeX(int d)
{
	x += (((x + d) < 0) || ((x + d) > pool -5)) ? 0 : d;
}

void Charector ::ChangeY(int d)
{
	y +=  (((y+ d) < 0) || ((y + d) > (pool / scale - 4))) ? 0 : d;
}

void Charector ::PrintHuman()
{
		system("cls");
	string s = string(x, ' ');
	cout <<string(pool, '-') << endl;
	for (int i = 0; i < pool - (pool -y); i++)
	{
		cout << '#' << string(pool - 2, ' ') << "#\n";
	}
	for (int i = 0; i < 3; i++)
	{
		cout <<'#'+ s + human[i] + string(pool - x - 2 - human[i].size(), ' ') + "#\n";
	}
		for (int i = y + 4; i < (pool/ scale ); i++)
	{
		cout << '#' << string(pool - 2, ' ') << "#\n";
	}
		cout <<string(pool, '-') << endl;
}