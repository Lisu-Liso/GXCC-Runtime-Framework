#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string getdirpath(){
    FILE* stream=fopen("C:\\GXCC\\path.txt","r");
    if(!stream){
        return "ERROR IN RUNNING.";
    }else{
        int c=0;
        string str;
        while((c=fgetc(stream))!=-1){
            str+=c;
        }
        fclose(stream);
        string dir;
        for(int i=0;i<str.size()-8;i++){
            if(str[i]=='\"'||str[i]=='\\') dir+='\\';
            dir+=str[i];
        }
    }
    return 
}
int main(){
    return 0;
}