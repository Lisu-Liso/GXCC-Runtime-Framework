#include "GXCCRuntimeFramework.hpp"
#include <string>
#include <iostream>
using namespace std;
int main(){
    string dirpath=getdirpath();
    if(dirpath=="ERROR IN RUNNING."){
        FILE* stream=fopen("Result.json","w");
        fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
        fclose(stream);
        return 1;
    }else{
        string versionfilepath=dirpath+"version.GXv";
        FILE* stream=fopen(versionfilepath.c_str(),"r");
    }
    return 0;
}