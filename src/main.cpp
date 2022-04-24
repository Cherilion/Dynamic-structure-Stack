#include "../include/myStackLib.h"

using namespace std;

int main() {
    myStack<int> nums;

    srand(time(0));

    for(int i = 0; i < 10; i++){
        nums.push_back(rand() % 101);
    }
    //nums.sort("quickSort");
    nums.print();

    for(int i = 0; i < nums.size(); i++){
        if((nums[i] % 10 && !(nums[i] % 5)) || nums[i] == 5){
            nums.remove(i);
        }
    }
    nums.print();

    return 0;
}
