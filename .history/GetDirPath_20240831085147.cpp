#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    FILE* stream=fopen("C:\\GXCC\\path.txt","r");
    if(!stream){
        FILE* stream=fopen(".\\Result.json","w");
        
    }
    return 0;
}