#include"orderfile.h"

Orderfile::Orderfile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);
    string date;
    string time;
    string stuid;
    string stuname;
    string roomid;
    string status;

    this->m_size = 0;

    while(ifs>>date && ifs>>time && ifs>>stuid && ifs>>stuname &&
          ifs>>roomid && ifs>>status)
    {
        string key;
        string value;
        map<string,string> m;
        int pos = date.find(":");
        if(pos != -1)
        {
            key = date.substr(0,pos);
            value = date.substr(pos+1,date.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = time.find(":");
        if(pos != -1)
        {
            key = time.substr(0,pos);
            value = time.substr(pos+1,date.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = stuid.find(":");
        if(pos != -1)
        {
            key = stuid.substr(0,pos);
            value = stuid.substr(pos+1,date.size()-pos);
            m.insert(make_pair(key,value));
        }
        pos = stuname.find(":");
        if(pos != -1)
        {
            key = stuname.substr(0,pos);
            value = stuname.substr(pos+1,date.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = roomid.find(":");
        if(pos != -1)
        {
            key = roomid.substr(0,pos);
            value = roomid.substr(pos+1,date.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        pos = status.find(":");
        if(pos != -1)
        {
            key = status.substr(0,pos);
            value = status.substr(pos+1,date.size()-pos-1);
            m.insert(make_pair(key,value));
        }

        this->m_orderdata.insert(make_pair(this->m_size,m));
        this->m_size++;

//        for (map<int, map<string, string>>::iterator it = m_orderdata.begin(); it != m_orderdata.end();it++)
//            {
//                cout << "key = " << it->first << " value = " << endl;
//                for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
//                {
//                    cout << mit->first << " " << mit->second << " ";
//                }
//                cout << endl;
//            }
    }
    ifs.close();
}



void Orderfile::updateorder()
{
    if(this->m_size == 0)
    {
        return;
    }

    ofstream ofs(ORDER_FILE,ios::out | ios::trunc);
    for(int i = 0;i < m_size;i++)
    {
        ofs<<"date:"<<this->m_orderdata[i]["date"]<<endl;
        ofs<<"time:"<<this->m_orderdata[i]["time"]<<endl;
        ofs<<"stuid:"<<this->m_orderdata[i]["stuid"]<<endl;
        ofs<<"stuname:"<<this->m_orderdata[i]["stuname"]<<endl;
        ofs<<"roomid:"<<this->m_orderdata[i]["roomid"]<<endl;
        ofs<<"status:"<<this->m_orderdata[i]["status"]<<endl;
        ofs<<endl;
    }
    ofs.close();
}






