#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

struct Feed {
    string type;
    string title;
    string category;
    string subcategory; 
};

void displayFilteredFeeds(const vector<Feed>& feeds, const vector<string>& allowedCategories,
                          const string& modeName, const string& subcategory = "") {
    cout << "\n--- Mode: " << modeName;
    if (!subcategory.empty()) {
        cout << " (" << subcategory << ")";
    }
    cout << " ---\n";
    bool found = false;
    for (const auto& feed : feeds) {
        if (find(allowedCategories.begin(), allowedCategories.end(), feed.category) != allowedCategories.end()) {
            if (subcategory.empty() || feed.subcategory == subcategory) {
                cout << "[" << feed.type << "] " << feed.title << " (" << feed.category;
                if (!feed.subcategory.empty()) {
                    cout << " - " << feed.subcategory;
                }
                cout << ")\n";
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No feeds available for the selected mode";
        if (!subcategory.empty()) {
            cout << " and subcategory";
        }
        cout << ".\n";
    }
}


int getUserModeSelection() {
    int choice;
    cout << "\n===== Feed Filter Modes =====\n";
    cout << "1. KidsOnly (Study + Sports)\n";
    cout << "2. StudyOnly\n";
    cout << "3. SportsOnly\n";
    cout << "4. EntertainmentOnly\n";
    cout << "5. All Feeds\n";
    cout << "Choose a mode (1-5): ";
    while (!(cin >> choice) || choice < 1 || choice > 5) {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

// Function to get study subcategory selection
string getStudySubcategory() {
    int subChoice;
    cout << "\nSelect the type of study content you need:\n";
    cout << "1. Class 1–10\n";
    cout << "2. Intermediate\n";
    cout << "3. B.Tech\n";
    cout << "4. Degree\n";
    cout << "5. Research\n";
    cout << "Choose an option (1-5): ";
    while (!(cin >> subChoice) || subChoice < 1 || subChoice > 5) {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (subChoice) {
        case 1: return "Class 1–10";
        case 2: return "Intermediate";
        case 3: return "B.Tech";
        case 4: return "Degree";
        case 5: return "Research";
        default: return "";
    }
}

int main() {
    const vector<Feed> appFeeds = {
        {"YouTube", "Top 10 Study Hacks", "study", "Class 1–10"},
        {"News", "India Wins U19 World Cup", "sports", ""},
        {"YouTube", "Funny Cat Videos", "entertainment", ""},
        {"News", "Global Economy Update", "finance", ""},
        {"Info", "CBSE 10th Exam Tips", "study", "Class 1–10"},
        {"YouTube", "Football Skills 2025", "sports", ""},
        {"News", "Movie Release Today", "entertainment", ""},
        {"YouTube", "Intermediate Physics Lecture", "study", "Intermediate"},
        {"News", "B.Tech Semester 3 Syllabus Released", "study", "B.Tech"},
        {"Info", "Degree Final Year Project Guidelines", "study", "Degree"},
        {"YouTube", "Latest Research in AI", "study", "Research"}
    };

    cout << "===== App Feed Control Simulation =====\n";

    int mode = getUserModeSelection();

    vector<string> selectedCategories;
    string modeName;
    string selectedSubcategory = "";

    switch (mode) {
        case 1:
            selectedCategories = {"study", "sports"};
            modeName = "KidsOnly";
            break;
        case 2:
            selectedCategories = {"study"};
            modeName = "StudyOnly";
            selectedSubcategory = getStudySubcategory();
            break;
        case 3:
            selectedCategories = {"sports"};
            modeName = "SportsOnly";
            break;
        case 4:
            selectedCategories = {"entertainment"};
            modeName = "EntertainmentOnly";
            break;
        case 5: {
            set<string> uniqueCategories;
            for (const auto& feed : appFeeds)
                uniqueCategories.insert(feed.category);  // Allow all unique categories
            selectedCategories.assign(uniqueCategories.begin(), uniqueCategories.end());
            modeName = "All";
            break;
        }
        default:
            // Should never reach here due to input validation
            selectedCategories = {"study", "sports"};
            modeName = "KidsOnly";
    }

    displayFilteredFeeds(appFeeds, selectedCategories, modeName, selectedSubcategory);

    return 0;
}
