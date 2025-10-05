// created movie class with functions
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Struct for each review node
struct Node {
    double rating;
    string comment;
    Node* next;
};

// Class that stores movie title and linked list of reviews
class Movie {
private:
    string title;
    Node* head;

public:
    // constructor initializes movie title and empty list
    Movie(string t) {
        title = t;
        head = nullptr;
    }

    // add new review at tail (default)
    void addReview(double rating, string comment) {
        Node* temp = new Node;
        temp->rating = rating;
        temp->comment = comment;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    // print all reviews and calculate average
    void displayReviews() {
        cout << "\nMovie: " << title << endl;
        Node* current = head;
        int count = 0;
        double total = 0.0;

        while (current != nullptr) {
            count++;
            cout << "    > Review #" << count << ": " << current->rating
                 << " - " << current->comment << endl;
            total += current->rating;
            current = current->next;
        }

        if (count > 0)
            cout << "    > Average: " << total / count << endl;
        else
            cout << "No reviews yet.\n";
    }
};

// main function now just uses the class
int main() {
    Movie m("Sample Movie");

    char again;
    do {
        double rating;
        string comment;

        cout << "Enter review rating 0–5: ";
        cin >> rating;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter review comment: ";
        getline(cin, comment);

        m.addReview(rating, comment);

        cout << "Add another review? (Y/N): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (again == 'Y' || again == 'y');

    m.displayReviews();

    return 0;
}
