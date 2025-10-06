// Lab 19 - Abstract & Automate Lab 18
// Commit 3: Added Movie class, automated review.txt w key phrases and also avg. Next will be tying it all together.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time() seed
#include <iomanip>   // for setprecision()
using namespace std;

// Each node stores one review
struct Node {
    double rating;
    string comment;
    Node* next;
};

// Linked list function: add node to head
void addToHead(Node*& head, double rating, string comment) {
    Node* temp = new Node;
    temp->rating = rating;
    temp->comment = comment;
    temp->next = head;
    head = temp;
}

// Movie class (title + linked list of reviews)
class Movie {
private:
    string title;
    Node* head;  // linked list of reviews

public:
    Movie(string t) {
        title = t;
        head = nullptr;
    }

    // Add a review (always adds to head)
    void addReview(double rating, string comment) {
        addToHead(head, rating, comment);
    }

    // Display all reviews and calculate average
    void display() {
        cout << "Movie: " << title << endl;
        Node* current = head;
        int count = 0;
        double total = 0.0;

        while (current != nullptr) {
            count++;
            cout << fixed << setprecision(1);
            cout << "    > Review #" << count << ": "
                 << current->rating << " - "
                 << current->comment << endl;
            total += current->rating;
            current = current->next;
        }

        if (count > 0)
            cout << "    > Average: " << total / count << endl;
        else
            cout << "    > No reviews available." << endl;

        cout << endl;
    }
};

