/*
구간 합 구하기

사용자로부터 입력이 N 개를 입력받았을 때 이 배열에서 일부분의 합을 구하는 문제 해결 시에
매 질문마다 부분합을 구하는 것이 아니라 S 라고 하는 배열에서 0 ~ n 까지의 부분합을 미리 계산해놓고
이 배열을 사용하여 질문의 부분합을 구하는 방법

*/

#include <iostream>

using namespace std;

int main(){
    // 아래 세 코드는 C++ 에서 작성한 코드의 시간을 단축시켜줄 수 있는 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int suNo, quizNo;
    cin >>suNo >> quizNo;
    int S[100001]={};

    for (int i = 1; i <=suNo; i++){
        int temp;
        cin>> temp;
        S[i] = S[i-1] + temp;
    }
    for (int i = 0 ; i< quizNo; i++){
        int start, end;
        cin >> start >> end;
        cout<< S[end]-S[start-1]<<"\n";
    }
    return 0;
}