#include <iostream>
const int Limit = 255;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    char input[Limit];
    cout << "Enter a string for getline() processing:\n";
    cin.getline(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 1\n";

    char ch;
    cin.get(ch);
    cout << "The next input character is: " << ch << endl;

    if (ch != '\n') {
        cin.ignore(Limit, '\n');
    }

    cin.get(input, Limit, '#');
    cout << input << "\n";

    cin.get(ch);
    cout << "The next input character is: " << ch << endl;

    return 0;
}