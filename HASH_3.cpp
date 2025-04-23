#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    string prev = "-";

    sort(phone_book.begin(), phone_book.end());

    for( auto phone : phone_book){
        if( phone.find(prev) == 0 ){
            return false;
        }
        prev=phone;
    }
    return true;
}

int main(){ 
    cout << solution({"119", "97674223", "1195524421"})<<endl; // result = false
    cout << solution({"123","456","789"})<<endl; // result = true
    cout << solution({"12","123","1235","567","88"})<<endl; // result = false
    cout << solution({"0","10"})<<endl; // result = true
}
