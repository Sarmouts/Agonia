#include"Player.h"
#include"Computer.h"
#include"Trapoulas.h"
void stirTrapoula()
{
	std::vector<std::string> temp;
	srand(time(0));
	while (!trapoula.empty())
	{
		int i = rand() % trapoula.size();
		temp.push_back(trapoula[i]);
		trapoula[i] = trapoula[trapoula.size() - 1];
		trapoula.pop_back();
	}
	trapoula = temp;
}
void Init(std::vector<std::string>* a, std::vector<std::string>* b)
{
	bool j = 1;
	for (int i = 0; i < 14; i++, j -= 1)
	{
		if (j)
			(*a).push_back(trapoula[trapoula.size() - 1]);
		else
			(*b).push_back(trapoula[trapoula.size() - 1]);
		trapoula.pop_back();
	}
}
void PrintTrap(std::vector<std::string> v)
{
	for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
	std::cout << "\n";
}
int main()
{
	stirTrapoula();//Anakatema Trapoulas
	Init(&playerTrap, &compTrap);//Moirasma
	Tablecard = trapoula[37];//Fillo sto trapezi
	trapoula.pop_back();
	bool NowPlaying = 1;
	while (!playerTrap.empty() && !compTrap.empty())
	{
		if (NowPlaying)
		{
			std::cout << "Table Card: |" << Tablecard << "|\n\n";
			std::cout << "Your trapoula: ";
			PrintTrap(playerTrap);
			std::cout << "Enter position(0->6*) of the card you want and -1 if you cant use any: ";
			int pos;
			std::cin >> pos;
			if (pos == -1) {
				NowPlaying -= 1;
				playerTrap.push_back(trapoula[trapoula.size() - 1]);
				trapoula.pop_back();
				continue;
			}
			else if (!Check(playerTrap[pos])) {
				std::cout << "\nThis Card cannot be used!!!\n";
				system("pause");
				continue;
			}
			Move(playerTrap[pos]);
			NowPlaying -= 1;
			if (!Tablecard[0] == '9') NowPlaying -= 1;
			playerTrap[pos] = playerTrap[playerTrap.size() - 1];
			playerTrap.pop_back();
			system("pause");
		}
		else {
			std::string res = BestPossSol();
			if (res == "")
			{
				compTrap.push_back(trapoula[trapoula.size() - 1]);
				trapoula.pop_back();
			}
			else {
				MoveC(res);
				auto it = std::find(compTrap.begin(), compTrap.end(), res);
				compTrap[it - compTrap.begin()] = compTrap[compTrap.size() - 1];
				compTrap.pop_back();
			}
			NowPlaying -= 1;
			if (res[0] == '9') NowPlaying -= 1;
		}
		stirTrapoula();
	}
	if (playerTrap.empty())
		std::cout << "Congrats!!! You have won!!!";
	else
		std::cout << "(: Sorry, you have been defeated... Try again! ;)";
}
//A2345678910KJQ
//\3 \4 \5 \6