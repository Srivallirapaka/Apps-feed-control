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

void displayFilteredFeeds(const vector<Feed>& feeds) {
    cout << "\n--- KidsOnly Study & Sports Feeds ---\n";
    for (const auto& feed : feeds) {
        if (feed.category == "study" || feed.category == "sports") {
            cout << "[" << feed.type << "] " << feed.title << " (" << feed.category << ")\n";
        }
    }
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

    cout << "App Feed Control Simulation\n";
    cout << "Mode: KidsOnly (Study + Sports)\n";

    displayFilteredFeeds(appFeeds);

    return 0;
}
