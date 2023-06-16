#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct paar {
    string word;
    int count;
};

int main() {
    vector<paar> wordCount;

    string input;
    cout << "Geben Sie den Text ein: ";
    getline(cin, input);

    // Aufteilen des Eingabetextes in einzelne Wörter
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);

        // a Check for the word existence in the vector 
        bool wordExists = false;
        for (auto& p : wordCount) {
            if (p.word == token) {
                p.count++;
                wordExists = true;
                break;
            }
        }

        // When teh word NOT in vector --> generate new 
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
        cout << p.word << ": " << p.count << endl;
    }

    return 0;
}
