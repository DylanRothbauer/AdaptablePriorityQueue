#include "AdaptablePriorityQueue.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    AdaptablePriorityQueue pq;
    int choice;
    int bid;
    string name;
    string nameToRemove;

    while (true) {
        cout << "1. Add new Bid/Name pair\n";
        cout << "2. Peek at the front of the Queue\n";
        cout << "3. Remove person from the front of the Queue\n";
        cout << "4. Remove a person from anywhere in the Queue by name\n";
        cout << "5. Print the entire Queue, bids and names\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1:
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the bid: ";
            cin >> bid;
            pq.enqueue(bid, name);
            break;
        case 2:
            if (!pq.isEmpty()) {
                auto top = pq.peek();
                cout << "The front of the Queue is " << top << "\n";
            }
            else {
                cout << "The Queue is empty\n";
            }
            break;
        case 3:
            if (!pq.isEmpty()) {
                auto top = pq.dequeue();
                cout << top << " has been removed from the front of the Queue\n";
            }
            else {
                cout << "The Queue is empty\n";
            }
            break;
        case 4:
            cout << "Enter the name to remove: ";
            cin >> nameToRemove;
            if (pq.removeAny(nameToRemove)) {
                cout << nameToRemove << " has been removed from the Queue\n";
            }
            else {
                cout << nameToRemove << " was not found in the Queue\n";
            }
            break;
        case 5:
            pq.print();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        cout << "\n";
    }
}
