#include"teacher.h"

Teacher::Teacher(){}

Teacher::Teacher(int empid,string name,string pwd)
{
    this->m_empid = empid;
    this->m_name = name;
    this->m_pwd = pwd;
}
void Teacher::openmenu()
{
    cout << "欢迎教师登录！" << endl;
        cout << "\t\t ----------------------------------\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t|          1.查看所有预约          |\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t|          2.审核预约              |\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t|          0.注销登录              |\n";
        cout << "\t\t|                                  |\n";
        cout << "\t\t ----------------------------------\n";
        cout << "请选择您的操作： " << endl;
}
void Teacher::showallorder()
{
    Orderfile of;
    if(of.m_size == 0)
    {
        cout<<"无预约记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0;i<of.m_size;i++)
    {
        cout<<i+1<<",";
        cout<<"预约时间：周"<<of.m_orderdata[i]["date"];
        cout<<"时段："<<(of.m_orderdata[i]["time"] == "1"? "上午":"下午");
        cout<<"学号："<<of.m_orderdata[i]["stuid"];
        cout<<"姓名："<<of.m_orderdata[i]["stuname"];
        cout<<"机房："<<of.m_orderdata[i]["roomid"];
        string status = "状态：";
        if(of.m_orderdata[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if(of.m_orderdata[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if(of.m_orderdata[i]["status"] == "-1")
        {
            status += "审核未通过，预约失败";
        }
        else
        {
            status += "预约已取消";
        }
        cout<<status<<endl;
    }
    system("pause");
    system("cls");

}
void Teacher::valiorder()
{
    Orderfile of;
    if(of.m_size == 0)
    {
        cout<<"无预约记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"待审核的记录如下："<<endl;

    vector<int>v;
    int index = 1;
    for(int i = 0;i<of.m_size;i++)
    {
        if(of.m_orderdata[i]["status"] == "1")
        {
            v.push_back(i);
            cout<<index++<<",";
            cout<<"预约时间：周"<<of.m_orderdata[i]["date"];
            cout<<"时段："<<of.m_orderdata[i]["time"];
            cout<<"机房："<<of.m_orderdata[i]["roomid"];
            string status = "状态：";

            if(of.m_orderdata[i]["stauts"] == "1")
            {
                status += "审核中";
            }
            cout<<status<<endl;

        }
    }
    cout<<"请选择审核预约记录，按0返回"<<endl;
    int select;
    int ret = 0;
    while(1)
    {
        cin>>select;
        if(select >= 0 && select <= (int)v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                cout<<"请输入审核结果："<<endl;
                cout<<"1.通过"<<endl;
                cout<<"2.不通过"<<endl;
                cin>>ret;
                if(ret == 1)
                {
                    of.m_orderdata[v[select-1]]["status"] = "2";
                }
                else
                {
                    of.m_orderdata[v[select-1]]["status"] = "-1";
                }
                of.updateorder();
                cout<<"审核完毕！"<<endl;
                break;
            }
        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    system("pause");
    system("cls");
}

