#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void output(const std::string& s) { std::cout << s << " "; }

int main() {
    using namespace std;

    string s1[4] = {"fine", "fish", "fosh", "fool"};
    string s2[2] = {"dog", "cat"};
    string s3[2] = {"apple", "banana"};
    vector<string> words(4);

    //! should leave enough space for the new elements in original copy
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    //! insert iterators automatically handle resizing the vector as needed
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    return 0;
}