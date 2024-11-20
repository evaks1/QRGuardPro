#ifndef SAFETYEVALUATOR_H
#define SAFETYEVALUATOR_H

#include <string>

// Abstract base class
class SafetyEvaluatorBase {
public:
    // Pure virtual 
    virtual bool evaluate(const std::string& url) = 0;
    virtual bool isHTTPS(const std::string& url) = 0;
    virtual std::string extractDomain(const std::string& url) = 0;
};

// Derived 
class SafetyEvaluator : public SafetyEvaluatorBase {
public:
    // Override 
    bool evaluate(const std::string& url) override;
    bool isHTTPS(const std::string& url) override;
    std::string extractDomain(const std::string& url) override;

private:
    // CURL callback function
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // SAFETYEVALUATOR_H