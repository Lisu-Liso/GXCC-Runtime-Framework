#include <cstdio>
#include "GXCCRuntimeFramework.hpp"
using namespace std;
using namespace GXCCRuntimeFramework;
int main(int argc,char* argv[]){
    if(argc==2){
        string version=getlatestversion();
        FILE* stream=fopen(argv[1],"w");
        fprintf(stream,"%s\"\n}",getlatestversion().c_str());
        fclose(stream);
        return 0;
    }else return 1;
    return 0;
}