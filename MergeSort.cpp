#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;
typedef pair<int, string> Data;
void merge(vector<pair<int, string> >& v, int p,int q, int r){
  Data left[q-p+2],right[r-q+1];
  int leftsize=q-p+1,rightsize=r-q,i=0,j=0;
  for(int i=0;i<leftsize;i++){
    left[i]=v[i+p];
  }
  left[leftsize]=make_pair(INT_MIN,'dw');
  for(int i=0;i<rightsize;i++){
    right[i]=v[i+q+1];
  }
  right[rightsize]=make_pair(INT_MIN,'dw');
  for(int k=p;k<=r;k++){
    if(left[i].first>=right[j].first){
      v[k]=left[i];
      i++;
    }
    else{
      v[k]=right[j];
      j++;
    }
  }
}
void mergesort(vector<pair<int, string> >& v, int p, int r){
int q;
  if(p<r){
    q=(p+r)/2;
    mergesort(v,p,q);
    mergesort(v,q+1,r);
    merge(v,p,q,r);
  }
  else
    return;
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

    // merge sort
    mergesort(v, 0, v.size()-1);
    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}
