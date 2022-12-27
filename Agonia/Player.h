#pragma once
#include"Trapoulas.h"
bool Check(std::string pcard)
{
	if (pcard[0] == 'A')
		return 1;
	else if (pcard[pcard.size() - 1] == Tablecard[Tablecard.size() - 1])
		return 1;
	else if (pcard.size() == Tablecard.size() && pcard[0] == Tablecard[0])
		return 1;
	return 0;
}
void Move(std::string pcard)
{
	int add = 0;
	if (pcard[0] == 'A')
	{
		int pos;
		std::cout << "Select(0-3) \3 \4 \5 \6: ";
		std::cin >> pos;
		prev = pcard;
		pcard = symbs[pos];
	}
	else if (pcard[0] == '8') add = 3;
	else if (pcard[0] == '7') add = 2;
	for (int i = 0; i < add; i++) {
		compTrap.push_back(trapoula[trapoula.size() - 1]);
		trapoula.pop_back();
	}
	if (Tablecard.size() != 1) trapoula.push_back(Tablecard);
	else trapoula.push_back(prev);
	Tablecard = pcard;
}