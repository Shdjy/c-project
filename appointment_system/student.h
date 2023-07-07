#ifndef STUDENT_H
#define STUDENT_H

#endif // STUDENT_H

#pragma once
#include<iostream>
using namespace std;
#include"indentity.h"
#include"file.h"
#include"computerroom.h"
#include<vector>
#include<fstream>
#include"orderfile.h"
class Student:public Indentity
{
public:
    Student();

    Student(int id,string name,string pwd);

    virtual void openmenu();
    //申请预约
    void applyorder();
    //查看我的预约
    void showmyorder();
    //查看所有预约
    void showallorder();
    //取消预约
    void cancelorder();
    int m_id;

    vector<Computerroom> vcom;
};
