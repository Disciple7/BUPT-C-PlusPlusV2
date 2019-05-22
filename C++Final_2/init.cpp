#include"mainfunc.h"

void wordList_init(vector<string>& wordList)
{
	string tmpString;
	fstream wordFile;
	if(DEV_MODE)
		wordFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\wordList.csv", ios::out | ios::in);
	else
		wordFile.open("wordList.csv", ios::out | ios::in);

	while(wordFile&&!(wordFile.peek()==EOF))//��wordFile���ڣ��Ҳ�Ϊ��βʱ�����ֱ��ʹ��wordFile.eof()��������һ�ж�ȡ���Ρ�
	{
		wordFile >> tmpString;
		wordList.push_back(tmpString);
	}
	sort(wordList.begin(), wordList.end(),string_cmp);
	wordFile.close();
}
void playerList_init(vector<player>& playerList)
{
	string tmpPlayerInfo;
	vector<string> tmpInfoList;
	fstream playerFile;
	if(DEV_MODE)
		playerFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\playerList.csv", ios::out | ios::in);
	else
		playerFile.open("playerList.csv", ios::out | ios::in);
	while (playerFile && !(playerFile.peek()==EOF))
	{
		playerFile >> tmpPlayerInfo;
		string_split(tmpPlayerInfo, tmpInfoList, ",");
		player tmpPlayer(tmpInfoList[0],tmpInfoList[1],stoi(tmpInfoList[2]),stoi(tmpInfoList[3]),stoi(tmpInfoList[4]));
		playerList.push_back(tmpPlayer);
		tmpInfoList.clear();
	}
	playerFile.close();
}
void testerList_init(vector<tester>& testerList)
{
	string tmpTesterInfo;
	vector<string> tmpInfoList;
	fstream testerFile;
	if(DEV_MODE)
		testerFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\testerList.csv", ios::out | ios::in);
	else
		testerFile.open("testerList.csv", ios::out | ios::in);

	while (testerFile && !(testerFile.peek()==EOF))
	{
		testerFile >> tmpTesterInfo;
		string_split(tmpTesterInfo, tmpInfoList, ",");
		tester tmpTester(tmpInfoList[0], tmpInfoList[1], stoi(tmpInfoList[2]), stoi(tmpInfoList[3]));
		testerList.push_back(tmpTester);
		tmpInfoList.clear();
	}
	testerFile.close();
}
void show_main_info()
{
	cout << "++++++++++++++++++++++++++++++" << endl;
	cout << "|      Word Remebering!      |" << endl;
	cout << "++++++++++++++++++++++++++++++" << endl;
	cout << "|   Press 1 to Regist        |" << endl;
	cout << "|   Press 2 to Login(Player) |" << endl;
	cout << "|   Press 3 to Login(Tester) |" << endl;
	cout << "|   Press 4 to Search People |" << endl;
	cout << "|   Press 0 to Quit          |" << endl;
	cout << "++++++++++++++++++++++++++++++" << endl;
}
