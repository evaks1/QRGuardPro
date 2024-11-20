#ifndef SAFETYEVALUATOR_H
#define SAFETYEVALUATOR_H

#include <string>

/**
 * @class SafetyEvaluatorBase
 * @brief An abstract base class for evaluating URL safety.
 *
 * The SafetyEvaluatorBase class defines a blueprint for URL safety evaluation,
 * requiring derived classes to implement methods for evaluating URLs, checking HTTPS,
 * and extracting domains.
 */
class SafetyEvaluatorBase {
public:
    /**
     * @brief Virtual destructor for SafetyEvaluatorBase.
     */
    virtual ~SafetyEvaluatorBase() = default;

    /**
     * @brief Evaluates the safety of a given URL.
     * @param url The URL to evaluate.
     * @return True if the URL is deemed safe, false otherwise.
     */
    virtual bool evaluate(const std::string& url) = 0;

    /**
     * @brief Checks if a URL uses the HTTPS protocol.
     * @param url The URL to check.
     * @return True if the URL starts with "https://", false otherwise.
     */
    virtual bool isHTTPS(const std::string& url) = 0;

    /**
     * @brief Extracts the domain from a given URL.
     * @param url The URL to process.
     * @return A std::string containing the domain of the URL.
     */
    virtual std::string extractDomain(const std::string& url) = 0;
};

/**
 * @class SafetyEvaluator
 * @brief A concrete implementation of SafetyEvaluatorBase for evaluating URL safety.
 *
 * The SafetyEvaluator class implements the methods defined in SafetyEvaluatorBase,
 * providing functionality for evaluating URLs using external services,
 * checking HTTPS status, and extracting domains.
 */
class SafetyEvaluator : public SafetyEvaluatorBase {
public:
    /**
     * @brief Evaluates the safety of a given URL.
     * 
     * This implementation uses the Google Safe Browsing API to check if the URL
     * is associated with known threats.
     * @param url The URL to evaluate.
     * @return True if the URL is deemed safe, false otherwise.
     */
    bool evaluate(const std::string& url) override;

    /**
     * @brief Checks if a URL uses the HTTPS protocol.
     * @param url The URL to check.
     * @return True if the URL starts with "https://", false otherwise.
     */
    bool isHTTPS(const std::string& url) override;

    /**
     * @brief Extracts the domain from a given URL.
     * @param url The URL to process.
     * @return A std::string containing the domain of the URL.
     */
    std::string extractDomain(const std::string& url) override;

private:
    /**
     * @brief A callback function for handling data received via CURL.
     * @param contents Pointer to the data received.
     * @param size Size of each data element.
     * @param nmemb Number of elements.
     * @param userp Pointer to the user-defined data to write to.
     * @return The total number of bytes processed.
     */
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // SAFETYEVALUATOR_H