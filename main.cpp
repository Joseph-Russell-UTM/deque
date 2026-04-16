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
    cout << "=== DEQUE TEST SUITE ===" << endl << endl;

    // INT TEST
    cout << "--- INT TEST: Pushing 1000 elements to back ---" << endl;
    Deque<int> dq;

    for (int i = 0; i < 1000; i++) {
        dq.push_back(i);
    }
    cout << "Completed pushing 1000 elements to back.\n" << endl;

    cout << "--- Pushing 500 elements to front ---" << endl;
    for (int i = 0; i < 500; i++) {
        dq.push_front(-i);
    }
    cout << "Completed pushing 500 elements to front.\n" << endl;

    cout << "INT TEST RESULTS:\n";
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl << endl;

    // STRING TEST (IMPORTANT FOR BONUS)
    cout << "--- STRING TEST: Creating deque and pushing 3 strings ---" << endl;
    Deque<string> dqStr;

    dqStr.push_back("hello");
    dqStr.push_front("world");
    dqStr.push_back("deque");
    cout << "Completed pushing 3 strings.\n" << endl;

    cout << "STRING TEST RESULTS:\n";
    for (int i = 0; i < dqStr.size(); i++) {
        cout << dqStr[i] << " ";
    }
    cout << endl;

    cout << "\n=== ALL TESTS COMPLETE ===" << endl;
    return 0;
}