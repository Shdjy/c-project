#include <iostream>
#include<windows.h>
#include"file.h"
#include"indentity.h"
#include<fstream>
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;


void managermenu(Indentity* &manager);
void Studentmenu(Indentity* &student);
void Teachermenu(Indentity* &teacher);

void LoginIn(string filename,int type)
{
    Indentity* person = NULL;
    ifstream ifs;
    ifs.open(filename,ios::in);

    //文件不存在
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        ifs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;
    if(type == 1)
    {
        cout<<"请输入你的学号:"<<endl;
        cin>>id;
    }
    if(type == 2)
    {
        cout<<"请输入你的职工号:"<<endl;
        cin>>id;
    }
    cout<<"请输入用户名:"<<endl;
    cin>>name;

    cout<<"请输入密码:"<<endl;
    cin>>pwd;

    if(type == 1)
    {
        //学生验证
        int fid;
        string fname;
        string fpwd;
        while(ifs>>fid && ifs>>fname && ifs>>fpwd)
        {
            if(fid == id && fname == name && fpwd == pwd)
            {
                cout<<"学生登录验证成功！"<<endl;
                system("pause");
                system("cls");
                person = new Student(id,name,pwd);
                //进如学生菜单
                Studentmenu(person);
                return;
            }
        }
    }
    if(type == 2)
    {
       //教师验证
        int fid;
        string fname;
        string fpwd;
        while(ifs>>fid && ifs>>fname && ifs>>fpwd)
        {
            if(fid == id && fname == name && fpwd == pwd)
            {
                cout<<"教师登录验证成功！"<<endl;
                system("pause");
                system("cls");
                person = new Teacher(id,name,pwd);
                Teachermenu(person);
                return;
            }
        }
    }
    else
    {
        //管理员验证
        string fname;
        string fpwd;
        while(ifs>>fname && ifs>>fpwd)
        {
            if(fname == name && fpwd == pwd)
            {
                cout<<"管理员登录验证成功！"<<endl;
                system("pause");
                system("cls");
                person = new Manager(name,pwd);
                //进入管理员子菜单
                managermenu(person);
                return;
            }
        }
    }
    cout<<"验证失败"<<endl;
    system("pause");
    system("cls");
}

void managermenu(Indentity* &manager)
{
    while(1)
    {
        manager->openmenu();
        Manager* man = (Manager*)manager;
        int select;
        cin>>select;
        switch(select)
        {
        case 1:
            cout<<"添加账号"<<endl;
            man->addperson();
            break;
        case 2:
            cout<<"查看账号"<<endl;
            man->showperson();
            break;
        case 3:
            cout<<"查看机房"<<endl;
            man->showcomputer();
            break;
        case 4:
            cout<<"清空预约"<<endl;
            man->cleanfile();
            break;
        case 0:

            delete manager;
            cout<<"注销成功"<<endl;
            system("pause");
            system("cls");
            return;
        default:
            cout<<"输入有误，请重新选择！"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    system("cls");
}

void Studentmenu(Indentity* &student)
{
    while(1)
    {
        //学生菜单
        student->openmenu();

        Student* stu = (Student*)student;
        int select;
        cin>>select;
        if(select == 1)
        {
            stu->applyorder();
        }
        else if(select == 2)
        {
            stu->showmyorder();
        }
        else if(select == 3)
        {
            stu->showallorder();
        }
        else if(select == 4)
        {
            stu->cancelorder();
        }
        else
        {
            delete student;
            cout<<"注销成功"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void Teachermenu(Indentity* &teacher)
{
    while(1)
    {
        teacher->openmenu();

        Teacher* tea = (Teacher*)teacher;
        int select;
        cin>>select;
        if(select == 1)
        {
            tea->showallorder();
        }
        else if(select == 2)
        {
            tea->valiorder();
        }
        else
        {
            delete teacher;
            cout<<"注销成功"<<endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int select;
    while(1)
    {
        cout << "======================  欢迎来到机房预约系统  ====================="
                 << endl;
            cout << endl << "请输入您的身份" << endl;
            cout << "\t\t -------------------------------\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          1.学生代表           |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          2.老    师           |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          3.管 理 员           |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t|          0.退    出           |\n";
            cout << "\t\t|                               |\n";
            cout << "\t\t -------------------------------\n";
            cout << "输入您的选择: ";
            cin>>select;
            switch(select)
            {
            case 1:
                LoginIn(STUDENT_FILE,1);
                break;
            case 2:
                LoginIn(TEACHER_FILE,2);
                break;
            case 3:
                LoginIn(AMDIN_FILE,3);
                break;
            case 0:
                cout<<"退出成功，欢迎下次使用。"<<endl;
                system("pause");
                return 0;
            default:
                cout<<"输入有误，请重新选择！"<<endl;
                system("pause");
                system("cls");
                break;
            }

            system("pause");

    }
}
