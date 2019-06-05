#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector <int>> wall;
int MaxLen = 0;
bool Input()
{
	vector <int> a;
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
	int Sum=0;
	for (int i = 0; i < a.size(); i++)
		Sum += a[i];
	if (Sum > MaxLen)
		MaxLen = Sum;
	wall.push_back(a);
	if (str[str.length() - 1] == ']'&&str[str.length() - 2] == ']')
		return false;
	return true;
}
bool Gap(vector<int> x, int posi)
{
	int xlen = 0, i = 0;
	while (xlen < posi&&i<x.size())
	{
		xlen += x[i];
		i++;
	}
	if (i == x.size() && xlen < posi)  //该层不够长
		return true;
	if (xlen == posi)
		return true;
	else
		return false;
}
int main()
{
	while (Input());
	vector<int> through;
	for (int i = 0; i < MaxLen - 1; i++)
		through.push_back(wall.size());
	for (int i = 1; i < MaxLen; i++)   //遍历每道可能的缝
		for (int j = 0; j < wall.size(); j++)    //遍历每一层
		{
			if (Gap(wall[j], i))
				through[i-1]--;
		}
	int ans = 1000000;
	for (int i = 0; i < MaxLen - 1; i++)
		if (ans > through[i])
			ans = through[i];
	cout << ans;
	system("pause");
	return 0;
}