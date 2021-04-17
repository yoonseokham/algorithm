#include <string>
#include <vector>

using namespace std;
void Sign(vector<int> numbers,int& count,int target,int index=0,int sum=0){
    if(index==numbers.size()){
        if(sum==target)
            count++;
        return;
    }
    Sign(numbers,count,target,index+1,sum+numbers[index]);
    Sign(numbers,count,target,index+1,sum-numbers[index]);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    Sign(numbers,answer,target);
    return answer;
}
