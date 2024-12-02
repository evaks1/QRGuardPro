#include "../include/SafetyEvaluator.h"
#include <curl/curl.h>
#include <iostream>
#include <cstdlib>

// Override: Check if URL starts with HTTPS
bool SafetyEvaluator::isHTTPS(const std::string& url) {
    return url.find("https://") == 0;
}

// Override: Extract domain from URL
std::string SafetyEvaluator::extractDomain(const std::string& url) {
    size_t start = url.find("://");
    if (start == std::string::npos) return "";
    start += 3;
    size_t end = url.find('/', start);
    if (end == std::string::npos) end = url.length();
    return url.substr(start, end - start);
}

// Override: Main evaluation function
bool SafetyEvaluator::evaluate(const std::string& url) {
    std::string domain = extractDomain(url);
    if (domain.empty()) return false;

    // Get API key from environment variable
    const char* apiKeyEnv = std::getenv("GOOGLE_SAFE_BROWSING_API_KEY");
    if (apiKeyEnv == nullptr) {
        std::cerr << "Error: GOOGLE_SAFE_BROWSING_API_KEY environment variable not set." << std::endl;
        return false;
    }
    std::string apiKey(apiKeyEnv);

    // Construct API URL
    std::string apiURL = "https://safebrowsing.googleapis.com/v4/threatMatches:find?key=" + apiKey;

    // Construct JSON payload
    std::string jsonPayload = R"(
    {
      "client": {
        "clientId":      "QRGuardPro",
        "clientVersion": "1.0"
      },
      "threatInfo": {
        "threatTypes":      ["MALWARE", "SOCIAL_ENGINEERING"],
        "platformTypes":    ["ANY_PLATFORM"],
        "threatEntryTypes": ["URL"],
        "threatEntries": [
          {"url": ")" + domain + R"("}
        ]
      }
    }
    )";

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, apiURL.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, SafetyEvaluator::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "CURL Error: " << curl_easy_strerror(res) << std::endl;
            return false;
        }

        // Parse the response to determine if the domain is safe
        if (readBuffer.find("\"matches\": [") != std::string::npos) {
            return false; // Domain is potentially unsafe
        } else {
            return true; // Domain is safe
        }
    }
    return false;
}

// Static callback function for CURL to write received data
size_t SafetyEvaluator::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}