#include <iostream>
#include "utils.h"
using namespace std;


int valid_int(int min_value, int max_value) {
    int value;

    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min_value || value > max_value)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "������� ����� �� " << min_value << " �� " << max_value << endl;
    }
    cin.ignore(10000, '\n');
    return value;
}