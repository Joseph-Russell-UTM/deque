/**
 * @file tree.cpp
 * @author Joseph Russell
 * @date 2026-04-18
 * @brief The implementation of tree.h
 * 
 * Defines the functions made in tree.h.
 */

 #include <deque>
 #include <iostream>

 using namespace std;

 int main(){
    deque<int> d;

    int tmp;

    d.push_front(30);
    d.push_front(20);
    d.push_front(10);

    d.push_back(35);
    d.push_back(25);
    d.push_back(5);

    tmp = d.front();
    cout << "front was: " << tmp << endl;
    d.pop_front();

    tmp = d.back();
    cout << "back was: " << tmp << endl;
    d.pop_back();

    for (int i = 0; i < d.size(); i++) {
        cout << "Element " << i << " is " << d[i] << endl;
    }

 }