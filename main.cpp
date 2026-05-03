#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ofstream test("test.txt");
    cout << "Hello wolrddd!";

    test << "Hi!!!";

    test.close();
}