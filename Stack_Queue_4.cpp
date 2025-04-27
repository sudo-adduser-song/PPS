#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int timer=0;

    int max = *max_element(priorities.begin(), priorities.end());

    while(1){
        if(priorities[timer]>=max) {
            if(timer == location){
                return answer+1;
            }
            else answer++;
            priorities[timer]=-1;
            max = *max_element(priorities.begin(), priorities.end());
        }

        timer++;
        timer= timer % priorities.size();
    }


    return answer;
}

int main(){
    cout<< solution({2, 1, 3, 2},2)<<endl; // result = 1
    cout<< solution({1, 1, 9, 1, 1, 1},0)<<endl; // result = 5
    
    cout<<endl;
    
}
