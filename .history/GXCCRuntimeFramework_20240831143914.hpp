#ifndef __GXCCRUNTIMEFRAMEWORK_H__
#define __GXCCRUNTIMEFRAMEWORK_H__

#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include <sstream>
#include "getpid.h"

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
std::string getlatestversion() {
    int saved_stdout = dup(fileno(stdout));
    freopen("NUL", "w", stdout);  // Only for Windows

    std::string information = R"(
$owner = "Lisu-Liso"
$repo = "GXCC"
$url = "https://api.github.com/repos/$owner/$repo/releases/latest"
$response = Invoke-RestMethod -Uri $url -Headers @{ "User-Agent" = "PowerShell" }
$latestVersion = $response.tag_name
Write-Output $latestVersion  >> temp.txt
)";

    std::ofstream fout("temp.ps1");
    if (!fout) {
        std::cerr << "Failed to open temp.ps1 for writing.\n";
        return "";
    }
    fout << information;
    fout.close();

    system("powershell -Command ./temp.ps1");

    std::ifstream fin("temp.txt");
    if (!fin) {
        std::cerr << "Failed to open temp.txt for reading.\n";
        return "";
    }

    std::string version;
    std::getline(fin, version);
    fin.close();

    system("del /q /s temp.ps1");
    system("del /q /s temp.txt");

    dup2(saved_stdout, fileno(stdout));
    close(saved_stdout);

    return version;
}
bool isGXCCrunning(){
    int id=ProcessName2Pid("GXCC_Core.exe");
    return id;  // If id != 0 return 1
}

#endif