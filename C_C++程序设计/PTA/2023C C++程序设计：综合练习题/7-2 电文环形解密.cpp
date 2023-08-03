#include<iostream>
using namespace std;


int main(){
	long long key;
	int c;
	cin>>key;
	key = -key;
	key %= 26;
	getchar();	//处理输入时的‘\n’
	while((c = getchar()) != '\n'){
		if(c >= 65 && c <= 90){
			if(c+key >= 65 && c+key <= 90)
				printf("%c",c+key);
			else if(c+key < 65)
				printf("%c",90+key+1);
			else if(c+key > 90)
				printf("%c",65+c+key-90-1);
		}
		else if(c >= 97 && c<= 122){
			if(c+key >= 97 && c+key <= 122)
				printf("%c",c+key);
			else if(c+key < 97)
				printf("%c",122+key+1);
			else if(c+key > 122)
				printf("%c",97+c+key-122-1);
		}
		else printf("%c",c);
	}
}