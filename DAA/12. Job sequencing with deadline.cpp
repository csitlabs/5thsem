//12. Job sequencing with deadline

#include <iostream>

using namespace std;

// Structure to represent a job
struct Job {
    int id;        // Job ID
    int deadline;  // Deadline of the job
    int profit;    // Profit from the job
};

// Function to sort jobs by profit in descending order
void sortJobsByProfit(Job jobs[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (jobs[i].profit < jobs[j].profit) {
                // Swap jobs[i] and jobs[j]
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

// Function to perform job sequencing with deadlines
void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    sortJobsByProfit(jobs, n);

    // Array to keep track of free time slots
    int result[n]; // Stores the job ID for each slot
    bool slot[n];  // Keeps track of whether a slot is free or not

    // Initialize all slots as free
    for (int i = 0; i < n; ++i) {
        slot[i] = false;
        result[i] = -1; // -1 means slot is free
    }

    int maxProfit = 0;

    // Iterate through the jobs
    for (int i = 0; i < n; ++i) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = i; // Assign job to this slot
                slot[j] = true;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the sequence of jobs and total profit
    cout << "Job Sequence for Maximum Profit: ";
    for (int i = 0; i < n; ++i) {
        if (result[i] != -1) {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl;

    cout << "Total Profit: " << maxProfit << endl;
}

int main() {
    int n;
    cout << "Job sequencing with deadline" << endl;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job jobs[n];
    cout << "Enter job details (ID Deadline Profit):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}

