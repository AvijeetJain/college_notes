//C++ Program for implementing Round Robin Algorithm

#include<bits./stdc++.h>
using namespace std;

void checkNewArrival(int timer, int arrival[], int n, int &maxProccessIndex, vector<int> &queue) {
    for (int i = maxProccessIndex + 1; i < n; i++) {
        if (arrival[i] <= timer) {
            queue.push_back(i);
            if (i > maxProccessIndex) {
                maxProccessIndex = i;
            }
        }
    }
}

//Driver Code
int main() {
    int n, tq, timer = 0, maxProccessIndex = 0;
    float avgWait = 0, avgTT = 0;
    cout << "Enter the time quanta : ";
    cin >> tq;
    cout << "Enter the number of processes : ";
    cin >> n;
    int arrival[n], burst[n], wait[n], turn[n], temp_burst[n];
    bool complete[n];

    cout << "Enter the arrival time of the processes : ";
    for (int i = 0; i < n; i++)
        cin >> arrival[i];

    cout << "Enter the burst time of the processes : ";
    for (int i = 0; i < n; i++) {
        cin >> burst[i];
        temp_burst[i] = burst[i];
    }

    vector<int> queue;
    queue.push_back(0);

    for (int i = 0; i < n; i++) {
        complete[i] = false;
    }

    while (!queue.empty()) {
        int processIndex = queue[0];
        queue.erase(queue.begin());

        if (temp_burst[processIndex] <= tq) {
            timer += temp_burst[processIndex];
            temp_burst[processIndex] = 0;
            turn[processIndex] = timer;
            complete[processIndex] = true;
        } else {
            timer += tq;
            temp_burst[processIndex] -= tq;
            checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
            queue.push_back(processIndex);
        }

        if (queue.empty()) {
            checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
            if (!queue.empty()) {
                queue.push_back(queue[0]);
                queue.erase(queue.begin());
            }
        }
    }

    for (int i = 0; i < n; i++) {
        turn[i] -= arrival[i];
        wait[i] = turn[i] - burst[i];
    }

    cout << "Program No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << turn[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        avgWait += wait[i];
        avgTT += turn[i];
    }

    cout << "Average wait time : " << (avgWait / n) << endl;
    cout << "Average Turn Around Time : " << (avgTT / n) << endl;

    return 0;
}