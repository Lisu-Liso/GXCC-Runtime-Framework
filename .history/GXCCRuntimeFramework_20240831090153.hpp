#ifndef __GXCCRUNTIMEFRAMEWORK_H__
#define __GXCCRUNTIMEFRAMEWORK_H__

#include <cstdio>
#include <string>
std::string getdirpath(){
    FILE* stream=fopen("C:\\GXCC\\path.txt","r");
    if(!stream){
        return "ERROR IN RUNNING.";
    }else{
        int c=0;
        std::string str;
        while((c=fgetc(stream))!=-1){
            str+=c;
        }
        fclose(stream);
        std::string dir;
        for(int i=0;i<str.size()-8;i++){
            if(str[i]=='\"'||str[i]=='\\') dir+='\\';
            dir+=str[i];
        }
        return dir;
    }
}

#endif