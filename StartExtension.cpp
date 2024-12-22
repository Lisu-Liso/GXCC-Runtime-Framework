#include <iostream>
#include <cstdlib>
#include <string>
#include "GXCCRuntimeFramework.hpp"
using namespace std;
using namespace GXCCRuntimeFramework;
int main(int argc,char *argv[]){
    if(argc!=2) return 1;
    string dir=getdirpath();
    if(iserrorinrunning(dir)) return 1;
    string argv1=argv[1];
    string cmd="powershell -c start -FilePath "+dir+"Extensions\\GXCC-EB.exe -WorkingDirectory "+dir+" -ArgumentList \""+argv1+"\"";
    system(cmd.c_str());
    return 0;
}