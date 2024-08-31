#include 
int main(){
    FILE* stream=fopen("Result.json","w");
    fprintf(stream,"{\n    \"GXCCDirPath\": \"%s\"\n}",getdirpath());
    return 0;
}