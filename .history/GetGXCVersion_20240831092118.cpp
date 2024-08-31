#include "GXCCRuntimeFramework.hpp"
#include <string>
#include <iostream>
using namespace std;
int main(){
    
        FILE* stream=fopen("Result.json","w");
        fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
        fclose(stream);
    return 0;
}