#include <iostream>
#include "utils.h"
using namespace std;


int valid_int(int min_value, int max_value) {
    int value;

    while ((wcin >> value).fail()
        || wcin.peek() != '\n'
        || value < min_value || value > max_value)
    {
        wcin.clear();
        wcin.ignore(10000, '\n');
        wcout << L"������� ����� �� " << min_value << L" �� " << max_value << endl;
    }
    wcin.ignore(10000, '\n');
    return value;
}