#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int hamming(string s1, string s2){
	int similarity=0;
	
	for(int i=0; i<s1.length() && i<s2.length(); i++){
		if(s1[i]==s2[i]){
			similarity++;	
		}
	}
	
	return similarity;
}

int main(){
	ifstream ifile;
	string s1="exc";
	string s2;
	double total=0;
	int count=0;
	
	ifile.open("lorumipsum.txt");
	while(!ifile.eof()){
		s2="";
        ifile >> s2;
        if(s2.compare("")!=0){ 
	        total+=hamming(s1,s2);
			count++;
		}
    }
    cout<<total/count<<endl;
	return 0;	
} 
