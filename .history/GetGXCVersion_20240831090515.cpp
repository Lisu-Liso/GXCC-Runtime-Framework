#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(){
    string dirpath=getdirpath();
    if(dirpath=="ERROR IN RUNNING."){
        FILE* stream=fopen("Result.json","w");
        fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
        fclose(stream);
    }else{
        
    }
    return 0;
}