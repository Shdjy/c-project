#ifndef ORDERFILE_H
#define ORDERFILE_H

#endif // ORDERFILE_H

#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"file.h"
using namespace std;

class Orderfile
{
public:
    Orderfile();

    void updateorder();

    map<int,map<string,string>> m_orderdata;

    int m_size;
};
