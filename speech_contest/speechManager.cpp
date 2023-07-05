#include"speechManager.h"


SpeechManager::SpeechManager()
{
    this->initSpeecher();

    this->createspeeher();

    this->loadrecord();
}
void SpeechManager::show_menu()
{
    cout<<"***********************************"<<endl;
    cout<<"********* 欢迎参加演讲比赛 ********"<<endl;
    cout<<"********** 1.开始演讲比赛 *********"<<endl;
    cout<<"********** 2.查看往届记录 *********"<<endl;
    cout<<"********** 3.清空比赛记录 *********"<<endl;
    cout<<"********** 0.退出比赛程序 *********"<<endl;
    cout<<"***********************************"<<endl;
}

void SpeechManager::exitsystem()
{
    cout<<"欢迎下次使用！"<<endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeecher()
{
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->m_speecher.clear();
    this->m_record.clear();

    this->m_index = 1;
}

void SpeechManager::createspeeher()
{
    string nameseed = "ABCDEFGHIJKL";
    for(int i = 0;i<(int)nameseed.size();i++)
    {
        string name = "选手";
        name += nameseed[i];

        Speecher sp;
        sp.m_name = name;
        for(int i = 0;i < 2;i++)
        {
            sp.m_score[i] = 0;
        }
        this->v1.push_back(i + 10001);

        this->m_speecher.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startspeeh()
{
    //第一轮比赛
    //1.抽签
    this->speechdraw();
    //2.比赛
    this->speechcontest();
    //3.晋级结果
    this->showscore();
    //第二轮
    this->m_index++;
    //1.抽签
    this->speechdraw();
    //2.比赛
    this->speechcontest();
    //3.结果
    this->showscore();
    //4保存分数
    this->savescore();

    //重置比赛
    //初始化属性
    this->initSpeecher();
    this->createspeeher();
    this->loadrecord();

    cout<<"本届比赛完毕！"<<endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechdraw()
{
    cout<<"第"<<m_index<<"轮比赛选手正在抽签"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"抽签顺序如下"<<endl;
    if(m_index == 1)
    {
        random_shuffle(v1.begin(),v1.end());
        for(auto val:v1)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    else
    {
        random_shuffle(v2.begin(),v2.end());
        for(auto val: v2)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
    system("pause");
    cout<<endl;
}

void SpeechManager::speechcontest()
{
    cout<<"----------------第"<<m_index<<"轮比赛开始-----------------"<<endl;
    multimap<double,int,greater<int>> groupscore;

    int num = 0;

    vector<int> v_src;
    if(m_index == 1)
    {
        v_src = v1;
    }
    else
    {
        v_src = v2;
    }
    for(auto it = v_src.begin();it != v_src.end();it++)
    {
        num++;

        deque<int> d;
        for(int i = 0;i < 10;i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            d.push_back(score);
        }
        sort(d.begin(),d.end(),greater<double>());
        d.pop_back();
        d.pop_front();
        double sum = accumulate(d.begin(),d.end(),0.0f);
        double avg = sum / (double)d.size();

        this->m_speecher[*it].m_score[this->m_index-1] = avg;
        groupscore.insert(make_pair(avg,*it));
        if(num % 6 == 0)
        {
            cout<<"第"<<num/6<<"组比赛名次"<<endl;
            for(auto it = groupscore.begin();it != groupscore.end();it++)
            {
                cout<<"编号:"<<it->second<<"姓名:"<<this->m_speecher[it->second].m_name
                   <<"成绩:"<<this->m_speecher[it->second].m_score[this->m_index-1]<<endl;
            }

            int count = 0;
            for(auto it = groupscore.begin();it != groupscore.end() && count < 3;it++,count++)
            {
                if(m_index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    victory.push_back((*it).second);
                }
            }
            groupscore.clear();
            cout<<endl;
        }
    }
    cout<<"-------------------第"<<this->m_index<<"轮比赛结束----------------"<<endl;
    system("pause");

}

void SpeechManager::showscore()
{
    cout<<"----------------第"<<m_index<<"轮晋级选手-----------------"<<endl;
    vector<int> v;
    if(m_index == 1)
    {
        v = v2;
    }
    else
    {
        v = victory;
    }
    for(auto it = v.begin();it != v.end();it++)
    {
        cout<<"选手编号:"<<*it<<"姓名:"<<m_speecher[*it].m_name<<"得分:"<<
              m_speecher[*it].m_score[this->m_index - 1]<<endl;
    }
    cout<<endl;
    system("pause");
    system("cls");
    this->show_menu();
}

void SpeechManager::savescore()
{
    ofstream ofs;
    ofs.open("speech.csv",ios::out | ios::app);
    for(auto it = victory.begin();it != victory.end();it++)
    {
        ofs<<*it<<","<<m_speecher[*it].m_score[1]<<",";

    }
    ofs<<endl;
    ofs.close();
    cout<<"记录保存成功！"<<endl;
    this->fileisempty = false;
}

void SpeechManager::loadrecord()
{
    ifstream ifs("speech.csv",ios::in);
    if(!ifs.is_open())
    {
        this->fileisempty = true;
        cout<<"文件不存在！"<<endl;
        ifs.close();
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        cout<<"文件为空！"<<endl;
        this->fileisempty = true;
        ifs.close();
        return;
    }
    //文件不为空
    this->fileisempty = false;
    ifs.putback(ch);
    string date;
    int index = 0;
    while(ifs>>date)
    {
        vector<string> v;
        int pos = -1;//逗号位置
        int start = 0;
        while(1)
        {
            pos = date.find(",",start);
            if(pos == -1)
            {
                break;
            }
            string tmp = date.substr(start,pos-start);
            v.push_back(tmp);
            start = pos + 1;
        }
        this->m_record.insert(make_pair(index,v));
        index++;
    }
    ifs.close();
}

void SpeechManager::showrecord()
{
    if(this->fileisempty)
    {
        cout<<"文件为空，或者文件不存在！"<<endl;
    }
    for(int i = 0;i < (int)this->m_record.size();i++)
    {
        cout<<"第"<<i + 1<<"届"<<
              "冠军编号："<<this->m_record[i][0]<<"得分："<<this->m_record[i][1]<<" "
              "亚军编号："<<this->m_record[i][2]<<"得分："<<this->m_record[i][3]<<" "
              "季军编号："<<this->m_record[i][4]<<"得分："<<this->m_record[i][5]<<endl;
    }
    system("pause");
    system("cls");
}

void SpeechManager::cleanrecord()
{
    cout<<"确认清空？"<<endl;
    cout<<"1.确认"<<endl;
    cout<<"2.返回"<<endl;
    int select;
    cin>>select;
    if(select == 1)
    {
        ofstream ofs("speech.csv",ios::trunc);
        ofs.close();

        this->initSpeecher();
        this->createspeeher();
        this->loadrecord();
        cout<<"清除成功！"<<endl;
    }
    system("pause");
    system("cls");
}
SpeechManager::~SpeechManager()
{

}
