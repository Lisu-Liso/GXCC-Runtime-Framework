#ifndef __GXCCRUNTIMEFRAMEWORK_H__
#define __GXCCRUNTIMEFRAMEWORK_H__

#include <cstdio>
#include <string>
#include "json.hpp"
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
    
    string dirpath=getdirpath();
    if(dirpath=="ERROR IN RUNNING."){
        FILE* stream=fopen("Result.json","w");
        fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
        fclose(stream);
        return 1;
    }else{
        string versionfilepath=dirpath+"version.GXv";
        FILE* stream=fopen(versionfilepath.c_str(),"r");
    }
}

#endif