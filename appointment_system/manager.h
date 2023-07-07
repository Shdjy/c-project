#ifndef MANAGER_H
#define MANAGER_H

#endif // MANAGER_H

#pragma once
#include<iostream>
using namespace std;
#include"indentity.h"
#include"file.h"
#include<fstream>
#include<vector>
#include"teacher.h"
#include"student.h"
#include<iterator>
#include"computerroom.h"

class Manager:public Indentity
{
public:
    Manager();
    Manager(string name, string pwd);
    virtual void openmenu();
    //添加账号
    void addperson();
    //查看账号
    void showperson();
    //查看机房信息
    void showcomputer();
    //清空预约记录
    void cleanfile();
    //初始化容器
    void initvector();

    vector<Student> vstu;
    vector<Teacher> vtea;

    //检查重复
    bool isrepeat(int id,int type);

    vector<Computerroom> vcom;

};
