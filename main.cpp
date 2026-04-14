/**
 * @file main.cpp
 * @author Joseph Russell Zachery Pickell
 * @date 2026-04-14
 * @brief Uses the functions created in deque.cpp to create a deque and a menu for the user to interact with it.
 * 
 * main.cpp tests deque.cpp by creating a menu for the user to interact with the deque.
 */

#include <iostream>
#include <string>
#include "deque.h"
using namespace std;

int main() {
    // INT TEST
    Deque<int> dq;

    for (int i = 0; i < 1000; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < 500; i++) {
        dq.push_front(-i);
    }

    cout << "INT TEST:\n";
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;

    // STRING TEST (IMPORTANT FOR BONUS)
    Deque<string> dqStr;

    dqStr.push_back("hello");
    dqStr.push_front("world");
    dqStr.push_back("deque");

    cout << "\nSTRING TEST:\n";
    for (int i = 0; i < dqStr.size(); i++) {
        cout << dqStr[i] << " ";
    }
    cout << endl;

    return 0;
}