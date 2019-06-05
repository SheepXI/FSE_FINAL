#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Letter {
	int num = 0;
	char l;
};
vector <Letter> x;
bool exist(char a)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (a == x[i].l)
		{
			x[i].num++;
			return true;
		}
	}
	return false;
}
int main()
{
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (!exist(str[i]))
		{
			Letter b;
			b.l = str[i];
			b.num = 1;
			x.push_back(b);
		}
	}
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i].num == 1)
			cout << x[i].l;
		else if (x[i].num > 1)
			cout << x[i].num<< x[i].l;
	}
	system("pause");
	return 0;
}