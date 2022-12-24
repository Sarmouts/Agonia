/*#include"Trapoulas.h"
#include"Computer.h"
#include<algorithm>
int main()
{
	Tablecard = "5\3";
	compTrap = { "A\3","5\3" ,"8\3" ,"7\3" ,"9\3" ,"A\4" ,"5\3" };
	while (!compTrap.empty())
	{
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
		//	NowPlaying -= 1;
		//if (res[0] == '9') NowPlaying -= 1;
	}
}*/