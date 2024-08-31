#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    FILE* stream=fopen("Result.json","w");
    string dirpath=getdirpath();
    string formatdirpath;
    for(int i=0;i<dirpath.size();i++){
        
    }
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",dirpath.c_str());
    fclose(stream);
    return 0;
}