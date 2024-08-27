#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool FillReview(Review& r);
void ShowReview(const Review& r);

int main() {
    using namespace std;

    vector<Review> books;
    Review temp;
    while (FillReview(temp)) {
        books.push_back(temp);
    }

    if (books.size() > 0) {
        for_each(books.begin(), books.end(), ShowReview);
        cout << endl;

        sort(books.begin(), books.end());
        for_each(books.begin(), books.end(), ShowReview);
        cout << endl;

        sort(books.begin(), books.end(), worseThan);
        for_each(books.begin(), books.end(), ShowReview);
        cout << endl;

        random_shuffle(books.begin(), books.end());
        for_each(books.begin(), books.end(), ShowReview);
        cout << endl;
    }

    cout << "Done." << endl;

    return 0;
}

bool operator<(const Review& r1, const Review& r2) {
    if (r1.title < r2.title) {
        return true;
    } else if (r1.title == r2.title && r1.rating < r2.rating) {
        return true;
    } else {
        return false;
    }
}

bool worseThan(const Review& r1, const Review& r2) {
    return r1.rating < r2.rating;
}

bool FillReview(Review& r) {
    std::cout << "Enter title: ";
    std::getline(std::cin, r.title);
    if (r.title == "quit") {
        return false;
    }

    std::cout << "Enter rating: ";
    std::cin >> r.rating;
    if (!std::cin) {
        return false;
    }

    while (std::cin.get() != '\n') {
        continue;
    }
    return true;
}

void ShowReview(const Review& r) {
    std::cout << r.rating << "\t" << r.title << std::endl;
}