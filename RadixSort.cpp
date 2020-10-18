#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int digit16(int v, int d){
// 양의 정수 v 의 16진수 d 번째 숫자를 반환하는 함수
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 1 이라면 6 을 반환
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 4 라면 11 (= 0xb) 을 반환
  v = v >> d*4;
  return v & 0xf;
}

void countingSort16(vector<pair<int, string> >& v,int d){
    int c[16]={0},n=v.size(),temp;
    vector<pair<int, string> > output(n);
    for(int i=0;i<n;i++)
        c[digit16(v[i].first,d)]++;
    for (int i=1;i<16;i++)
            c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--){
        temp=digit16(v[i].first,d);
       output[c[temp]-1]=v[i];
       c[temp]--;
    }
    for(int i=0;i<n;i++){
        v[i]=output[i];
    }
}
int main(void) {
    int n,d;
    string s;
    vector<pair<int, string> > v;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> d >> s;
        v.push_back(pair<int,string>(d,s));
    }
    //radixsort
    for (int d=0; d<8; d++) countingSort16(v, d);
    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}
