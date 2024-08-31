#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
using Json=nlohmann::json;

// Callback function to write data to a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
    size_t totalSize = size * nmemb;
    userData->append((char*)contents, totalSize);
    return totalSize;
}

std::string getLatestRelease(const std::string& owner, const std::string& repo) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::string url = "https://api.github.com/repos/" + owner + "/" + repo + "/releases/latest";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "User-Agent: C++");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    // Parse JSON response
    Json::CharReaderBuilder readerBuilder;
    Json::Value jsonData;
    std::istringstream s(readBuffer);
    std::string errs;

    if (Json::parseFromStream(readerBuilder, s, &jsonData, &errs)) {
        return jsonData["tag_name"].asString();
    } else {
        return "Error parsing JSON";
    }
}

int main() {
    std::string owner = "octocat";
    std::string repo = "Hello-World";
    std::string latestVersion = getLatestRelease(owner, repo);
    std::cout << "The latest version of " << repo << " is " << latestVersion << std::endl;
    return 0;
}
