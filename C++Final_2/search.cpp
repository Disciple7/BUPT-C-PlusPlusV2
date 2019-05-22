#include"mainfunc.h"

void state_query( vector<player>& playerList,  vector<tester>& testerList)//��ѯ״̬�����Ը��ݸ���������ѯ�������ƣ��ȼ������͡�
{
	int order=1;
	string userName="\0";
	while (order != 0)
	{
		cout << "Qurey mode : Please input your order.\n(1)Show All Player Rank\n(2)Show All Tester Rank\n(3)Search Certain User\n(0)Quit" << endl;
		cin >> order;
		switch (order)
		{
		case 1:
		{
			cout << "Switch mode (default : by Name) :\n(1)Rank by Name\n(2)Rank by Level\n(3)Rank by Best Round" << endl;
			cin >> order;
			if(order==3)
				sort(playerList.begin(), playerList.end(), player_best_round_cmp);
			else if (order == 2)
				sort(playerList.begin(), playerList.end(), player_level_cmp);
			else
				sort(playerList.begin(), playerList.end(), player_name_cmp);
			cout << "Name\t\t\tLevel\tBestRound\tExp" << endl;
			for (unsigned int i = 0; i < playerList.size(); i++)//setw�������������ַ���
			{
				cout  << playerList[i].get_name() << "\t\t\t" << playerList[i].get_level() << "\t" << playerList[i].get_best_round() << "\t\t" << playerList[i].get_exp() << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Switch mode (default : by Name) :\n(1)Rank by Name\n(2)Rank by Level\n(3)Rank by Problem Num" << endl;
			cin >> order;
			if (order == 3)
				sort(testerList.begin(), testerList.end(), tester_problem_num_cmp);
			else if (order == 2)
				sort(testerList.begin(), testerList.end(), tester_level_cmp);
			else 
				sort(testerList.begin(), testerList.end(), tester_name_cmp);
			cout << "Name\t\t\tLevel\tProblemNum" << endl;
			for (unsigned int i = 0; i < testerList.size(); i++)
			{
				cout << testerList[i].get_name() << "\t\t\t" << testerList[i].get_level() << "\t" << testerList[i].get_problem_num() << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Type username you want to search : " << endl;
			cin >> userName;
			vector<player>::iterator playerIter = playerList.begin();
			for (; playerIter != playerList.end(); playerIter++)
			{
				if (playerIter->get_name() == userName)
				{
					cout<<"PlayerInfo:\nName\t\t\tLevel\tBestRound\tExp" << endl;
					cout   <<playerIter->get_name() << "\t\t\t" << playerIter->get_level() << "\t" << playerIter->get_best_round() << "\t\t" << playerIter->get_exp() << endl;
					break;
				}
			}
			vector<tester>::iterator testerIter = testerList.begin();
			for (; testerIter != testerList.end(); testerIter++)
			{
				if (testerIter->get_name() == userName)
				{
					cout << "testerInfo:\nName\t\t\tLevel\tProblemNum" << endl;
					cout  << testerIter->get_name() << "\t\t\t" << testerIter->get_level() << "\t" << testerIter->get_problem_num() << endl;
					break;
				}
			}
			if (playerIter == playerList.end() && testerIter == testerList.end())
				cout << "This user does not exist." << endl;
			break;
		}
		default:
			break;
		}
		if (order != 0)
		{
			order = 4;
			userName = "\0";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
	return;
}


bool string_cmp(string&x,  string&y)
{
	return x.length() > y.length();
}
//������򷽷�
bool player_name_cmp(player&p1, player&p2)//����������
{
	return p1.get_name() < p2.get_name();
}
bool player_level_cmp(player& p1, player&p2)//���ȼ�����
{
	return p1.get_level() > p2.get_level();
}
bool player_best_round_cmp(player& p1, player&p2)//����óɼ�����
{
	return p1.get_best_round() > p2.get_best_round();
}
//���������򷽷�
bool tester_name_cmp(tester&p1, tester&p2)//����������
{
	return p1.get_name() < p2.get_name();
}
bool tester_level_cmp(tester&p1, tester&p2)//���ȼ�����
{
	return p1.get_level() > p2.get_level();
}
bool tester_problem_num_cmp(tester&p1, tester&p2)//������������
{
	return p1.get_problem_num() > p2.get_problem_num();
}

void string_split( std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}
