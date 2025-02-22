#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

class StringProcessor {
private:
    std::string text;

public:
    StringProcessor(const std::string& input) : text(input) {}

    // Extract all numbers
    std::vector<int> getNumbers() {
        std::vector<int> numbers;
        std::stringstream ss(text);
        std::string word;
        while (ss >> word) {
            if (std::all_of(word.begin(), word.end(), ::isdigit)) {
                numbers.push_back(std::stoi(word));
            }
        }
        return numbers;
    }

    // Get word frequency
    std::map<std::string, int> getWordFrequency() {
        std::map<std::string, int> freq;
        std::stringstream ss(text);
        std::string word;
        while (ss >> word) {
            std::transform(word.begin(), word.end(),
                         word.begin(), ::tolower);
            freq[word]++;
        }
        return freq;
    }

    // Format as HTML
    std::string toHTML() {
        std::string html = "<p>";
        for (char& c : text) {
            if (c == '\n') {
                html += ' ';
            } else {
                html += c;
            }
        }
        html += "</p>";
        return html;
    }

    // Extract emails
    std::vector<std::string> getEmails() {
        std::vector<std::string> emails;
        std::stringstream ss(text);
        std::string word;
        while (ss >> word) {
            if (word.find('@') != std::string::npos) {
                emails.push_back(word);
            }
        }
        return emails;
    }

    // Format as CSV
    std::string toCSV() {
        std::stringstream ss(text);
        std::string word, csv;
        while (ss >> word) {
            if (!csv.empty()) csv += ",";
            csv += word;
        }
        return csv;
    }
};

int main() {
    std::string input = "Hello world! Contact us at "
                  "info@example.com or support@example.com. "
                  "Items: 42 and 73";

    StringProcessor proc(input);

    // Extract numbers
    auto numbers = proc.getNumbers();
    std::cout << "Numbers found: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // Get word frequency
    auto freq = proc.getWordFrequency();
    std::cout << "\nWord frequency:" << std::endl;
    for (const auto& [word, count] : freq) {
        std::cout << word << ": " << count << std::endl;
    }

    // Show HTML
    std::cout << "\nHTML format:" << std::endl;
    std::cout << proc.toHTML() << std::endl;

    // Show emails
    std::cout << "\nEmails found:" << std::endl;
    for (const auto& email : proc.getEmails()) {
        std::cout << email << std::endl;
    }

    // Show CSV
    std::cout << "\nCSV format:" << std::endl;
    std::cout << proc.toCSV() << std::endl;

    return 0;
}
