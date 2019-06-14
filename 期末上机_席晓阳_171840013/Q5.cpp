#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> ans;

int f(int x, int a, int b, int c)
{
	return a * x*x + b * x + c;
}

void mink(int a, int b,int c)
{
	int xmin = -(b / a / 2);
	if (f(xmin + 1, a, b, c) < f(xmin, a, b, c))
		xmin += 1;
	for (int i = xmin - k / 2 - 1; i <= xmin + k / 2 + 1; i++)
	{
		ans.push_back(f(i, a, b, c));
	}
}

int main()
{
	cin >> n >> k;
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		mink(a, b, c);
	}
	for (int i = 0; i < ans.size(); i++)
		for (int j = i + 1; j < ans.size(); j++)
		{
			if (ans[i] > ans[j])
			{
				int temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
			}
		}
	for (int i = 0; i < k; i++)
		cout << ans[i] << " ";
	system("pause");
	return 0;
}