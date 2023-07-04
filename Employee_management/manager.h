#ifndef MANANGER_H
#define MANANGER_H

#endif // MANANGER_H

#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager:public Worker
{
public:
    Manager(int id,string name,int did);
    //显示个人信息
    virtual void showinfo();
    //获取岗位名称
    virtual string getdeptname();
};
