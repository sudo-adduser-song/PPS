// Exceed Time Limit.

#include <string>
#include <iostream>
#include <vector>
#include <format>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = {0,0};
    vector<int> queue;
    vector<int>::iterator it=queue.begin();
    vector<vector<int>> tmp;

    int child_count=0;

    int holzzak =0;
    int inverse_holzzak =0;

    for(int i = 0 ; i < nodes.size() ; i++){
        queue.clear();
        queue.insert(queue.begin(),nodes[i]);
        tmp = edges;
        int cur_num=0;
        holzzak=0;
        inverse_holzzak=0;
        while(!queue.empty()){
            cur_num=queue.back();
            queue.pop_back();
            child_count=0;
            // cout<< "cur_num = "<<cur_num<<" queue length = "<<queue.capacity()<<endl;
            for(int j =0 ;j<tmp.size();j++){
                // cout<<"[DEBUG] j = "<<j << "/ tmp size = "<<tmp.size()<<endl;
                // cout<< "[DEBUG] tmp[j] = "<<tmp[j][0]<<", "<<tmp[j][1]<<endl;
                if(tmp[j][0]==cur_num){
                    // cout<<" if 문 OK / j = "<<j <<" / "<< tmp.size()<<endl;
                    queue.insert(queue.begin(),tmp[j][1]);
                    tmp.erase(tmp.begin() + j--);
                    child_count++;
                }
                else if(tmp[j][1]==cur_num){
                    // cout<<"else if 문 OK / j = "<<j <<" / "<< tmp.size()<<endl;
                    queue.insert(queue.begin(),tmp[j][0]);
                    tmp.erase(tmp.begin() + j--);
                    child_count++;
                }
            }
            if(cur_num%2==child_count%2){
                holzzak++;
            }
            else{
                inverse_holzzak++;
            }
            // cout<<"root node = "<<nodes[i]<<" / cur_num = "<<cur_num<<" / child nodes = "<<child_count<<endl;
        }
        // cout<<"root node = "<<nodes[i]<<" / holzzak = "<< holzzak<<" / inverse_holzzak = "<<inverse_holzzak<<endl;
        if(holzzak==0 & inverse_holzzak!=0){
            answer[1]++;
        }
        else if(holzzak!=0 & inverse_holzzak==0){
            answer[0]++;
        }
    }
    return answer;
}

int main(){
    vector<int> result = solution({11, 9, 3, 2, 4, 6},{{9, 11}, {2, 3}, {6, 3}, {3, 4}}); // result = (1,0)
    // vector<int> result = solution({9, 15, 14, 7, 6, 1, 2, 4, 5, 11, 8, 10},{{5, 14}, {1, 4}, {9, 11}, {2, 15}, {2, 5}, {9, 7}, {8, 1}, {6, 4}}); // result = (2,1)
    cout << result[0] <<", "<<result[1]<<endl;
    
}