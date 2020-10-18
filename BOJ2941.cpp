#include <iostream>
#include <string>

using namespace std;
int main(void){
string c_alpha[]={"c=","c-","dz=","d-","lj","nj","s=","z="};
string temp[101];
bool find =false;
int n=0,c=0,i=0;
while(true){
	c=fgetc(stdin);
	if(c==EOF)
		break;
	temp[i++]=string(c);
	cout<<temp[i]<<"\n";
	find =false;
		for(int i=0;i<8;i++){
			c=temp[i].find(c_alpha[i]);
			if(c==0){
				n++;
				find =true;
				break;
			}
		}
	if(!find&&temp[i]!="="||temp[i]!="-")
}
cout<<n<<" ";
return 0;
}
