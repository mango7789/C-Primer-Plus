#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

bool FillReview(Review& r);
void ShowReview(const Review& r);

int main() {
    using std::cout;
    using std::endl;
    using std::vector;

    vector<Review> books;
    Review temp;

    while (FillReview(temp)) {
        books.push_back(temp);
    }
    int num = books.size();

    if (num > 0) {
        cout << "Thank you. You entered the following:\n"
             << "Rating\tBook\n";
        for (int i = 0; i < num; i++) {
            ShowReview(books[i]);
        }

        cout << "Reprising:\n"
             << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++) {
            ShowReview(*pr);
        }

        vector<Review> oldList(books);

        if (num > 3) {
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After removing 2 items:\n"
                 << "Rating\tBook\n";
            for (pr = books.begin(); pr != books.end(); pr++) {
                ShowReview(*pr);
            }

            // insert 1 items
            books.insert(books.begin(), oldList.begin() + 1,
                         oldList.begin() + 2);
            cout << "After inserting 1 items:\n"
                 << "Rating\tBook\n";
            for (pr = books.begin(); pr != books.end(); pr++) {
                ShowReview(*pr);
            }
        }

        books.swap(oldList);
        cout << "After swapping:\n"
             << "Rating\tBook\n";
        for (pr = books.begin(); pr != books.end(); pr++) {
            ShowReview(*pr);
        }
    } else {
        cout << "No reviews entered.\n";
    }

    return 0;
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