#include"manager.h"
#include<algorithm>

Manager::Manager()
{

}
Manager::Manager(string name,string pwd)
{
    this->m_name = name;
    this->m_pwd = pwd;

    this->initvector();

    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);
    Computerroom c;
    while(ifs>>c.m_comid && ifs>>c.m_maxnum)
    {
        vcom.push_back(c);
    }
    cout<<"当前机房的数量:"<<vcom.size()<<endl;
    ifs.close();
}
void Manager::openmenu()
{
    cout << "欢迎管理员登录！" << endl;
        cout << "\t\t ---------------------------------\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          1.添加账号            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          2.查看账号            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          3.查看机房            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          4.清空预约            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t|          0.注销登录            |\n";
        cout << "\t\t|                                |\n";
        cout << "\t\t ---------------------------------\n";
        cout << "请选择您的操作： " << endl;
}
void Manager::addperson()
{
    cout<<"请输入要添加的账号类型"<<endl;
    cout<<"1.学生账号"<<endl;
    cout<<"2.老师账号"<<endl;
    int select;
    cin>>select;
    string filename;
    string tip;
    string errotip;
    ofstream ofs;
    if(select == 1)
    {
        filename = STUDENT_FILE;
        tip = "请输入学号：";
        errotip = "学号重复，请重新输入";
    }
    if(select == 2)
    {
        filename = TEACHER_FILE;
        tip = "请输入教师编号：";
        errotip = "教师编号重复，请重新输入";
    }
    ofs.open(filename,ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout<<"请输入姓名："<<endl;
    cin>>name;
    cout<<"请输入密码："<<endl;
    cin>>pwd;
    cout<<tip<<endl;
    while(1)
    {
        cin>>id;
        bool ret = isrepeat(id,select);
        if(ret)
        {
            cout<<errotip<<endl;
        }
        else
        {
            break;
        }
    }

    ofs<<endl;
    ofs<<id<<endl;
    ofs<<name<<endl;
    ofs<<pwd<<endl;
    ofs<<endl;
    cout<<"添加成功"<<endl;
    this->initvector();
    ofs.close();

    system("pause");
    system("cls");
}

void Manager::initvector()
{
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件为空"<<endl;
        return;
    }
    vstu.clear();
    vtea.clear();
    Student s;
    while(ifs>>s.m_id && ifs>>s.m_name && ifs>>s.m_pwd)
    {
        vstu.push_back(s);
    }
    cout<<"当前学生数："<<vstu.size()<<endl;
    ifs.close();

    ifs.open(TEACHER_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件为空"<<endl;
        return;
    }
    Teacher t;
    while(ifs>>t.m_empid && ifs>>t.m_name && ifs>>t.m_pwd)
    {
        vtea.push_back(t);
    }
    cout<<"当前教师数量："<<vtea.size()<<endl;
    ifs.close();
}
bool Manager::isrepeat(int id, int type)
{
    if(type == 1)
    {
        for(auto it = vstu.begin();it != vstu.end();it++)
        {
            if(id == it->m_id)
            {
                return 1;
            }
        }
    }
    else
    {
        for(auto it = vtea.begin();it != vtea.end();it++)
        {
            if(id == it->m_empid)
            {
                return 1;
            }
        }
    }
    return 0;
}
void printstudent(Student &s)
{
    cout<<"学号："<<s.m_id<<"姓名："<<s.m_name<<"密码："<<s.m_pwd<<endl;
}
void printteacher(Teacher & t)
{
    cout<<"职工号："<<t.m_empid<<"姓名："<<t.m_name<<"密码："<<t.m_pwd<<endl;
}
void Manager::showperson()
{
    cout<<"选择要查看的内容"<<endl;
    cout<<"1.查看所有学生"<<endl;
    cout<<"2.查看所有教师"<<endl;
    int select;
    cin>>select;
    if(select == 1)
    {
        cout<<"所有学生信息如下："<<endl;
        for_each(vstu.begin(),vstu.end(),printstudent);
    }
    else
    {
        cout<<"所有教师信息如下："<<endl;
        for_each(vtea.begin(),vtea.end(),printteacher);
    }
    system("pause");
    system("cls");
}
void Manager::showcomputer()
{
    cout<<"机房信息如下："<<endl;
    for(auto it = vcom.begin();it != vcom.end();it++)
    {
        cout<<"机房编号："<<it->m_comid<<"机房的最大数量："<<it->m_maxnum<<endl;
    }
    system("pause");
    system("cls");
}
void Manager::cleanfile()
{
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();

    cout<<"清除成功！"<<endl;
    system("pause");
    system("cls");
}

