#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Histogram{
	char c, d;
	string str;
public:
	Histogram(string str1){
		str = str1;
		c=' ';
		d=' ';
	}
	Histogram& operator << (char c);
	Histogram& operator << (string c);
	bool operator !();
};

Histogram& Histogram::operator <<(char c){
	str+=c;
	return *this;
}

Histogram& Histogram::operator <<(string c){
	str+=c;
	return *this;
}

bool Histogram::operator !(){
	string strstr;
	int num=0,count=0;
	cout << str;
	for(int i=0;i<str.length();i++){
		if(isalpha(str[i])){
			strstr+=tolower(str[i]);
			num++;
		}
		else{
			strstr+=str[i];
		}
	}
	cout << "\n총 알파벳 수 " << num << endl;

	for(int p=0;p<26;p++){
		count=0;
		for(int o=0;o<strstr.length();o++){
				if('a'+p==strstr[o]){
					count++;
				}
		}
		cout << (char)('a'+p) << ":" ;
		for(int q=0;q<count;q++){
			cout << "*";
		}
		cout << endl;
	}

	return true;
}

int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << "in love with you." << "- by " ;
	song << 'k' << 'i' << 't';
	!song;
	return 0;
}
