#include <iostream>
#include <fstream>
#include "GXCCRuntimeFramework.hpp"
using namespace std;
int main(){
    if(argc==2){
        FILE* stream=fopen(argv[1],"w");
        fprintf(stream,"{\n    \"information\": \"%s\"\n}",getversionjson().c_str());
        fclose(stream);
        return 0;
    }else return 1;
    return 0;
}