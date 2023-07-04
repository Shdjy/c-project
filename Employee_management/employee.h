#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#endif // EMPLOYEE_H
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Employee:public Worker
{
public:
    Employee(int id,string name,int did);
    //显示个人信息
    virtual void showinfo();
    //获取岗位名称
    virtual string getdeptname();
};
