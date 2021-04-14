#include <set>
int solution(int X, vector<int> &A) {
   set<int> leaves;
   for(int i=0;i<A.size();i++){
       leaves.insert(A[i]);
       if(leaves.size()==X) return i;
   }
   return -1;
}
