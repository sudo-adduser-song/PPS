#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string,vector<int>> genre; // genre -> {plays[m], plays[n], plays[o], ...}
    unordered_map<int,int> song; // plays[i] -> i
    map<int,string> sum2genre; // 

    

    for (int i = 0 ; i < genres.size() ; i++){
        genre[genres[i]].push_back(plays[i]);
        if(song.find(plays[i])==song.end())
            song[plays[i]]=i;
    }

    int sum=0;
    int max = 0;
    string max_genre="";
    int max_index=0;

    vector<int> tmp;


    while (genre.size()>0){
        max = 0;
        max_genre="";
        max_index=0;
        for ( auto t : genre){
            sum = 0;
            for( auto v : t.second){
                sum+=v;
            }
            if(sum>=max){
                max=sum;
                max_genre=t.first;
            }
        }
        tmp = genre[max_genre];
        genre.erase(max_genre);
        sort(tmp.begin(),tmp.end());
        answer.push_back(song[tmp[tmp.size()-1]]);
        if(tmp.size()>=2) answer.push_back(song[tmp[tmp.size()-2]]);
    }
    

    return answer;
}

int main(){

    vector<int> results = solution({"classic", "pop", "classic", "classic", "pop"},{500, 600, 150, 800, 2500}); // result = {4, 1, 3, 0}

    for(auto result :results ){
        cout<<result<<", ";
    }
    
    cout<<endl;
    
}
