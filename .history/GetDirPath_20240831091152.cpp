#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
int main(){
    FILE* stream=fopen("Result.json","w");
    string 
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
    fclose(stream);
    return 0;
}