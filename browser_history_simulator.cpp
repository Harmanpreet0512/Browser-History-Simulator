#include <iostream>
#include <deque>
using namespace std;

class BrowserHistory {
private:
    deque<string> history;   // stores all visited URLs
    int current;             // index of the current page

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
    }

    // Visit a new URL
    void visit(string url) {
        // Remove all "forward" history after current page
        while ((int)history.size() > current + 1) {
            history.pop_back();
        }
        history.push_back(url);
        current++;
        cout << "Visited: " << url << endl;
    }

    // Go back 'steps' pages
    void back(int steps) {
        if (current == 0) {
            cout << "Already at the oldest page. Can't go back.\n";
            return;
        }
        current = max(0, current - steps);
        cout << "Went back to: " << history[current] << endl;
    }

    // Go forward 'steps' pages
    void forward(int steps) {
        if (current == (int)history.size() - 1) {
            cout << "Already at the latest page. Can't go forward.\n";
            return;
        }
        current = min((int)history.size() - 1, current + steps);
        cout << "Went forward to: " << history[current] << endl;
    }

    // Show current page
    void showCurrent() {
        cout << "Current page: " << history[current] << endl;
    }

    // Show full history (for debugging / understanding)
    void showAllHistory() {
        cout << "\n--- Full History ---\n";
        for (int i = 0; i < (int)history.size(); i++) {
            if (i == current)
                cout << "-> " << history[i] << "  (current)\n";
            else
                cout << "   " << history[i] << endl;
        }
        cout << "---------------------\n";
    }
};

int main() {
    string homepage = "google.com";
    BrowserHistory browser(homepage);

    int choice;
    string url;
    int steps;

    while (true) {
        cout << "\n===== Browser History Simulator =====\n";
        cout << "1. Visit new URL\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Show Full History\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL to visit: ";
                cin >> url;
                browser.visit(url);
                break;
            case 2:
                cout << "Enter steps to go back: ";
                cin >> steps;
                browser.back(steps);
                break;
            case 3:
                cout << "Enter steps to go forward: ";
                cin >> steps;
                browser.forward(steps);
                break;
            case 4:
                browser.showCurrent();
                break;
            case 5:
                browser.showAllHistory();
                break;
            case 6:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
