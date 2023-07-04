#ifndef BOSS_H
#define BOSS_H

#endif // BOSS_H

#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss:public Worker
{
public:
    Boss(int id,string name,int did);
    //显示个人信息
    virtual void showinfo();
    //获取岗位名称
    virtual string getdeptname();
};
