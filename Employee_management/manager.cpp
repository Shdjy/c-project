#include"manager.h"

Manager::Manager(int id,string name,int did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}
//显示个人信息
void Manager::showinfo()
 {
     cout<<"职工编号:"<<m_id
        <<"\t职工姓名:"<<m_name
       <<"\t岗位:"<<this->getdeptname()
      <<"\t岗位职责:完成老板交给的任务，并下发任务给员工"<<endl;
 }
//获取岗位名称
string Manager:: getdeptname()
{
    return string("经理");
}
