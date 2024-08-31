#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    FILE* stream=fopen("Result.json","w");
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",formatpathinjson(getdirpath()).c_str());
    fclose(stream);
    return 0;
}