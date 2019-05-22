#include"database.h"

user::user(string newName, string newPassword)
{
	name = newName;
	password = newPassword;
};
user::~user()
{
};
string user::get_name()
{
	return name;
}
string user::get_password()
{
	return password;
}

player::player(string newName, string newPassword,int newExp,int newLevel,int newbestRound) : user(newName,newPassword)
{
	exp = newExp;
	level = newLevel;
	best_round = newbestRound;
};
player::~player()
{
}
int player::get_exp() { return exp; }
int player::get_level() { return level; }
int player::get_best_round() { return best_round; }
void player::rewards(int bestRound)
{
	exp += 5*bestRound*bestRound;
	if (this->best_round < bestRound)//�����λغ���������ʷ��ѻغ��������
		best_round = bestRound;
	while (exp / (10 * (level + 1)) > 0)//ÿ��һ������Ҫ10�����ȼ�+1���ľ���������
	{
		exp -= 10 * (level + 1); 
		level++;
	}
}

tester::tester(string newName, string newPassword,int newProblemNum, int newLevel) :user(newName, newPassword)
{
	level = newProblemNum;
	problemNum = newProblemNum;
}
tester::~tester()
{
}
short tester::get_level() { return level; }
int tester::get_problem_num() { return problemNum; }
void tester::rewards(int wordAdd)
{
	problemNum += wordAdd;
	while (problemNum >= ((level + 1)*(level + 2) / 2))
		level++;//ÿ��1����������Ҫ��������Ϊ����+1��0��1�����ʣ�1��2�����ʣ��Դ����ơ�������������Expһ�����Լ�����˵��Ƶõ��ȼ��뵥�������Ĺ�ϵ��
};



