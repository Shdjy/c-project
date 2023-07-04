#ifndef WORKER_H
#define WORKER_H

#endif // WORKER_H


#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker//职工抽象类
{
public:
    int m_id;
    string m_name;
    int m_deptid;
    //显示个人信息
    virtual void showinfo()=0;
    //获取岗位名称
    virtual string getdeptname()=0;
    virtual ~Worker() {}
};
