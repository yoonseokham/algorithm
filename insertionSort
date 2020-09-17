#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,string> Data;
void InsertionSort(vector <Data> &v){
  int n=v.size(),end_j;
  Data key;
  for(int i=1;i<n;i++){
    key=v[i];
    for(int j=i-1;j>=0;j--){
      end_j=j;
      if(key.first<v[j].first) v[j+1]=v[j];
      else{
        break;
      }
      v[end_j]=key;
    }
  }
}
int main(void) {
    int n;
    vector<pair<int, string> > v;
    
    cin >> n;
    
    for (int i=0; i<n; i++){
        int d;
        string s;
        cin >> d >> s;  
        v.push_back(pair<int,string>(d,s));
    }
    InsertionSort(v);
    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;          
    }

    return 0;
}
