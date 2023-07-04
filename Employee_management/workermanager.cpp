#include"workermanager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open())
    {
        //cout<<"文件不存在"<<endl;
        m_EmpNum = 0;
        m_Emparry = nullptr;
        this->m_filenull = true;
        ifs.close();
        return;
    }
    //文件存在但为空
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        //cout<<"文件为空"<<endl;
        m_EmpNum = 0;
        m_Emparry = nullptr;
        this->m_filenull = true;
        ifs.close();
        return;
    }
    //文件存在不为空
    int num = this->get_empnum();
    //cout<<"职工人数："<<num<<endl;
    this->m_filenull = false;
    this->m_EmpNum = num;
    //根据职工数创建数组
    this->m_Emparry = new Worker*[this->m_EmpNum];//开辟空间
    init_emp();
}
void WorkerManager::menu()
{
    cout<<"****************************************"<<endl;
    cout<<"**********欢迎使用职工管理系统**********"<<endl;
    cout<<"************0.退出管理系统**************"<<endl;
    cout<<"************1.增加职工信息**************"<<endl;
    cout<<"************2.显示职工信息**************"<<endl;
    cout<<"************3.删除职工信息**************"<<endl;
    cout<<"************4.修改职工信息**************"<<endl;
    cout<<"************5.查找职工信息**************"<<endl;
    cout<<"************6.按编号排序 ***************"<<endl;
    cout<<"************7.清空职工信息**************"<<endl;
    cout<<"****************************************"<<endl;
}
void WorkerManager::exitsystem()
{
   cout<<"欢迎下次使用"<<endl;
   system("pause");
   exit(0);
}
void WorkerManager::add_emp()
{
    cout<<"请输入添加职工个数："<<endl;
    int addnum;
    cin>>addnum;
    if(addnum > 0)
    {
        int newsize = this->m_EmpNum+addnum;
        Worker** newspace =new Worker*[newsize];

        if(this->m_Emparry!=NULL)
        {
            for(int i = 0;i<this->m_EmpNum;i++)
            {
                newspace[i] = this->m_Emparry[i];
            }
        }
        //批量添加
        for(int i = 0;i < addnum;i++)
        {
            int id;
            string name;
            int dselect;
            while(1)
            {
                cout<<"请输入第"<<i+1<<"个新职工的编号"<<endl;
                cin>>id;
                if(this->m_filenull)
                {
                    break;
                }
                for(int i = 0;i<this->m_EmpNum-1;i++)
                {
                    if(this->m_Emparry[i]->m_id == id)
                    {
                        cout<<"该id已存在请重新输入"<<endl;
                    }
                    break;
                }
            }



            cout<<"请输入第"<<i+1<<"个新职工的姓名"<<endl;
            cin>>name;
            cout<<"请选择职工岗位"<<endl;
            cout<<"1.普通员工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>dselect;
            Worker* worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(id,name,1);
                break;
            case 2:
                worker = new Manager(id,name,2);
                break;
            case 3:
                worker = new Boss(id, name,3);
                break;
            default:
                break;
            }
            newspace[this->m_EmpNum+1]=worker;
        }
        //释放原来数组
        delete [] this->m_Emparry;
        this->m_Emparry = newspace;
        this->m_EmpNum = newsize;
        //保存到文件中
        this->save();
        this->m_filenull = false;
        cout<<"成功添加"<<addnum<<"名新职工"<<endl;
    }
    else
    {
        cout<<"输入有误"<<endl;
    }
    system("pause");
    system("cls");
}
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//写文件
    //件给个人的数据写入文件
    for(int i =0;i<this->m_EmpNum;i++)
    {
        ofs<<this->m_Emparry[i]->m_id<<" "
          <<this->m_Emparry[i]->m_name<<" "
         <<this->m_Emparry[i]->m_deptid<<endl;
    }
    ofs.close();
}
int WorkerManager::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;

    int num=0;
    while(ifs>>id && ifs>>name && ifs>>did)
    {
        num++;
    }
    ifs.close();
    return num;
}
//初始化员工
void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int did;

    int index = 0;
    while(ifs>>id && ifs >> name && ifs >> did)
    {
        Worker* worker = nullptr;
        if(did == 1)
        {
            worker = new Employee(id,name,did);
        }
        if(did == 2)
        {
            worker = new Manager(id,name,did);
        }
        if(did == 3)
        {
            worker = new Boss(id,name,did);
        }
        this->m_Emparry[index] = worker;
        index++;
    }
    ifs.close();
}
void WorkerManager::show_emp()
{
    if(this->m_filenull)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<this->m_EmpNum;i++)
            this->m_Emparry[i]->showinfo();
    }
    system("pause");
    system("cls");
}
int WorkerManager::Isexist(int id)
{
    int index = -1;
    for(int i = 0;i<this->m_EmpNum;i++)
    {
        if(this->m_Emparry[i]->m_id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
void WorkerManager::del_emp()//删除
{
    if(this->m_filenull)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        cout<<"请输入要删除职工的id"<<endl;
        int id;
        cin>>id;

        int ret = Isexist(id);
        if(ret == -1)
        {
            cout<<"查无此人"<<endl;
        }
        else
        {
            for(int i = ret;i<this->m_EmpNum;i++)
            {
                this->m_Emparry[i] = this->m_Emparry[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout<<"删除成功"<<endl;
        }
        system("pause");
        system("cls");
    }
}
void WorkerManager::mod_emp()
{
    if(this->m_filenull)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        cout<<"请输入修改职工的编号"<<endl;
        int id;
        cin>>id;

        int ret = Isexist(id);
        if(ret == -1)
        {
            cout<<"查无此人"<<endl;
        }
        else
        {
            //修改
            delete this->m_Emparry[ret];
            int newid;
            string newname;
            int dselect;
            cout<<"查到："<<id<<"号职工，请输入新的职工号。"<<endl;
            cin>>newid;
            cout<<"请输入新的姓名"<<endl;
            cin>>newname;
            cout<<"请输入新的岗位："<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>dselect;
            Worker* worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(newid,newname,1);
                break;
            case 2:
                worker = new Manager(newid,newname,2);
                break;
            case 3:
                worker = new Boss(newid, newname,3);
                break;
            default:
                break;
            }
            //跟新数据到数组中
            this->m_Emparry[ret] = worker;
            cout<<"修改成功"<<endl;
            this->save();
        }
    }
    system("pause");
    system("cls");
}
void WorkerManager::find_emp()
{
    if(this->m_filenull)
    {
        cout<<"文件不存在或者记录为空"<<endl;
    }
    else
    {
        cout<<"请选择查找方式"<<endl;
        cout<<"1.按id查找"<<endl;
        cout<<"2.按姓名查找"<<endl;
        int find;
        cin>>find;
        if(find == 1)
        {
            //按id
            int id = 0;
            cout<<"请输入要查找啊的编号"<<endl;
            cin>>id;
            int ret  = Isexist(id);
            if(ret == -1)
            {
                cout<<"查无此人！"<<endl;
            }
            else
            {
                cout<<"查找成功，员工信息如下："<<endl;
                this->m_Emparry[ret]->showinfo();
            }
        }
        else if(find == 2)
        {
            string name;
            cout<<"请输入要查找员工的姓名："<<endl;
            cin>>name;
            bool flag = false;
            for(int i = 0;i<this->m_EmpNum;i++)
            {
                if(this->m_Emparry[i]->m_name == name)
                {
                    cout<<"查找成功，职工编号为："
                       <<this->m_Emparry[i]->m_id<<"职工信息："<<endl;
                    this->m_Emparry[i]->showinfo();
                    flag = true;
                }
            }
            if(flag == false)
            {
                cout<<"查无此人！"<<endl;
            }
        }
    }
    system("pause");
    system("cls");
}
void WorkerManager::sort_emp()
{
    if(this->m_filenull)
    {
        cout<<"文件不存在或者记录为空"<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout<<"请选择排序的方式"<<endl;
        cout<<"1.按职工号升序"<<endl;
        cout<<"2.按职工号降序"<<endl;
        int select = 0;
        cin>>select;
        for(int i = 0;i<this->m_EmpNum;i++)
        {
            int min_max = i;
            for(int j = i+1;j<this->m_EmpNum;j++)
            {
                if(select == 1)
                {
                    if(this->m_Emparry[min_max]->m_id > this->m_Emparry[j]->m_id)
                    {
                        min_max = j;
                    }
                }
                else
                {
                    if(this->m_Emparry[min_max]->m_id < this->m_Emparry[j]->m_id)
                    {
                        min_max = j;
                    }
                }
            }
            if(i != min_max)
            {
                Worker* temp = this->m_Emparry[i];
                this->m_Emparry[i] = this->m_Emparry[min_max];
                this->m_Emparry[min_max] = temp;
            }
        }
        cout<<"排序成功，排序后的结果："<<endl;
        this->save();
        this->show_emp();
    }
}
void WorkerManager::clean_emp()
{
    cout<<"确定清空吗?"<<endl;
    cout<<"1.确定"<<endl;
    cout<<"2.返回"<<endl;
    int select = 0;
    cin>>select;
    if(select == 1)
    {
        ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
        ofs.close();

        if(this->m_Emparry != NULL)
        {
            for(int i = 0;i < this->m_EmpNum;i++)
            {
                delete this->m_Emparry[i];
                this->m_Emparry[i] = NULL;
            }
            delete[] this->m_Emparry;
            this->m_Emparry = NULL;
            this->m_EmpNum = 0;
            this->m_filenull = true;
        }
       cout<<"清除成功！"<<endl;
    }
    system("pause");
    system("cls");
}
WorkerManager::~WorkerManager()
{
    if(this->m_Emparry!=NULL)
    {
       for(int i = 0;i < this->m_EmpNum;i++)
       {
           if(this->m_Emparry[i] != NULL)
           {
               delete this->m_Emparry[i];
           }
       }
       delete[] this->m_Emparry;
    }
}
