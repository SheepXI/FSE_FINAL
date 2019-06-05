#include<iostream>
#include<string>
using namespace std;
string a, b;
int SameLen(int la,int lb)
{
	int len;
	if (la > lb)
	{
		len = la;
		for (int i = 0; i < la - lb; i++)
			b = "0" + b;
	}
	else if (lb > la)
	{
		len = lb;
		for (int i = 0; i < lb - la; i++)
			a = "0" + a;
	}
	else
		len = la;
	return len;
}
string add(string a, string b,int len)
{
	string ans;
	bool more=false;
	int x;
	for (int i = len - 1; i >= 0; i--)
	{
		if (more)  //上一次有进位
			x = a[i] - 48 + b[i] - 48 + 1;
		else
			x = a[i] - 48 + b[i] - 48;
		if (x >= 10)
		{
			more = true;
			x -= 10;
			char k = x + 48;
			ans = k + ans;
		}
		else
			more = false;
	}
	if (more)
		ans = "1" + ans;
	return ans;
}
int main()
{
	cin >> a >> b;
	int lena = a.length(), lenb = b.length();
	int len=SameLen(lena,lenb);
	string ans = add(a, b,len);
	cout << ans;
	system("pause");
	return 0;
}