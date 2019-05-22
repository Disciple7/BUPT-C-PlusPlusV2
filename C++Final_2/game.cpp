#include"mainfunc.h"
int state_game(vector<string>& wordList)//����ֵΪ������
{
	int rewards = 0;
	int round = 0;//�ڼ���
	int wordCount =5;
	int size = wordList.size();
	int round_time = 3000;
	int biasA = 0;
	int biasB = biasA + wordList.size() / 2;
	int bonus = 0;//ʱ�佱����ÿ����3��ʱ�佱�����Ի����һ��
	int health = 5;//����5������ֹ��Ϸ

	string targetWord;
	string myWord="\0";
	time_t timer;

	sort(wordList.begin(), wordList.end(), string_cmp);
	cout << "Game Start ! Type \":q\" to Quit !" << endl;
	while(myWord!=":q"&&health>0)
	{
		if (wordCount == 0)
		{
			round++;//ÿ��round+1�����ʡ����ֵ�����ɺ����ò�������һ�֡�
			wordCount = round+1;
			if (biasA < (size /3)*2)
			{
				biasA++;
				biasB = biasA + (size - biasA) / 2;
			}
			else
			{
				biasB = size - 1;//����ʱ��ȡ�����ʿ��1/3�ĵ���
			}
			round_time = round_time*size / (size + round);//round_time�𽥼���
			cout << "Next Round " << round << " ! " << wordCount << "word(s) left !" << endl;
		}
		targetWord = wordList[biasA+rand()%(biasB-biasA)];//�޶���ȡ��Χ��ȼ��仯
		cout << targetWord;
		Sleep(round_time);
		cout << "\r                   \r";//���һ�У����ѹ���Ƶ���ʼ��
		timer = time(NULL);
		cin >> myWord;
		if (targetWord == myWord)
		{
			wordCount--;
			timer = time(NULL) - timer;
			cout << "Correct !" << endl;
			if (timer < 3)
			{
				cout << "Fast Type! Bonus! " << endl;
				bonus++;
			}
		}
		else if(myWord !=":q")
		{
			cout << "Wrong !" << endl;
			health--;
		}
	}
	cout << "Your Best Round��" << round << endl;
	return round+bonus/3;
}
void flush_player(int nowUserPos, int bestRound, vector<player>& playerList)
{
	player nowPlayer = playerList[nowUserPos];
	nowPlayer.rewards(bestRound);	//���´��˵ľ��顢�ȼ����������

	for (vector<player>::iterator playerIter=playerList.begin(); playerIter!=playerList.end();)//����playerList
	{
		if (playerIter->get_name() == nowPlayer.get_name())
		{
			playerList.erase(playerIter);
			playerList.push_back(nowPlayer);
			break;
		}
		else
			playerIter++;
	}

	string tmpPlayerInfo;//����playerFile
	vector<string> tmpInfoList;
	fstream playerFile;
	if(DEV_MODE)
		playerFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\playerList.csv", ios::in | ios::out);
	else 
		playerFile.open("playerList.csv", ios::in | ios::out);

	if (!playerFile)
	{
		cout << "playerList.csv open failed! " << endl;
		abort();
	}
	playerFile.seekp(0);
	getline(playerFile, tmpPlayerInfo);//-�����������������������⣬tmpInfoList��û����վʹ���
	streamoff tmpFptr = playerFile.tellg();//��ÿ��ͷ����һ�е�ĩβ����һ����ַ�����������һ������Ϣ��Ҫ�޸ĵģ��ص����ͷ�����޸���Ϣ��
	while (playerFile && !(playerFile.peek()==EOF))
	{
		getline(playerFile, tmpPlayerInfo);//ȡ�ļ�һ�У������ֽ��user������
		string_split(tmpPlayerInfo, tmpInfoList, ",");
		if (tmpInfoList[0] == nowPlayer.get_name())
		{
			playerFile.seekp(tmpFptr);
			playerFile << nowPlayer.get_name() << "," << nowPlayer.get_password() << "," << nowPlayer.get_level() << "," << nowPlayer.get_exp() << "," << nowPlayer.get_best_round() << endl;
			break;
		}
		tmpInfoList.clear();//tmpInfoListҪ������Ϊstring_split�õ���push_back���������������
		tmpFptr = playerFile.tellg();
	}
	playerFile.close();
	return;
}
