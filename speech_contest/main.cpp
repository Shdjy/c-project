#include <iostream>
#include<windows.h>
#include<ctime>
using namespace std;
#include"speechManager.h"
#include"speecher.h"


//学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
//每名选手都有对应的编号，如10001 ~10012
//比赛方式:分组比赛，每组6个人;
//第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲。
//十个评委分别给每名选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
//第二轮为决塞，前三名胜出
//每轮比赛过后需要显示晋级选手的信息
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    SpeechManager sm;

    srand((unsigned int)time(NULL));
    int input;
    while(1)
    {
        sm.show_menu();
        cout<<"请选择执行的功能"<<endl;
        cin>>input;
        switch (input)
        {
        case 0://退出
            sm.exitsystem();
            break;
        case 1://开始
            sm.startspeeh();
            break;
        case 2://查看
            sm.showrecord();
            break;
        case 3://清空
            sm.cleanrecord();
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
}
