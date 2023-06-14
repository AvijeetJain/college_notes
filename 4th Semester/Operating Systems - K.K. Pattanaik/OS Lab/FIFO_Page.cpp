#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int numFrames; // Number of frames in physical memory
    int numPages; // Number of pages in virtual memory
    cout << "Enter the number of frames in physical memory: ";
    cin >> numFrames;
    cout << "Enter the number of pages in virtual memory: ";
    cin >> numPages;

    vector<int> pages(numPages); // Pages in virtual memory
    cout << "Enter the page references: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    queue<int> frameQueue; // Queue to keep track of frames in physical memory
    unordered_set<int> frameSet; // Set to check if a frame is present in physical memory
    int pageFaults = 0; // Count of page faults

    cout << "Page Faults: ";
    for (int i = 0; i < numPages; i++) {
        if (frameSet.size() < numFrames) {
            // If there is still space in physical memory
            if (frameSet.find(pages[i]) == frameSet.end()) {
                // If the page is not present in physical memory
                frameSet.insert(pages[i]);
                frameQueue.push(pages[i]);
                pageFaults++;
            }
        } else {
            // If physical memory is full, replace the oldest page (FIFO)
            if (frameSet.find(pages[i]) == frameSet.end()) {
                // If the page is not present in physical memory
                int oldestPage = frameQueue.front();
                frameQueue.pop();
                frameSet.erase(oldestPage);
                frameSet.insert(pages[i]);
                frameQueue.push(pages[i]);
                pageFaults++;
            }
        }
        cout << pageFaults << " "; // Output the page faults for each page reference
    }
    cout << endl;

    return 0;
}
