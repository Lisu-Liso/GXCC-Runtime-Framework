#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    FILE* stream=fopen("C:\\GXCC\\path.txt","r");
    if(!stream){
        FILE* stream=fopen(".\\Result.json","w");
        fprintf(stream,"{\n    \"information\": \"ERROR IN RUNNING.\"\n}");
        fclose(stream);
        return 1;
    }else{
        int c=0;
        while((c=fgetc(stream)))
    }
    return 0;
}