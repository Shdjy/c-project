#include <iostream>
#include<windows.h>
#include<string>

#define MAX 1000
using namespace std;
struct person  //联系人的结体
{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_addr;
};
struct addressbook
{
   struct person personarry[MAX];
   int m_size;
};

void menu()
{
    cout<<"*****************************"<<endl;
    cout<<"********1.添加联系人*********"<<endl;
    cout<<"********2.显示联系人*********"<<endl;
    cout<<"********3.删除联系人*********"<<endl;
    cout<<"********4.查找联系人*********"<<endl;
    cout<<"********5.修改联系人*********"<<endl;
    cout<<"********6.清空联系人*********"<<endl;
    cout<<"********0.退出通讯录*********"<<endl;
    cout<<"*****************************"<<endl;
}
void addperson(addressbook* ab)
{
    if(ab->m_size==MAX)
    {
        cout<<"通讯录已满"<<endl;
        return;
    }

    string name;
    cout<<"请输入姓名"<<endl;
    cin>>name;
    ab->personarry[ab->m_size].m_name = name;

    int sex = 0;
    cout<<"请输入性别"<<endl;
    cout<<"1----男"<<endl;
    cout<<"2----女"<<endl;
    while(1)
    {
        cin>>sex;
        if(sex==1 || sex==2)
        {
            ab->personarry[ab->m_size].m_sex = sex;
            break;
        }
        else
        {
            cout<<"请按要求输入"<<endl;
        }
    }

    cout<<"请输入年龄"<<endl;
    int age;
    cin>>age;
    ab->personarry[ab->m_size].m_age = age;

    cout<<"请输入电话"<<endl;
    string phone;
    cin>>phone;
    ab->personarry[ab->m_size].m_phone = phone;

    cout<<"请输入住址"<<endl;
    string addr;
    cin>>addr;
    ab->personarry[ab->m_size].m_addr = addr;

    ab->m_size++;
    cout<<"添加成功"<<endl;
    system("pause");
    system("cls");
}
void show(addressbook* ab)
{
    if(ab->m_size==0)
    {
        cout<<"当前通讯录为空"<<endl;
    }
    for(int i=0;i<ab->m_size;i++)
    {
        cout<<"name:"<<ab->personarry[i].m_name<<"\t";
        cout<<"sex:"<<(ab->personarry[i].m_sex ==1?"男":"女")<<"\t";
        cout<<"age:"<<ab->personarry[i].m_age<<"\t";
        cout<<"phone:"<<ab->personarry[i].m_phone<<"\t";
        cout<<"addr:"<<ab->personarry[i].m_addr<<endl;
    }
    system("pause");
    system("cls");
}
int isexist(addressbook* ab,string name)
{
    for(int i = 0;i<ab->m_size;i++)
    {
        if(ab->personarry[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
}
void remove(addressbook* ab)
{
    string name;
    cout<<"请输入要删除的姓名："<<endl;
    cin>>name;
    int ret = isexist(ab,name);
    if(ret!=-1)
    {
        for(int i = ret;i<ab->m_size;i++)
        {
            ab->personarry[i]=ab->personarry[i+1];
        }
        ab->m_size--;
        cout<<"删除成功"<<endl;
    }
    else
        cout<<"查无此人"<<endl;
    system("pause");
    system("cls");
}
void search(addressbook* ab)
{
    cout<<"请输入要查找的姓名"<<endl;
    string name;
    cin>>name;
    int ret = isexist(ab,name);
    if(ret == -1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        cout<<"name:"<<ab->personarry[ret].m_name<<"\t";
        cout<<"sex:"<<(ab->personarry[ret].m_sex ==1?"男":"女")<<"\t";
        cout<<"age:"<<ab->personarry[ret].m_age<<"\t";
        cout<<"phone:"<<ab->personarry[ret].m_phone<<"\t";
        cout<<"addr:"<<ab->personarry[ret].m_addr<<endl;
    }
    system("pause");
    system("cls");
}
void update(addressbook* ab)
{
    cout<<"请输入要修改的名字"<<endl;
    string name;
    cin>>name;
    int ret = isexist(ab,name);
    if(ret ==-1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        int sex = 0;
        cout<<"请输入性别"<<endl;
        cout<<"1----男"<<endl;
        cout<<"2----女"<<endl;
        while(1)
        {
            cin>>sex;
            if(sex==1 || sex==2)
            {
                ab->personarry[ret].m_sex = sex;
                break;
            }
            else
            {
                cout<<"请按要求输入"<<endl;
            }
        }

        cout<<"请输入年龄"<<endl;
        int age;
        cin>>age;
        ab->personarry[ret].m_age = age;

        cout<<"请输入电话"<<endl;
        string phone;
        cin>>phone;
        ab->personarry[ret].m_phone = phone;

        cout<<"请输入住址"<<endl;
        string addr;
        cin>>addr;
        ab->personarry[ret].m_addr = addr;
    }
    cout<<"修改成功"<<endl;
    system("pause");
    system("cls");
}
void clear(addressbook* ab)
{
    cout<<"确认要清空通讯录吗（Y/N）"<<endl;
    string selection;
    cin>>selection;
    if(selection=="Y")
    {
        ab->m_size = 0;
        cout<<"清空成功"<<endl;
    }
    else if(selection == "N")
    {
        cout<<"取消清空"<<endl;
    }
    else
        cout<<"输入非法，返回主界面"<<endl;
    system("pause");
    system("cls");
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    addressbook ab;
    ab.m_size=0;
    int select =0;
    do{
        menu();//菜单
        cin>>select;
        switch(select)
        {
        case 1:
            addperson(&ab);
            break;
        case 2:
            show(&ab);
            break;
        case 3:
            remove(&ab);
            break;
        case 4:
            search(&ab);
            break;
        case 5:
            update(&ab);
            break;
        case 6:
            clear(&ab);
            break;
        case 0:
            cout<<"欢迎下次使用"<<endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }

    }while(true);


}
