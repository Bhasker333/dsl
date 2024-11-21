/*
singly LL
ass 3
*/
#include <iostream>
#include <string>
using namespace std;

// Class representing a Song
class song {
    string title;   // Title of the song
    string singer;  // Singer of the song
    float time;     // Duration of the song in minutes

public:
    song *next; // Pointer to the next song (for linked list)

    song() {
        next = NULL; // Initialize `next` pointer to NULL
    }

    // Read the song details from the user
    void read() {
        cout << "Enter the song title: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, title); // Read the title with spaces
        cout << "Enter the singer name: ";
        cin.ignore(); // Clear the input buffer again
        getline(cin, singer); // Read the singer name with spaces
        cout << "Enter duration of song: ";
        cin >> time; // Read the song duration
    }

    // Getter for the title
    string get_title() {
        return title;
    }

    // Setter for the singer
    string setsinger(string st) {
        singer = st;
        return singer;
    }

    // Display song details
    void display() {
        cout << "Song Title: " << title << "\n";
        cout << "Singer Name: " << singer << "\n";
        cout << "Duration of song: " << time << "\n";
    }
};

// Class representing the Playlist
class playlist {
    song *head; // Head pointer for the linked list of songs

public:
    playlist() {
        head = NULL; // Initialize the playlist as empty
    }

    // Add a song to the playlist
    void add_song() {
        song *nn = new song; // Create a new song object
        nn->read(); // Read song details

        if (head == NULL) {
            head = nn; // If playlist is empty, make this the first song
        } else {
            song *cn;
            // Traverse to the end of the playlist
            for (cn = head; cn->next != NULL; cn = cn->next);
            cn->next = nn; // Add the new song at the end
        }
    }

    // Delete a song by its title
    void delete_song(string title) {
        song *cn = head;
        song *prev = NULL;

        // Traverse the playlist to find the song
        while (cn != NULL && cn->get_title() != title) {
            prev = cn;
            cn = cn->next;
        }

        if (cn == NULL) {
            // If song not found
            cout << "Song not found!" << endl;
            return;
        }

        // If the song is at the head
        if (prev == NULL) {
            head = cn->next;
        } else {
            prev->next = cn->next; // Link the previous node to the next node
        }

        delete cn; // Free the memory
        cout << "Song deleted." << endl;
    }

    // Display the entire playlist
    void displayplaylist() {
        song *cn;
        for (cn = head; cn != NULL; cn = cn->next) {
            cn->display(); // Display each song
        }
    }

    // Add a song at the beginning by title
    void add_begin(string title) {
        song *nn = new song;
        for (song *cn = head; cn != NULL; cn = cn->next) {
            if (title == cn->get_title()) {
                nn->next = head;
                head = nn;
            }
        }
    }

    // Insert a song after a given title
    void insertion_at_any(string aftertitle) {
        song *cn;
        song *nn = new song;
        for (cn = head; cn != NULL; cn = cn->next) {
            if (aftertitle == cn->get_title()) {
                nn->next = cn->next;
                cn->next = nn;
            }
        }
    }

    // Modify the singer of a song
    void modify(string title, string singer) {
        song *cn;
        for (cn = head; cn != NULL; cn = cn->next) {
            if (title == cn->get_title()) {
                cn->setsinger(singer);
            }
        }
    }
};

int main() {
    playlist pg; // Playlist object
    int choice;

    while (true) {
        // Menu options
        cout << "1. Add Song\n2. Delete Song\n3. Display Playlist\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Add song(s)
                int n;
                cout << "Enter the number of songs: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    pg.add_song();
                }
                break;
            }

            case 2: { // Delete a song
                string title;
                cin.ignore(); // Clear input buffer
                cout << "Enter the title: ";
                getline(cin, title);
                pg.delete_song(title);
                break;
            }

            case 3: { // Display all songs
                pg.displayplaylist();
                break;
            }

            case 4: // Exit
                exit(0);

            default: { // Invalid input
                cout << "Invalid choice! Please enter a valid option." << endl;
            }
        }
    }

    return 0;
}
