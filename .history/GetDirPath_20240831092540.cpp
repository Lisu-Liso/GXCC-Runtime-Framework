#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
#include <string>
using namespace std;
int main(int argc,char* argv[]){
    if(argc==2){
        FILE* stream=fopen(argv[1],"w");
        fprintf(stream,"{\n    \"information\": \"%s\"\n}",formatpathinjson(getdirpath()).c_str());
        fclose(stream);
    }
    return 0;
}