#include"student.h"

Student::Student()
{

}
Student::Student(int id,string name,string pwd)
{
    m_id = id;
    m_name = name;
    m_pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE,ios::in);

    Computerroom c;
    while(ifs>>c.m_comid && ifs>>c.m_maxnum)
    {
        vcom.push_back(c);
    }
    ifs.close();
}

void Student::openmenu()
{
    cout << "欢迎学生登录！" << endl;
        cout << "\t\t ----------------------------------\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          1.申请预约              |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          2.查看我的预约          |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          3.查看所有预约          |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          4.取消预约              |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t|          0.注销登录              |\n";
        cout << "\t\t|                                 |\n";
        cout << "\t\t ----------------------------------\n";
        cout << "请选择您的操作： " << endl;
}
void Student::applyorder()
{
    cout<<"机房开放时间为周一到周五"<<endl;
    cout<<"请输入申请预约的时间："<<endl;
    cout<<"1.周一"<<endl;
    cout<<"2.周二"<<endl;
    cout<<"3.周三"<<endl;
    cout<<"4.周四"<<endl;
    cout<<"5.周五"<<endl;
    int date = 0;
    int time;
    int room;
    while(1)
    {
        cin>>date;
        if(date >= 1 && date <= 5)
        {
            break;
        }
        cout<<"输入有无请重新选择时间"<<endl;
    }

    cout<<"请选择申请预约时间段："<<endl;
    cout<<"1.上午"<<endl;
    cout<<"2.下午"<<endl;
    while(1)
    {
        cin>>time;
        if(time >= 1 && time<= 2)
        {
            break;
        }
        cout<<"输入有误请重新选择"<<endl;
    }

    cout<<"请选择机房："<<endl;
    cout<<"1号机房容量："<<vcom[0].m_maxnum<<endl;
    cout<<"2号机房容量："<<vcom[1].m_maxnum<<endl;
    cout<<"3号机房容量："<<vcom[2].m_maxnum<<endl;
    while(1)
    {
        cin>>room;
        if(room >= 1 && room <=3)
        {
            break;
        }
        cout<<"输入有误请重新选择机房："<<endl;
    }
    cout<<"预约成功！审核中..."<<endl;

    ofstream ofs(ORDER_FILE,ios::app);
    ofs<<"date:"<<date<<endl;
    ofs<<"time:"<<time<<endl;
    ofs<<"stuid:"<<this->m_id<<endl;
    ofs<<"stuname:"<<this->m_name<<endl;
    ofs<<"roomid:"<<room<<endl;
    ofs<<"status:"<<1<<endl;
    ofs<<endl;
    //ofs<<endl;
    ofs.close();
    system("pause");
    system("cls");
}
void Student::showmyorder()
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

        if(atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id)
        {

            cout<<"预约日期：周"<<of.m_orderdata[i]["date"];
            cout<<"时段："<<(of.m_orderdata[i]["time"] == "1"? "上午":"下午");
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
            system("pause");
            system("cls");
        }
    }

}
void Student::showallorder()
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
void Student::cancelorder()
{
    Orderfile of;
    if(of.m_size == 0)
    {
        cout<<"无预记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"审核中或预约成功的记录可以取消，请输入消费记录"<<endl;

    vector<int>v;
    int index = 1;
    for(int i = 0;i<of.m_size;i++)
    {
        if(atoi(of.m_orderdata[i]["stuid"].c_str()) == this->m_id)
        {
            if(of.m_orderdata[i]["status"] == "1" || of.m_orderdata[i]["status"] == "2")
            {
                v.push_back(i);
                cout<<index++<<",";
                cout<<"预约时间：周"<<of.m_orderdata[i]["date"];
                cout<<"时段："<<of.m_orderdata[i]["time"];
                cout<<"机房："<<of.m_orderdata[i]["roomid"];
                string status = "状态：";

                if(of.m_orderdata[i]["status"] == "1")
                {
                    status += "审核中";
                }
                if(of.m_orderdata[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                cout<<status<<endl;
            }
        }
    }
    cout<<"请输入取消的记录，按0返回"<<endl;
    int select = 0;
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
                of.m_orderdata[select]["status"] = "0";
                of.updateorder();
                cout<<"取消预约成功"<<endl;
                break;
            }
        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    system("pause");
    system("cls");
}

