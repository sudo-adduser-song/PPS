#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

int solution(vector<int> bandage, int health, vector< vector<int> > attacks) {
    int time=1;

    int max_health = health;
    int flag = 0;

    int total_attack= attacks.size();
    int attack_count=0;
    vector<int> next_attack= attacks[0];


    while(1){
        if(time==next_attack[0]){
            health -= next_attack[1];
            flag=0;
            attack_count+=1;
            if (total_attack==attack_count){
                if(health<=0) health=-1;
                break;
            }
            next_attack=attacks[attack_count];
        }
        else{
            health+=bandage[1];
            flag+=1;
            if(flag==bandage[0]){
                health+=bandage[2];
                flag=0;
            }
        }
        if(health<=0) {
            health=-1;
            break;
        }
        if(health>=max_health) health=max_health;
        // cout<<"time : "<<time<<" / health : "<<health<<" / flag : "<<flag<< endl;
        time ++;
        
    }
    


    return health;
}

int main(){
    
    // cout << solution({5, 1, 5}, 30, {{2, 10}, {9, 15}, {10, 5}, {11, 5}}); // result = 5

    // cout << solution({3, 2, 7}, 20, {{1, 15}, {5, 16}, {8, 6}}); // result = -1

    // cout << solution({4, 2, 7}, 20, {{1, 15}, {5, 16}, {8, 6}}); // result = -1

    cout << solution({1, 1, 1}, 5, {{1, 2}, {3, 2}}); // result = 3
}