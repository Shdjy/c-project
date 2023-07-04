#include <iostream>
#include"workermanager.h"
#include<windows.h>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

//公司中职工分为三类:普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
//普通员工职责:完成经理交给的任务
//经理职责:完成老板交给的任务，并下发任务给员工
//老板职责:管理公司所有事务
//系统功能：退出，增加，显示，删除，修改，查找，按编号排序，清空


int main()
{
    SetConsoleOutputCP(CP_UTF8);


    WorkerManager wm;
    int input;
    while(1)
    {
        wm.menu();
        cout<<"请选择执行的功能"<<endl;
        cin>>input;
        switch (input)
        {
        case 0://退出
            wm.exitsystem();
            break;
        case 1://增加
            wm.add_emp();
            break;
        case 2://显示
            wm.show_emp();
            break;
        case 3://删除
            wm.del_emp();
            break;
        case 4://修改
            wm.mod_emp();
            break;
        case 5://查找
            wm.find_emp();
            break;
        case 6://排序
            wm.sort_emp();
            break;
        case 7://清空
            wm.clean_emp();
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
}
