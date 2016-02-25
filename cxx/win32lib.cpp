#include <Windows.h>
#include <iostream>
#include <string>
#include "icbc.h"
using namespace std;

string get_icbc_ver()
{
    init_icbc();
    string ver = GetDllVersion();
    MessageBox(NULL, ver.c_str(), ver.c_str(),MB_OK); 
    return ver;
}
string test_cpp()
{    
    string ver = "Hello world from c++";
    //MessageBox(NULL, ver.c_str(), ver.c_str(),MB_OK); 
    //ver = GetDllVersion();
    return ver;
}
