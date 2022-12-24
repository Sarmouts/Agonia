#pragma once
#include"Trapoulas.h"
#include<algorithm>
std::string previous = "";
bool compare(std::string a, std::string b)
{
	if (isalpha(a[0]))
		return 0;
	if (isalpha(b[0]))
		return 1;
	return a[0] > b[0];
}
int maxpos = 0;
std::string BestPossSol()
{
	int type[4] = { 0 };
	std::vector<std::string> sol;
	for (int i = 0; i < compTrap.size(); i++) {
		if (compTrap[i][compTrap[i].size() - 1] == Tablecard[Tablecard.size() - 1] && compTrap[i][0] != 'A')
			sol.push_back(compTrap[i]);
		if (compTrap[i][0] != 'A')
			type[compTrap[i][compTrap[i].size() - 1] - 3]++;
	}
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
	int a = 0;
	for (int i = 0; i < 4; i++) {
		if (type[i] > a)
		{
			maxpos = i;
			a = type[i];
		}
	}
	return asoi;
}
void MoveC(std::string card)
{
	int add = 0;
	if (card[0] == 'A')
	{
		previous = card;
		card = symbs[maxpos];
	}
	else if (card[0] == '8') add = 3;
	else if (card[0] == '7') add = 2;
	for (int i = 0; i < add; i++) {
		playerTrap.push_back(trapoula[trapoula.size() - 1]);
		trapoula.pop_back();
	}
	if (Tablecard.size() != 1) trapoula.push_back(Tablecard);
	else trapoula.push_back(previous);
	Tablecard = card;
}