#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    FILE* stream=fopen("Result.json","w");
    string dirpath=getdirpath();
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",dirpath);
    fclose(stream);
    return 0;
}