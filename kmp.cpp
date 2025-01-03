#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Function to build the LPS array for KMP
vector<int> buildLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int j = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < m; i++) {
        if (pattern[i] == pattern[j]) {
            j++;
            lps[i] = j;
        } else {
            if (j != 0) {
                j = lps[j - 1];
                i--; // Stay at the same character
            } else {
                lps[i] = 0;
            }
        }
    }
    return lps;
}

// KMP Search Algorithm
vector<int> KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = buildLPS(pattern);
    vector<int> matches;

    int i = 0, j = 0; // i: index for text, j: index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            matches.push_back(i - j); // Found a match
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}

// Function to display the list of services/documents
void displayServices(const vector<string>& services) {
    cout << "\n--- List of Available Services/Documents ---\n";
    for (size_t i = 0; i < services.size(); i++) {
        cout << setw(3) << i + 1 << ". " << services[i] << endl;
    }
    cout << endl;
}

// Function to search for a keyword in the list of services/documents
void searchService(const vector<string>& services) {
    string query;
    cout << "Enter a keyword to search: ";
    getline(cin, query);

    cout << "\nSearching for: \"" << query << "\"\n";

    bool found = false;
    for (const auto& service : services) {
        vector<int> matches = KMPSearch(service, query);
        if (!matches.empty()) {
            found = true;
            cout << "Match found in: \"" << service << "\"" << endl;
        }
    }

    if (!found) {
        cout << "No matches found for the keyword \"" << query << "\".\n";
    }
}

// Function to add a new service/document
void addService(vector<string>& services) {
    string newService;
    cout << "Enter the name of the new service/document: ";
    getline(cin, newService);
    services.push_back(newService);
    cout << "Service/Document added successfully.\n";
}

// Function to display the main menu
void displayMenu() {
    cout << "\n--- Chandigarh E-Governance System ---\n";
    cout << "1. View Available Services/Documents\n";
    cout << "2. Search for a Service/Document\n";
    cout << "3. Add a New Service/Document\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Main Function
int main() {
    vector<string> services = {
        "Property Tax Payment Portal",
        "Citizen Feedback System",
        "Online Complaint Registration",
        "E-Governance Policy Document",
        "Public Transport Management System"
    };

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To handle the newline character after integer input

        switch (choice) {
            case 1:
                displayServices(services);
                break;
            case 2:
                searchService(services);
                break;
            case 3:
                addService(services);
                break;
            case 4:
                cout << "Exiting the system. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
