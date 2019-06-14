#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	char dele;
	cin >> dele;
	string str;
	cin >> str;
	vector<string> ans;
	while (str != "@")  // ‰»Î
	{
		string z = "";
		for (int i = 0; i < str.length(); i++)
			if (str[i] != dele)
				z += str[i];
		ans.push_back(z);
		cin >> str;
	}
	for(int i=0;i< ans.size();i++)          //≈≈–Ú
		for (int j = i + 1; j < ans.size(); j++)
		{
			if (ans[i] < ans[j])
			{
				string temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
			}
		}
	for (int i = 0; i < ans.size() - 1; i++)  // ‰≥ˆ
		cout << ans[i] << endl;
	cout << ans[ans.size() - 1];
	system("pause");
	return 0;
}