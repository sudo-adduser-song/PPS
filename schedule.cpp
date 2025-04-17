#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    int n = schedules.size();

    for (int i = 0; i<n; i++){
        int h = schedules[i]/100;
        int m = schedules[i]%100+10;
        if(m >=60){
            m-=60;
            h++;
        }
        schedules[i]=h*100+m;
        // cout<<schedules[i]/100<<":"<<schedules[i]%100<<endl;
    }
    int count =0;
    int clear =0;
    for (int i = 0 ;i < n; i++){
        clear=1;
        for(int j =0; j<7;j++){
            if((startday+j)%7==6) continue; // SAT
            if((startday+j)%7==0) continue; // SUN
            if(timelogs[i][j] > schedules[i]) clear =0;
        }
        if( clear == 1) answer ++;
    }
    return answer;
}

int main(){
    // cout << solution({700, 800, 1100},{{710, 2359, 1050, 700, 650, 631, 659}, {800, 801, 805, 800, 759, 810, 809}, {1105, 1001, 1002, 600, 1059, 1001, 1100}},5)<<endl; // result = 3
    cout << solution({730, 855, 700, 720},{{710, 700, 650, 735, 700, 931, 912}, {908, 901, 805, 815, 800, 831, 835}, {705, 701, 702, 705, 710, 710, 711}, {707, 731, 859, 913, 934, 931, 905}}, 1)<<endl; // result = 2
}