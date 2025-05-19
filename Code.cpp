#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Feed {
    string type;
    string title;
    string category;
};

// Function to display feeds based on selected categories
void displayFilteredFeeds(const vector<Feed>& feeds, const vector<string>& allowedCategories, const string& modeName) {
    cout << "\n--- Mode: " << modeName << " ---\n";
    bool found = false;
    for (const auto& feed : feeds) {
        if (find(allowedCategories.begin(), allowedCategories.end(), feed.category) != allowedCategories.end()) {
            cout << "[" << feed.type << "] " << feed.title << " (" << feed.category << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No feeds available for the selected mode.\n";
    }
}

// Function to display mode menu and return user selection
int getUserModeSelection() {
    int choice;
    cout << "\n===== Feed Filter Modes =====\n";
    cout << "1. KidsOnly (Study + Sports)\n";
    cout << "2. StudyOnly\n";
    cout << "3. SportsOnly\n";
    cout << "4. EntertainmentOnly\n";
    cout << "5. All Feeds\n";
    cout << "Choose a mode (1-5): ";
    cin >> choice;
    return choice;
}

int main() {
    vector<Feed> appFeeds = {
        {"YouTube", "Top 10 Study Hacks", "study"},
        {"News", "India Wins U19 World Cup", "sports"},
        {"YouTube", "Funny Cat Videos", "entertainment"},
        {"News", "Global Economy Update", "finance"},
        {"Info", "CBSE 10th Exam Tips", "study"},
        {"YouTube", "Football Skills 2025", "sports"},
        {"News", "Movie Release Today", "entertainment"}
    };

    cout << "===== App Feed Control Simulation =====\n";

    int mode = getUserModeSelection();

    vector<string> selectedCategories;
    string modeName;

    switch (mode) {
        case 1:
            selectedCategories = {"study", "sports"};
            modeName = "KidsOnly";
            break;
        case 2:
            selectedCategories = {"study"};
            modeName = "StudyOnly";
            break;
        case 3:
            selectedCategories = {"sports"};
            modeName = "SportsOnly";
            break;
        case 4:
            selectedCategories = {"entertainment"};
            modeName = "EntertainmentOnly";
            break;
        case 5:
            for (const auto& feed : appFeeds)
                selectedCategories.push_back(feed.category);  // Allow all categories
            modeName = "All";
            break;
        default:
            cout << "Invalid choice. Defaulting to KidsOnly mode.\n";
            selectedCategories = {"study", "sports"};
            modeName = "KidsOnly";
    }

    displayFilteredFeeds(appFeeds, selectedCategories, modeName);

    return 0;
}
