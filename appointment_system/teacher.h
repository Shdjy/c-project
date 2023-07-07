#ifndef TEACHER_H
#define TEACHER_H

#endif // TEACHER_H


#pragma once
#include<iostream>
using namespace std;
#include"indentity.h"
#include"file.h"
#include"orderfile.h"
#include<vector>

class Teacher:public Indentity
{
public:
    Teacher();
    Teacher(int empid,string name,string pwd);

    virtual void openmenu();
    //查看所有预约
    void showallorder();
    //审核预约
    void valiorder();
    int m_empid;

};
