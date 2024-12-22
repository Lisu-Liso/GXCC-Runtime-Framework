#include <string>
#include "GXCCRuntimeFramework.hpp"
using namespace std;
using namespace GXCCRuntimeFramework;
int main(int argc,char *argv[]){
    if(argc==2){
        string str=argv[1];
        if(str.size()!=8) return 3;
    }
    if(argc==2) return !GetStartWithGXCC(argv[1]);
    else return 2;
}