#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    sort(nums.begin(),nums.end());
    
    int prev = -1;
    int count = 0;

    for( auto num : nums){
        if(num != prev){
            prev = num;
            count++;
        }
    }
    if(nums.size()/2 >= count){
        return count;
    }
    else return nums.size()/2;
}

int main(){ 
    // cout << solution({3,1,2,3})<<endl; // result = 2
    cout << solution({3,3,3,2,2,4})<<endl; // result = 3
    cout << solution({3,3,3,2,2,2})<<endl; // result = 2
}
