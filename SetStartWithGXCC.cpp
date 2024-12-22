#include <string>
#include "GXCCRuntimeFramework.hpp"
using namespace std;
using namespace GXCCRuntimeFramework;
int main(int argc,char *argv[]){
    if(argc>=2){
        string str=argv[1];
        if(str.size()!=8) return 3;
        if(argc==2) return !SetStartWithGXCC(argv[1]);
        else{
            string argv2=argv[2];
            if(argv2=="Set"){
                return !SetStartWithGXCC(argv[1]);
            }else if(argv2=="Not"){
                return !SetStartWithGXCC(argv[1],0);
            }
        }
    }
    else return 2;
}