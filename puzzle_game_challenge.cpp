#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int puzzle_count = diffs.size();

    bool clear = false;

    int level=1;

    int min =1;
    int max =1;

    int time_prev=0;

    long long clear_time = 0;
    
    int max_diff=0;

    long long all_time = 0;



    for(int i =0;i<puzzle_count;i++){
        if(max_diff<=diffs[i]) max_diff=diffs[i];
        all_time+=times[i];
    }

    max = max_diff;


    while(1){
        level=(min+max)/2;

        for( int i = 0 ; i < puzzle_count ; i++){

            if(level >= diffs[i] ){
                clear_time+= times[i];
            }
            else{
                clear_time+= (diffs[i]-level)*(times[i-1] + times[i])+times[i];
            }
        }


        cout<<"min = "<<min<<" / max = "<<max <<" / level = "<<level<<" / limit = "<<limit<<" / clear_time = "<<clear_time<<endl;
        if(max-min == 1) {
            if(clear_time<limit) level = min;
            else level = max;
            break;
        }

        if(limit < clear_time){
            min=level;
        }
        else{
            max=level;
        }

        clear_time=0;
        time_prev=0;
    }
    
    return level;
}

int main(){
    
    // cout << solution({1, 5, 3},{2, 4, 7},30); 

    // cout << solution({1, 4, 4, 2},{6, 3, 8, 2},59);

    // cout << solution({1, 328, 467, 209, 54},{2, 7, 1, 4, 3},1723); 

    // cout << solution({1, 99999, 100000, 99995},{9999, 9001, 9999, 9001},3456789012); 

    cout << solution({1, 1, 3},{1, 1, 3},50); 

}