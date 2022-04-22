#include "../include/myStackLib.h"

using namespace std;

int main() {
    myStack<int> nums;
    nums.push_back(20);
    nums.push_back(10);
    nums.push_back(5);
    try {
        nums.sort("quickSort");
    } catch (const char* msg) {
        cout << msg << endl;
    }
    nums.print();
    return 0;
}
