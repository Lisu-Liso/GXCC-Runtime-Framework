#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    FILE* stream=fopen("Result.json","w");
    string dirpath=getdirpath();
    for()
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",dirpath.c_str());
    fclose(stream);
    return 0;
}