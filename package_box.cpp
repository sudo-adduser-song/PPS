#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    int height = n/w +1;

    int target_x=0;
    int target_y=0;

    vector<vector<int>> boxes(height,vector<int>(w,0));
    int number=1;
    for(int i = 0 ; i <height; i++){
        for(int j = 0; j<w; j++){
            if(i%2==1){
                if(number==num){
                    target_x=w-j-1;
                    target_y=i;
                }
                if(number>n) boxes[i][w-j-1]=0;
                else boxes[i][w-j-1]=number++;
            }
            else{
                if(number==num){
                    target_x=j;
                    target_y=i;
                }
                if(number>n) boxes[i][j]=0;
                else boxes[i][j]=number++;
            }
        }
    }
    // for(int i =height-1;i>=0;i--){
    //     for(int j = 0; j<w;j++){
    //         cout<< boxes[i][j]<<"\t";
    //         // if(boxes[i][j]==num){
    //         //     answer=height-i;
    //         // }
    //     }
    //     cout<<endl;
    // }

    // cout<<"target x = "<<target_x<<" / target y = "<<target_y<<" / height = "<<height<<endl;

    for(int i = height-1; i>=target_y;i--){
        // cout<<boxes[i][target_x]<<endl;
        if(boxes[i][target_x]==0) continue;
        else answer++;
    }
    

    return answer;
}

int main(){
    cout << solution(22,6,8)<<endl; // result = 3
    // cout << solution(100,6,10)<<endl; // result = 3
    // cout << solution(13,3,6)<<endl; // result = 4
}