/*#include"Trapoulas.h"
#include<algorithm>
bool compare(std::string a, std::string b)
{
	if (isalpha(a[0]))
		return 0;
	if (isalpha(b[0]))
		return 1;
	return a[0] > b[0];
}
std::string BestPossSol()
{
	std::vector<std::string> sol;
	int type[4] = { 0 };
	for (int i = 0; i < compTrap.size(); type[compTrap[i][compTrap[i].size() - 1] - 3]++, i++)
		if (compTrap[i][compTrap[i].size() - 1] == Tablecard[Tablecard.size() - 1])
			sol.push_back(compTrap[i]);
	std::sort(sol.begin(), sol.end(), compare);
	if (!sol.empty())
		return sol[0];
	std::string res = "";
	std::string asoi = "";
	int max = 0;
	for (int i = 0; i < compTrap.size(); i++)
	{
		if (compTrap[i].size() == Tablecard.size() && compTrap[i][0] == Tablecard[0])
			if (type[compTrap[i][compTrap[i].size() - 1] - 3] > max)
			{
				max = type[compTrap[i][compTrap[i].size() - 1] - 3];
				res = compTrap[i];
			}
		if (compTrap[i][0] == 'A')
			asoi = compTrap[i];
	}
	if (res != "")
		return res;
	else
		return asoi;
}
int main()
{
	std::cout << BestPossSol();
}*/