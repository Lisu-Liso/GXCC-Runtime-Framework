#ifndef __GXCCRUNTIMEFRAMEWORK_H__
#define __GXCCRUNTIMEFRAMEWORK_H__

#include <cstdio>
#include <string>
#include "json.hpp"

bool iserrorinrunning(std::string data){
    if(data=="ERROR IN RUNNING.") return 1;
    return 0;
}
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
        return str;
    }
}
std::string formatpathinjson(std::string path){
    std::string formatpath;
    for(int i=0;i<path.size()-8;i++){
        if(path[i]=='\"'||path[i]=='\\') formatpath+='\\';
        formatpath+=path[i];
    }
    return formatpath;
}
std::string getversion(){
    std::string dirpath=getdirpath();
    if(iserrorinrunning()){
        return dirpath;
    }else{
        std::string versionfilepath=dirpath+"version.GXv";
        FILE* stream=fopen(versionfilepath.c_str(),"r");
    }
}

#endif