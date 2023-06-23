#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct paar{
    string word;
    int count;
        };

int main() {
    vector<paar> wordCount;

    string input;
    cout << "[INPUT]:\t";
    getline(cin, input);

    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);

        // a Check for the word existence in the wordCount vector 
        bool wordExists = false;
        for (auto& p : wordCount) {
            if (p.word == token) {
                p.count++;
                wordExists = true;
                break;
            }
        }

        // When the word NOT in vector --> loadthe existing one 
        if (!wordExists) {
            paar newPair;
            newPair.word = token;
            newPair.count = 1;
            wordCount.push_back(newPair);
        }

        input.erase(0, pos + delimiter.length());
    }

    // Check last words 
    if (!input.empty()) {
        bool wordExists = false;
        for (auto& p : wordCount) {
            if (p.word == input) {
                p.count++;
                wordExists = true;
                break;
            }
        }
        if (!wordExists) {
            paar newPair;
            newPair.word = input;
            newPair.count = 1;
            wordCount.push_back(newPair);
        }
    }

    // print word len
    for (const auto& p : wordCount) {
        cout <<"[WORD]" << p.word << ": " << p.count << endl;
    }

    return 0;
}

// Test Case : 
// aa  bb bb aa aa bb aa aa