#pragma once
#include"global.h"
#include"database.h"


//ע��״̬����user_register.cpp�У�
void state_register(vector<player>& playerList, vector<tester>& testerList);

//��¼������login.cpp��
int player_login(vector<player>& playerList);
int tester_login(vector<tester>& testerList);

//��Ϸ״̬��game.cpp��
int state_game(vector<string>& wordList);
void flush_player(int nowUserPos, int expReward, vector<player>& playerList);

//����״̬��testmake.cpp��
int state_testmake(vector<string>& wordList);
void flush_tester(int nowUserPos, int problemNumReward, vector<tester>& testerList);

//��ѯ״̬��search.cpp��
void state_query(vector<player>& playerList, vector<tester>& testerList);

//������������init.cpp�У�
void wordList_init(vector<string>& wordList);
void playerList_init(vector<player>& playerList);
void testerList_init(vector<tester>& testerList);
void show_main_info();

//��������
//�ַ����ָ������search.cpp�У�
void string_split( std::string& s, std::vector<std::string>& v,  const std::string& c);
//�ַ����ȽϺ�������search.cpp�У�
bool string_cmp( string&x,  string&y);
//������򷽷�
bool player_name_cmp(player&p1, player&p2);//����������
bool player_level_cmp(player& p1, player&p2);//���ȼ�����
bool player_best_round_cmp(player& p1, player&p2);//����óɼ�����
//���������򷽷�
bool tester_name_cmp(tester&p1, tester&p2);//����������
bool tester_level_cmp(tester&p1, tester&p2);//���ȼ�����
bool tester_problem_num_cmp(tester&p1, tester&p2);//������������
