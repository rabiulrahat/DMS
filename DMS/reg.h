#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "last.c"
#ifdef _WIN64
#include <windows.h>
#include <process.h>
#define NAME_MAX 255
#endif
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::setw;
using std::string;
string name, password;
char nam[50];
char dirName[NAME_MAX + 1];

int regest(char usrname[20])
{
    name = usrname[20];
    nam[50] = usrname[20];
    string temp;
    int flag = 0;
    int i = 0;
    ifstream fin("userlist.txt", ios::in);
    ofstream fout("userlist.txt", ios::app);
    while (std::getline(fin, temp))
    {
        if (!strcmp(usrname, temp.c_str()))
            flag = 1;
    }
    fin.close();
    if (flag)
    {
        return 0;
    }
    else
    {

        fout << usrname << endl;
        fout.close();
        cout << " \n                       Enter you user name once again: ";

        cin >> name;
        int pid = getpid();
        char *prefix = nam;

        snprintf(dirName, NAME_MAX + 1, "%s%d", nam, pid);
        #ifdef _WIN64
        dircreat(&dirName[0]);
        #else
        dircreat(nam, dirName, pid);
        #endif
        cout << " \n                       Enter password: ";
        cin >> password;
        ofstream MyFile;
       #ifdef _WIN64
        MyFile.open(name + ".txt",std::ios::out);
        #else
        MyFile.open("data\\" + name + ".txt");
        #endif
        MyFile << usrname << endl
               << password << endl;
        MyFile << dirName;
        MyFile.close();
        cout << "Registered successfully" << endl;
    return 1;
    }
    return 0;
}
