#ifndef SPEECHMANAGER_H
#define SPEECHMANAGER_H

#endif // SPEECHMANAGER_H

#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include <numeric>
#include<fstream>
#include"speecher.h"
#include<iterator>
#include <algorithm>
#include<functional>
using namespace std;

class SpeechManager
{
public:
    SpeechManager();
    //菜单函数
    void show_menu();
    void exitsystem();

    vector<int> v1;//比赛选手12人
    vector<int> v2;//第一轮晋级6人
    vector<int> victory;//胜利3人
    map<int, Speecher> m_speecher;
    int m_index;//轮数
    //初始化
    void initSpeecher();
    //创建12名选手
    void createspeeher();
    //开始比赛
    void startspeeh();
    //抽签
    void speechdraw();
    //比赛
    void speechcontest();
    //比赛结果
    void showscore();
    //保存分数
    void savescore();
    //读取记录
    void loadrecord();
    //判断文件是否为空
    bool fileisempty;
    //往届记录
    map<int, vector<string>> m_record;
    //显示往届得分
    void showrecord();
    //清空记录
    void cleanrecord();
    ~SpeechManager();
};
