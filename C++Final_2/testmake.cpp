#include"mainfunc.h"

int state_testmake(vector<string>& wordList)
{
	fstream wordFile;
	if (DEV_MODE)
		wordFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\wordList.csv", ios::in | ios::out | ios::app);
	else
		wordFile.open("wordList.csv");
	if (!wordFile)
	{
		cout << "wordList.csv open failed!" << endl;
		abort();
	}

	cout << "Please input your word (input \":q\" to quit ) : " << endl;
	int wordCount = 0;
	string myWord;
	cin >> myWord;
	while (myWord != ":q")
	{
		vector<string>::iterator wordIter = wordList.begin();
		for (; wordIter != wordList.end(); wordIter++)//����һ�����ʺ��ڵ��ʱ�����һ��
		{
			if (myWord == *wordIter)
				break;
		}
		if (wordIter == wordList.end())//δ��鵽��ͬ���ʣ���Iter��ָ��end()����ʱ�ɰѵ���д�뵽wordList��wordFile��
		{
			wordList.push_back(myWord);
			wordFile << myWord << endl;
			wordCount++;
		}
		else//�����Ѵ���ʱ���һ����ʾ
		{
			cout << "This word has already been in the database." << endl;
		}
		cin >> myWord;//���������:q����ֱ���˳�
	}
	cout << "You contributed " << wordCount << " word(s) !" << endl;
	return wordCount;
}
void flush_tester(int nowUserPos, int wordAdd, vector<tester>& testerList)
{
	tester nowtester = testerList[nowUserPos];
	nowtester.rewards(wordAdd);	//���´��˵ľ��顢�ȼ����������

	for (vector<tester>::iterator testerIter = testerList.begin(); testerIter != testerList.end();)//����testerList
	{
		if (testerIter->get_name() == nowtester.get_name())
		{
			testerList.erase(testerIter);
			testerList.push_back(nowtester);
			break;
		}
		else
			testerIter++;
	}

	string tmptesterInfo;//����testerFile
	vector<string> tmpInfoList;
	fstream testerFile;
	if (DEV_MODE)
		testerFile.open("D:\\coding\\C++Final\\C++Final_2\\Debug\\testerList.csv", ios::in | ios::out);
	else
		testerFile.open("testerList.csv");
	if (!testerFile)
	{
		cout << "testerList.csv open failed! " << endl;
		abort();
	}
	testerFile.seekp(0);
	getline(testerFile, tmptesterInfo);
	streamoff tmpFptr = testerFile.tellg();//��ÿ��ͷ����һ�е�ĩβ����һ����ַ�����������һ������Ϣ��Ҫ�޸ĵģ��ص����ͷ�����޸���Ϣ��
	while (testerFile && !(testerFile.peek()==EOF))
	{
		getline(testerFile, tmptesterInfo);//ȡ�ļ�һ�У������ֽ��user������
		string_split(tmptesterInfo, tmpInfoList, ",");
		if (tmpInfoList[0] == nowtester.get_name())
		{
			testerFile.seekp(tmpFptr);
			testerFile << nowtester.get_name() << "," << nowtester.get_password() << "," << nowtester.get_level() << "," << nowtester.get_problem_num();
			break;
		}
		tmpInfoList.clear();
		tmpFptr = testerFile.tellg();
	}
	testerFile.close();
	return;
}
