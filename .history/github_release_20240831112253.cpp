#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

// 用于处理 libcurl 的回调函数
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    std::string owner = "octocat";
    std::string repo = "Hello-World";
    
    std::string url = "https://api.github.com/repos/" + owner + "/" + repo + "/releases/latest";
    
    // 初始化 libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize libcurl" << std::endl;
        return 1;
    }

    std::string response_string;
    std::string header_string;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    // 发起请求
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    // 解析 JSON 响应
    Json::CharReaderBuilder readerBuilder;
    Json::Value jsonData;
    std::istringstream responseStream(response_string);
    std::string errs;

    if (!Json::parseFromStream(readerBuilder, responseStream, &jsonData, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    // 获取并显示最新 release 的版本号
    std::string latestVersion = jsonData["tag_name"].asString();
    std::cout << latestVersion << std::endl;

    // 清理
    curl_easy_cleanup(curl);
    return 0;
}
