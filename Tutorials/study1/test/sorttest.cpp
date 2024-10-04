#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 1, 12, 123, 41};
    sort(nums.begin(), nums.end());

    for (int i = 0; i < size(nums); i += 1)
    {
        cout << nums[i] << " ";
    }
}