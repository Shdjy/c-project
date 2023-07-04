#include"boss.h"

Boss::Boss(int id,string name,int did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}
//显示个人信息
 void Boss::showinfo()
 {
     cout<<"职工编号:"<<m_id
        <<"\t职工姓名:"<<m_name
       <<"\t岗位:"<<this->getdeptname()
      <<"\t岗位职责:管理公司所有事务"<<endl;
 }
//获取岗位名称
string Boss:: getdeptname()
{
    return string("老板");
}
