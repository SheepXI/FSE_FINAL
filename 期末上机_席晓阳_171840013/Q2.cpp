#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> A, B, C, D;
	int a, b, c, d;
	for (int i = 0; i < n; i++)  //输入
	{
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	vector<int> sumAB, sumCD;   //将AB和CD分别组合
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			sumAB.push_back(A[i] + B[j]);
			sumCD.push_back(C[i] + D[j]);
		}
	int ans = 0;
	for (int i = 0; i < n*n; i++)    //AB+CD=0
		for (int j = 0; j < n*n; j++)
		{
			if (sumAB[i] + sumCD[j] == 0)
				ans++;
		}
	cout << ans;
	system("pause");
	return 0;
}