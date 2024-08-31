#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    FILE* stream=fopen("Result.json","w");
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",formatpathinjson());
    fclose(stream);
    return 0;
}