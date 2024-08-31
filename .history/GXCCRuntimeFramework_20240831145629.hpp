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
std::string getLatestVersion() {
    // PowerShell command to get the latest version from GitHub API
    std::string psCommand = R"(
    $owner = "Lisu-Liso"
    $repo = "GXCC"
    $url = "https://api.github.com/repos/$owner/$repo/releases/latest"
    $response = Invoke-RestMethod -Uri $url -Headers @{ "User-Agent" = "PowerShell" }
    $latestVersion = $response.tag_name
    Write-Output $latestVersion
    )";
    
    // Execute the PowerShell command and get the output
    std::string command = "powershell -Command \"" + psCommand + "\"";
    std::string output = exec(command);

    // Trim any leading or trailing whitespace
    output.erase(0, output.find_first_not_of(" \n\r\t"));
    output.erase(output.find_last_not_of(" \n\r\t") + 1);

    return output;
}
bool isGXCCrunning(){
    int id=ProcessName2Pid("GXCC_Core.exe");
    return id;  // If id != 0 return 1
}

#endif