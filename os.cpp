#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;

struct Process {
    int id;
    vector<int> Max;
    vector<int> Allocation;
    vector<int> Need;
    bool status;
};

bool IsSafe(vector<Process> &processes, vector<int> &available, int nprocesses, int nresources) {
    int finished = nprocesses;
    while (finished != 0) {
        int counter = finished;
        for (auto &proc : processes) {
            if (!proc.status) {
                int j;
                for (j = 0; j < nresources; j++) {
                    if (proc.Need[j] > available[j])
                        break;
                }
                if (j == nresources) {
                    finished--;
                    proc.status = true;
                    for (int k = 0; k < nresources; k++) {
                        available[k] += proc.Allocation[k];
                    }
                    seq.push_back(proc.id);
                }
            }
        }
        if (counter == finished) {
            return false;
        }
    }
    return true;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int nprocesses, nresources;
    cout << "\nEnter the number of resources: ";
    cin >> nresources;
    cout << "Enter the number of processes: ";
    cin >> nprocesses;
    cout << endl;

    vector<int> available(nresources);
    vector<Process> processes(nprocesses);

    for (int i = 0; i < nprocesses; i++) {
        processes[i].Max.resize(nresources);
        processes[i].Allocation.resize(nresources);
        processes[i].Need.resize(nresources);
        processes[i].id = i;
        processes[i].status = false;

        cout << "\nEnter the allocated resources for P" << i << ": \n";
        for (int j = 0; j < nresources; j++) {
            cin >> processes[i].Allocation[j];
        }
    }

    cout << endl;
    for (int i = 0; i < nprocesses; i++) {
        cout << "\nEnter the maximum resource need of P" << i << ": \n";
        for (int j = 0; j < nresources; j++) {
            cin >> processes[i].Max[j];
            processes[i].Need[j] = processes[i].Max[j] - processes[i].Allocation[j];
        }
    }

    cout << "\nEnter the available resources: \n";
    for (int j = 0; j < nresources; j++) {
        cin >> available[j];
    }

    cout << "\n\n\tNeed Matrix\n\t";
    for (int i = 0; i < nresources; i++) {
        cout << "R" << i << "\t";
    }
    cout << endl;

    for (int j = 0; j < nprocesses; j++) {
        cout << "P" << j << "\t";
        for (int i = 0; i < nresources; i++) {
            cout << processes[j].Need[i] << "\t";
        }
        cout << endl;
    }

    if (IsSafe(processes, available, nprocesses, nresources)) {
        cout << "\n\nYes, the system is in a safe state.\nSafe sequence: ";
        for (int i = 0; i < nprocesses; i++) {
            cout << "P" << seq[i];
            if (i != nprocesses - 1) cout << ", ";
        }
        cout << "\n\n";
    } else {
        cout << "\n\nNo, the system is in an unsafe state.\n\n\n";
    }

    return 0;
}
