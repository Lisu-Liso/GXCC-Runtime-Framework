#include <iostream>
#include <fstream>
#include <sstream>
#include "GXCCRuntimeFramework.hpp"
using namespace std;
int main(int argc,char* argv[]){
    if(argc==2||1){
        stringstream ss;
        ss<<getlatestversion();
        string str=getlatestversion();
        cout<<str.c_str();
        // FILE* stream=fopen(argv[1],"w");
        // fprintf(stream,"{\n    \"information\": \"%s\"\n}",getlatestversion().c_str());
        // fclose(stream);
        return 0;
    }else return 1;
    return 0;
}