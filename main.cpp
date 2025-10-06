// Lab 19 - Abstract & Automate Lab 18
// Commit 3: Added Movie class, automated review generation from file that reads from reviews.txt

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

int main() {
    srand(time(0));  // seed for random ratings

    // Load comments from file
    vector<string> comments;
    ifstream file("reviews.txt");
    string line;

    if (!file) {
        cerr << "Error: reviews.txt not found." << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (!line.empty())
            comments.push_back(line);
    }
    file.close();

    // Create movies
    vector<Movie> movies = {
        Movie("Inception"),
        Movie("The Batman"),
        Movie("Interstellar"),
        Movie("Avatar 2")
    };

    // Give each movie 3 random reviews
    for (auto& movie : movies) {
        for (int i = 0; i < 3; i++) {
            double rating = (rand() % 41 + 10) / 10.0;  // 1.0–5.0
            string comment = comments[rand() % comments.size()];
            movie.addReview(rating, comment);
        }
    }

    // Display all movie reviews
    for (auto& movie : movies) {
        movie.display();
    }

    return 0;
}
