// Final Working Version 
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Each node below stores a movie review that consists of rating, comment, and pointer to next
struct Node {
    double rating;
    string comment;
    Node* next;
};

// Adds a new review at the head of the linked list
void addToHead(Node*& head, double rating, string comment) {
    Node* temp = new Node;
    temp->rating = rating;
    temp->comment = comment;
    temp->next = head;
    head = temp;
}

// Adds a new review at the tail of the linked list
void addToTail(Node*& head, double rating, string comment) {
    Node* temp = new Node;
    temp->rating = rating;
    temp->comment = comment;
    temp->next = nullptr;

    if (head == nullptr) {
        head = temp; // first node in list
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = temp;
    }
}

int main() {
    cout << "Which linked list method should we use?\n";
    cout << "[1] New nodes are added at the head of the linked list\n";
    cout << "[2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Node* head = nullptr;
    char again;

    // have to loop here collect reviews
    do {
        double rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter review comments: ";
        getline(cin, comment);

        // Add review based on the movies ratin
        if (choice == 1)
            addToHead(head, rating, comment);
        else
            addToTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (again == 'Y' || again == 'y');

    // Traverse and output all reviews, also calculate average
    cout << "\nOutputting all reviews:\n";
    Node* current = head;
    int count = 0;
    double total = 0.0;

    while (current != nullptr) {
        count++;
        cout << "    > Review #" << count << ": " << current->rating 
             << ": " << current->comment << endl;
        total += current->rating;
        current = current->next;
    }

    // Below display's average rating
    if (count > 0)
        cout << "    > Average: " << total / count << endl;
    else
        cout << "No reviews entered.\n";

    return 0;
}