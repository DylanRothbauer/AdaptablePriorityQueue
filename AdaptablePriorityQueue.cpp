#include "AdaptablePriorityQueue.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
* Dylan Rothbauer
* 5/3/23
* 
* CHANGE LOG
* 5/3/23 - Dylan Rothbauer - added run time
* 5/3/23 - Dylan Rothbauer - pushed to git hub
*/

int main() {
    AdaptablePriorityQueue pq;
    int a, b;
    string name, nameToRemove;

    bool loop = true;

    while (loop) {
        cout << "1) Add new Bid and Name pair" << endl;
        cout << "2) Peek at the front of the Queue" << endl;
        cout << "3) Remove person from the front of the Queue" << endl;
        cout << "4) Remove a person from anywhere in the Queue by name" << endl;
        cout << "5) Print the entire Queue, bids and names" << endl;
        cout << "6) Quit" << endl;
        cout << "Enter your choice: ";
        cin >> a;
        cout << endl;

        switch (a) { // switch statement
        case 1:
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the bid: ";
            cin >> b;
            pq.enqueue(b, name);
            break;
        case 2:
            if (!pq.isEmpty()) {
                auto top = pq.peek();
                cout << "The front of the Queue is " << top << endl;
            }
            else {
                cout << "The Queue is empty" << endl;
            }
            break;
        case 3:
            if (!pq.isEmpty()) {
                auto top = pq.dequeue();
                cout << top << " has been removed from the front of the Queue" << endl;
            }
            else {
                cout << "The Queue is empty" << endl;
            }
            break;
        case 4:
            cout << "Enter the name to remove: ";
            cin >> nameToRemove;
            if (pq.removeAny(nameToRemove)) {
                cout << nameToRemove << " has been removed from the Queue" << endl;
            }
            else {
                cout << nameToRemove << " was not found in the Queue" << endl;
            }
            break;
        case 5:
            pq.print();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    }
}
