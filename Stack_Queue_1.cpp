#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = -1;

    for( auto e : arr){
        if(prev!=e){
            answer.push_back(e);
            prev=e;
        }
    }  

    return answer;
}

int main(){

    // vector<int> results = solution({1,1,3,3,0,1,1}); // result = {1,3,0,1}
    vector<int> results = solution({4,4,4,3,3}); // result = {4,3}

    for(auto result :results ){
        cout<<result<<", ";
    }
    
    cout<<endl;
    
}
