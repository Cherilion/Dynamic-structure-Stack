#include "../include/myStackLib.h"

using namespace std;

int main() {
    myStack<string> nums;
    nums.push_back(" adf ds10");
    nums.push_back("20");
    nums.push_back("5");
    nums.print();
    return 0;
}
