#ifndef WORKER_H
#define WORKER_H

#endif // WORKER_H

#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#define FILENAME "info.txt"
class WorkerManager
{
public:
    WorkerManager();
    //菜单
    void menu();
    //退出
    void exitsystem();

    int m_EmpNum;//职工人数
    Worker** m_Emparry;
    //添加
    void add_emp();
    //保存文件
    void save();
    //判断文件是否为空 标志
    bool m_filenull;
    //统计人数
    int get_empnum();
    //初始化员工
    void init_emp();
    //显示员工
    void show_emp();
    //判断职工是否存在
    int Isexist(int id);
    //删除员工
    void del_emp();
    //修改职工
    void mod_emp();
    //查找职工
    void find_emp();
    //排序
    void sort_emp();
    //清空
    void clean_emp();

    ~WorkerManager();
};
