// SafetyEvaluator.h
#ifndef SAFETYEVALUATOR_H
#define SAFETYEVALUATOR_H

#include <string>

class SafetyEvaluator {
public:
    SafetyEvaluator();
    ~SafetyEvaluator();

    // Main evaluation function
    bool evaluate(const std::string& url);

private:
    // Helper functions
    bool isHTTPS(const std::string& url);
    std::string extractDomain(const std::string& url);

    // CURL callback function
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // SAFETYEVALUATOR_H