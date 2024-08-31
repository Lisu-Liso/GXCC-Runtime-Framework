#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    FILE* stream=fopen("Result.json","w");
    string dirpath;
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
    fclose(stream);
    return 0;
}