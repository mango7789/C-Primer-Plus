#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

char toLower(char c) { return tolower(c); }
string& ToLower(string& s);
void display(const string& s);

int main() {
    vector<string> words;
    cout << "Enter words:\n";
    string input;
    while (cin >> input && input != "quit") {
        words.push_back(input);
    }

    for_each(words.begin(), words.end(), display);
    cout << endl;

    set<string> wordset;
    transform(words.begin(), words.end(), inserter(wordset, wordset.begin()), ToLower);
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    map<string, int> wordcount;
    set<string>::iterator iter;
    for (iter = wordset.begin(); iter != wordset.end(); ++iter) {
        wordcount[*iter] = count(words.begin(), words.end(), *iter);
    }
    for (iter = wordset.begin(); iter != wordset.end(); ++iter) {
        cout << *iter << ": " << wordcount[*iter] << endl;
    }

    return 0;
}

string& ToLower(string& s) {
    transform(s.begin(), s.end(), s.begin(), toLower);
    return s;
}

void display(const string& s) { cout << s << " "; }