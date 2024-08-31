#include "GXCCRuntimeFramework.hpp"
#include <string>
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
    if(argc==2){
        FILE* stream=fopen(argv[1],"w");
        fprintf(stream,"{\n    \"information\": \"%s\"\n}",get.c_str());
        fclose(stream);
        return 0;
    }else return 1;
    return 0;
}