#ifndef __GXCCRUNTIMEFRAMEWORK_H__
#define __GXCCRUNTIMEFRAMEWORK_H__

#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "json.hpp"

bool iserrorinrunning(std::string data){
    int n=17;   // sizeof("ERROR IN RUNNING:");
    const std::string stdstr="ERROR IN RUNNING:";
    for(int i=0;i<n;i++){
        if(stdstr[i]!=data[i]) return 0;
    }
    return 1;
}
std::string getdirpath(){
    FILE* stream=fopen("C:\\GXCC\\path.txt","r");
    if(!stream){
        return "ERROR IN RUNNING: getdirpath().";
    }else{
        int c=0;
        std::string str;
        while((c=fgetc(stream))!=-1){
            str+=c;
        }
        fclose(stream);
        std::string dir;
        for(int i=0;i<str.size()-8;i++){
            dir+=str[i];
        }
        return dir;
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
std::string getversionjson(){
    std::string dirpath=getdirpath();
    if(iserrorinrunning(dirpath)){
        return dirpath;
    }else{
        std::string versionfilepath=dirpath+"version.GXv";
        FILE* stream=fopen(versionfilepath.c_str(),"r");
        if(!stream){
            return "ERROR IN RUNNING: getversionjson().";
        }
        int c=0;
        std::string versionjson;
        while((c=fgetc(stream))!=-1){
            versionjson+=c;
        }
        return versionjson;
    }
}
std::string getlatestversion(){
    // freopen("NUL","w",stdout);
    std::string information="$owner = \"Lisu-Liso\"\n$repo = \"GXCC\"\n\n$url = \"https://api.github.com/repos/$owner/$repo/releases/latest\"\n\n$response = Invoke-RestMethod -Uri $url -Headers @{ \"User-Agent\" = \"PowerShell\" }\n\n$latestVersion = $response.tag_name\nWrite-Output $latestVersion  >> temp.txt\n";
    std::ofstream fout;
    fout.open("temp.ps1");
    fout<<information;
    fout.close();
    system("powershell -Command ./temp.ps1");
    system("del /q /s temp.ps1");
    system("del /q /s temp.txt");
    re
}

#endif