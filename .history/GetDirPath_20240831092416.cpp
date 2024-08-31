#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(int argc,char* argv[]){
    if(arg)
    FILE* stream=fopen("Result.json","w");
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",formatpathinjson(getdirpath()).c_str());
    fclose(stream);
    return 0;
}