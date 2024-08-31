#include <iostream>
#include <fstream>
#include "GXCCRuntimeFramework.hpp"
using namespace std;

int main(int argc,char* argv[]){
    if(argc==2){
        string version=getlatestversion();
        ofstream fout;
        fout.open(argv[1]);
        fout<<"{\n    \"information\": \"";
        fout<<version;
        fout<<"\"\n}";
        fout.close();
        // FILE* stream=fopen(argv[1],"w");
        // fprintf(stream,"{\n    \"information\": \"%s\"\n}",getlatestversion().c_str());
        // fclose(stream);
        return 0;
    }else return 1;
    return 0;
}