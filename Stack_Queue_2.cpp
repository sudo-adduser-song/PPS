#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; // 배포되는 기능의 개수를 저장할 벡터
    vector<int> day; // 각 기능의 완료 일수를 저장할 벡터
    
    // 각 기능의 완료까지 걸리는 일수를 계산합니다.
    for(int i = 0; i < progresses.size(); i++)
    {
        // 완료 일수 계산: (100 - 현재 진도) / 개발 속도
        day.push_back(ceil((100.0 - progresses[i]) / speeds[i])); // 소수점 올림 처리
    }
    
    int time = -1; // 이전 기능의 완료 일수를 저장하기 위한 변수

    // 각 기능의 완료 일수를 순회합니다.
    for(int i : day)
    {
        // 현재 기능의 완료 일수가 이전 기능보다 크면 새로운 배포 시작
        if(time < i)
        {
            time = i; // 현재 기능의 완료 일수를 저장
            answer.push_back(1); // 새로운 배포 그룹을 시작하므로 1 추가
        }
        else
        {
            // 현재 기능이 이전 기능과 함께 배포될 경우
            int n = answer.back(); // 현재 그룹의 기능 개수를 가져옵니다.
            n++; // 기능 개수를 증가
            answer.pop_back(); // 이전 그룹 개수 제거
            answer.push_back(n); // 증가된 개수를 다시 추가
        }
    }
    
    return answer; // 최종 결과 반환
}

int main(){
    vector<int> results = solution({93, 30, 55},{1, 30, 5}); // result = {2,1}
    // vector<int> results = solution({95, 90, 99, 99, 80, 99},{1, 1, 1, 1, 1, 1}); // result = {1,3,2}

    for(auto result :results ){
        cout<<result<<", ";
    }
    
    cout<<endl;
    
}
