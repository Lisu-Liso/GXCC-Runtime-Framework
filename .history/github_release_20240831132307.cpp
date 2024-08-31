#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

// 用于处理libcurl写入数据的回调函数
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// 获取 GitHub 最新发布版本的函数
std::string get_latest_release(const std::string& repo) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        std::string url = "https://api.github.com/repos/" + repo + "/releases/latest";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");  // GitHub API 需要 User-Agent
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    return readBuffer;
}

// 主函数
int main() {
    std::string repo = "owner/repository";  // 替换为实际的 GitHub 仓库
    std::string response = get_latest_release(repo);
    
    try {
        auto json = nlohmann::json::parse(response);
        std::string tag_name = json["tag_name"];
        std::cout << "Latest release version: " << tag_name << std::endl;
    } catch (nlohmann::json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }

    return 0;
}
