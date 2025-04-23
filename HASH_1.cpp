#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0; i < completion.size(); i++)
    {
        if(participant[i] != completion[i])
            return participant[i]; 
    }
    return participant.back();
}

int main(){ 
    cout << solution({"leo", "kiki", "eden"},{"eden", "kiki"})<<endl; // result = "leo"
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"},{"josipa", "filipa", "marina", "nikola"})<<endl; // result = "vinko"
    cout << solution({"mislav", "stanko", "mislav", "ana"},{"stanko", "ana", "mislav"})<<endl; // result = "mislav"
}
