#include <iostream>
#include <cstdio>
#include <string>
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
        string str;
        while((c=fgetc(stream))!=-1){
            str+=c;
        }
        fclose(stream);
        string dir;
        for(int i=0;i<str.size()-8;i++){
            if(str[i]=='\"') dir+=
            dir+=str[i];
        }
        FILE* stream=fopen(".\\Result.json","w");
        fprintf(stream,"{\n    \"information\": \"%s\"\n}",dir.c_str());
        fclose(stream);
    }
    return 0;
}