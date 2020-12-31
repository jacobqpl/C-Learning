#include <iostream>
#include <vector>
using namespace std;

void shift_elements(vector<int> &x){
	vector<int>::iterator begin = x.begin();
	int temp = *begin;
	
	x.erase(begin);
	x.push_back(temp);
}

int main(){
	vector<int> v = {1,2,3,4};
	shift_elements(v);
	for(int i=0; i < 4; i++){
		cout << v[i];
	}
	return 0;
}
