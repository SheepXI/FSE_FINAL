#include<iostream>
#include<vector>
#include<string>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
	int uniquePathsIII(vector<vector<int>>& grid)
	{
		int i1 = 0, j1 = 0, t_steps = 1;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1) i1 = i, j1 = j;
				if (grid[i][j] == 0) ++t_steps;
			}
		}
		return dfs(grid, i1, j1, t_steps);
	}
private:
	int dfs(vector<vector<int>>& g, int i, int j, int s)
	{
		if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
		if (g[i][j] == 2) return s == 0 ? 1 : 0;
		g[i][j] = -1;
		int paths = dfs(g, i + 1, j, s - 1) + dfs(g, i - 1, j, s - 1) +
			dfs(g, i, j + 1, s - 1) + dfs(g, i, j - 1, s - 1);
		g[i][j] = 0;
		return paths;
	}
};
void Input(vector<vector<int>>& g)
{
	vector <int> a;
	string str;
	cin >> str;
	for (int i = 0; i < str.length()-1; i++)
	{
		while (i < str.length()-1&&(str[i] >= '0'&&str[i] <= '2'))
		{
			if (str[i - 1] == '-')
				a.push_back(-1);
			else if(str[i]=='0')
				a.push_back(0);
			else if(str[i] == '1')
				a.push_back(1);
			else
				a.push_back(2);
			i++;
		}
		if (i < str.length()-1&&str[i] == ']')
		{
			g.push_back(a);
			a.clear();
		}
		if (i == str.length() - 2)
			return;
	}
	return;
}
int main()
{
	vector<vector<int>> grid;
	Input(grid);
	Solution S;
	int ans=S.uniquePathsIII(grid);
	cout << ans;
	system("pause");
	return 0;
}
