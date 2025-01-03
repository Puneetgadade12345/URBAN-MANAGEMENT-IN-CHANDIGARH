#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a service request
struct ServiceRequest {
    string requestID;     // Unique identifier for the service request
    string serviceType;   // Type of service requested (e.g., "Road Repair", "Water Supply")
    string dateSubmitted; // Date of submission (format: YYYY-MM-DD)

    // For Quick Sort to compare based on date
    bool operator<(const ServiceRequest &other) const {
        return dateSubmitted < other.dateSubmitted;
    }
};

// Partition function to rearrange the elements around the pivot
int partition(vector<ServiceRequest>& requests, int low, int high) {
    ServiceRequest pivot = requests[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (requests[j] < pivot) {
            i++;
            swap(requests[i], requests[j]);
        }
    }
    swap(requests[i + 1], requests[high]);
    return i + 1;
}

// Function to perform Quick Sort on the vector of service requests
void quickSort(vector<ServiceRequest>& requests, int low, int high) {
    if (low < high) {
        int pivot = partition(requests, low, high);
        quickSort(requests, low, pivot - 1);  // Recursively sort the left part
        quickSort(requests, pivot + 1, high); // Recursively sort the right part
    }
}

// Function to display the service requests after sorting
void displayRequests(const vector<ServiceRequest>& requests) {
    cout << "\nSorted Service Requests (by Submission Date):\n";
    cout << "------------------------------------------------\n";
    for (const auto& request : requests) {
        cout << "Request ID: " << request.requestID
             << " | Service: " << request.serviceType
             << " | Date: " << request.dateSubmitted << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of service requests: ";
    cin >> n;

    // Create a vector of service requests
    vector<ServiceRequest> requests(n);

    // Input data for service requests
    cout << "Enter details for each service request (Request ID, Service Type, Date of Submission):\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter details for request " << i + 1 << ":\n";
        cout << "Request ID: ";
        cin >> requests[i].requestID;
        cout << "Service Type (e.g., 'Road Repair', 'Water Supply'): ";
        cin >> requests[i].serviceType;
        cout << "Date Submitted (YYYY-MM-DD): ";
        cin >> requests[i].dateSubmitted;
    }

    // Sort the service requests by date using Quick Sort
    quickSort(requests, 0, n - 1);

    // Display the sorted service requests
    displayRequests(requests);

    return 0;
}
