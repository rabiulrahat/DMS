#include <bits/stdc++.h>
#include <sys/stat.h>
#include <cstring>
#include <errno.h>
#include <dirent.h>
#include "reg.h"
#ifdef _WIN64
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;
const char *fol[50];

void login();
/// its for loging
bool is_Logged_In(string username, string password);
#ifdef _WIN64
bool is_Logged_In(string username, string password)
{
    string ur_name, ps_word;

    ifstream myFile;
    myFile.open(username + ".txt",std::ios::in);
    getline(myFile, ur_name); /// it's here used for take a string line from file,
    // getline--here it's use to take a proper string;//and if you see here it is taking input from file.
    // and we store it in to  ur_name;
    getline(myFile, ps_word);
    if (ur_name == username && ps_word == password) // here we compare user argument , i mean user input user name and also password.
    {
        return true;
    }
    else
    {
        return false;
    }
}

#else
bool is_Logged_In(string username, string password)
{
    string ur_name, ps_word;

    ifstream myFile;
    myFile.open("data\\" + username + ".txt");
    getline(myFile, ur_name); /// it's here used for take a string line from file,
    // getline--here it's use to take a proper string;//and if you see here it is taking input from file.
    // and we store it in to  ur_name;
    getline(myFile, ps_word);
    if (ur_name == username && ps_word == password) // here we compare user argument , i mean user input user name and also password.
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif

void login()
{
    int option;
    cout << "\n :: :: :: :: :: :: :: :: :: :: :: :: ::LOGIN & REGISTER FORM :: :: :: :: :: :: :: :: :: :: :: :: ::  ";
    cout << " \n                       [1]: Register " << endl;
    cout << " \n                       [2]: Login " << endl;

    cout << "Enter your choice: ";
    cin >> option;
    if (option == 1)
    {
        string username;

        ofstream MFile;
        cout << " \n                       Enter username: ";
        cin >> username;

        regest(&username[0]);
        switch (regest(&username[0]))
        {
        case 0:
        system(CLEAR);
            art();
            cout << "The user name has been registered, please re-select the user name" << endl;
            login();
            break;
        case 1:
            system(CLEAR);
            cout << "Registered successfully" << endl;
            break;
        }
    }

    if (option == 2)
    {
        string username, password;

        cout << " \n                       Enter username: ";
        cin >> username;
        cout << " \n                       Enter password: ";
        cin >> password;
        #ifdef _WIN64
        string line;
        vector<string> lines;
        ifstream myFile;
        myFile.open(username + ".txt", std::ios::in);
        if (myFile.is_open())
        {
            for (int lineno = 1; getline(myFile, line) && lineno <= 3; lineno++)
                if (lineno == 3)
                    lines.push_back(line);
        }
        myFile.close();

        #else

        string line;
        vector<string> lines;
        ifstream myFile;
        myFile.open("data\\" + username + ".txt");
        if (myFile.is_open())
        {
            for (int lineno = 1; getline(myFile, line) && lineno <= 3; lineno++)
                if (lineno == 3)
                    lines.push_back(line);
        }
        myFile.close();
        #endif
        fol[50] = &line[0];
        FILE *fp;
        fp = fopen("source.txt", "w+");
        fclose(fp);
        ofstream myfile;
        myfile.open("source.txt");
        myfile << line << endl;
        myfile.close();

        bool status = is_Logged_In(username, password);

        if (!status)
        {
            cout << "Incorrect Username Or Password!" << endl;
            system(CLEAR);
            art();
            login();
        }
        else
        {
            cout << "Successfully Logged In" << endl;
            system("PAUSE");
        }
    }
}
