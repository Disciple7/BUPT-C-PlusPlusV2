#include"mainfunc.h"

void state_register(vector<player>& playerList, vector<tester>& testerList)
{
	cout << "\nPlease choose your user type (default : quit):\n(1)player\n(2)tester" << endl;
	int type_choice = 0;
	cin >> type_choice;	
	if (cin.fail())//����Ƿ�ʱ
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');//������뻺�����ĵ�ǰ�� 
	}
	if (type_choice == 1)
	{
		cout << "type : player\n" << endl;
		type_choice = 1;
	}
	else if (type_choice == 2)
	{
		cout << "type : tester\n" << endl;
		type_choice = 2;
	}
	else
		return;
	cout << "Please set your username:" << endl;
	string name;
	cin >> name;
	if (name == "\0")//�����ʱ���Զ�����Ĭ���û���������
	{
		cout << "Default : Player_" << playerList.size() << endl;
		name = "Player_" + to_string(playerList.size());
	}
	cout << "Please set your account password:" << endl;
	string password;
	cin >> password;
	if (password == "\0")
	{
		cout << "Default : player" << playerList.size() << endl;
		password = "player" + to_string(playerList.size());
	}
	if (type_choice == 1)
	{
		player newPlayer(name, password);
		for (int i = 0; i < (int)playerList.size(); i++)
		{
			if (playerList[i].get_name() == newPlayer.get_name())
			{
				cout << "The Player-Name has been registered. Register failed!" << endl;
				return;
			}
		}
		fstream playerFile;
		if (DEV_MODE)
			playerFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\playerList.csv", ios::out | ios::app);
		else
			playerFile.open("playerList.csv");
		if (!playerFile)
		{
			cout << "playerList.csv open failed! " << endl;
			abort();
		}
		playerFile <<"\n"<< newPlayer.get_name() << "," << newPlayer.get_password() << ",0,0,0";//����д��ǰ�档д�������ᵼ�¶����Ρ�
		playerFile.close();
		playerList.push_back(newPlayer);
		cout << "Player successfully registers!" << endl;
	}
	else
	{
		tester newTester(name, password);
		for (int i = 0; i < (int)testerList.size(); i++)
		{
			if (testerList[i].get_name() == newTester.get_name())
			{
				cout << "The Tester-Name has been registered. Register failed!" << endl;
				return;
			}
		}
		fstream testerFile;
		if (DEV_MODE)
			testerFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\testerList.csv", ios::out | ios::app);
		else
			testerFile.open("testerFile.csv");
		if (!testerFile)
		{
			cout << "testerList.csv open failed! " << endl;
			abort();
		}
		testerFile << "\n" << newTester.get_name() << "," << newTester.get_password() << ",0,0";
		testerFile.close();
		testerList.push_back(newTester);
		cout << "Tester successfully registers!" << endl;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');//������뻺�����ĵ�ǰ�� 
}

