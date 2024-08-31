#include "GXCCRuntimeFramework.hpp"
#include <string>
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
        FILE* stream=fopen("Result.json","w");
        fprintf(stream,"{\n    \"information\": \"%s\"\n}",getdirpath());
        fclose(stream);
    return 0;
}