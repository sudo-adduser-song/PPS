#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
bool solution(string s)
{
    bool answer = true;
    int check = 0;

    for(auto c : s){
        if(c == '('){
            check++;
        }
        else if(c == ')'){
            if(check<=0){
                answer=false;
                break;
            }
            check--;
        }
    }
    if(check!=0) answer = false;

    return answer;
}



int main(){
    cout<< solution("()()")<<endl; // result = true
    cout<< solution("(())()")<<endl; // result = true
    cout<< solution(")()(")<<endl; // result = false
    cout<< solution("(()(")<<endl; // result = false
    
    cout<<endl;
    
}
