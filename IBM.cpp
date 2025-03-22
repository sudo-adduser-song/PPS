/*
IBM 빼기 1

'2001: 스페이스 오디세이'는 아서 C. 클라크의 소설이자 스탠리 큐브릭 감독의 영화이다.
이 작품에서 우주선은 토성으로 가고 있다. 긴 여행동안 선원들은 모두 정체 상태에 빠져있고, 두 선원은 깨어나 있다. 우주선은 인공지능 컴퓨터 HAL이 조정하고 있다. HAL은 점점 이상하게 행동하더니 선원들을 죽이기 시작했다. 자세한 이야기는 소설을 읽거나 영화를 보면 알 수 있다.
영화가 유명해지고 난 이후에 사람들은 '2001: 스페이스 오디세이'에 나오는 인공지능 컴퓨터인 HAL의 뜻에 관심을 가졌다. HAL은 휴리스틱 알고리즘 (Heuristic ALgorithm)의 약자이다. 하지만, HAL의 각 글자를 알파벳 다음 순서로 쓰면 IBM이 되기 때문에, IBM과 연관이 있다고 믿는 사람이 매우 많다.
컴퓨터의 이름이 주어졌을 때, 각 글자를 알파벳 다음 순서로 써서 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 아래 세 코드는 C++ 에서 작성한 코드의 시간을 단축시켜줄 수 있는 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 위 세 코드는 C++ 에서 작성한 코드의 시간을 단축시켜줄 수 있는 코드

    int N;
    cin >> N;

    vector<string> strings(N);


    for ( int i = 0; i<N; i++){
        cin >> strings[i];
    }

    string tmp;

    for ( int i = 0; i<N; i++){
        tmp = strings[i];
        for (int j = 0 ; j < tmp.length(); j++){
            if(tmp[j]=='Z') tmp[j]='A';
            else tmp[j]=tmp[j]+1;
        }
        strings[i] = tmp;
    }

    for ( int i = 0; i<N; i++){
        cout << "String #"<<i+1<<endl;
        cout << strings[i] << endl <<endl;
    }
    
    return 0;
}