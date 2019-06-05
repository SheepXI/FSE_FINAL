#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector <int> a;
bool Increase(vector<int> a)
{
	for (int i = 0; i < a.size() - 1; i++)
		if (a[i] > a[i + 1])
			return false;
	return true;
}
bool Decrease(vector<int> a)
{
	for (int i = 0; i < a.size() - 1; i++)
		if (a[i] < a[i + 1])
			return false;
	return true;
}
void Input()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		int x = 0;
		while (str[i] >= '0'&&str[i] <= '9'&&i < str.length())
		{
			x = x * 10 + str[i] - 48;
			i++;
		}
		if (x != 0)
			a.push_back(x);
	}
}
void Cal()
{
	int ans = 0;
	int Pbuy, Psell;
	for (int i = 0; i < a.size() - 1; i++)
	{
		Pbuy = a[i];
		while ((a[i] > a[i + 1]) && i < a.size() - 1)
		{
			i++;
			Pbuy = a[i];
		}
		Psell = a[i];
		while ((a[i] < a[i + 1]) && i < a.size() - 1)
		{
			i++;
			Psell = a[i];
		}
		ans += Psell - Pbuy;
		if (i == a.size() - 1)
			break;
	}
	cout << ans;
}
int main()
{
	Input();
	if (Increase(a))
		cout << a[a.size() - 1] - a[0];
	else if (Decrease(a))
		cout << 0;
	else Cal();
	system("pause");
	return 0;
}