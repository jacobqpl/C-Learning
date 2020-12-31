#include <cmath>
#include <iostream>
using namespace std;

double lcg_random(double seed){
	double a = 1103515245.0;
	int c = 12345;
	double m = 2147483648.0;
	double result;
	
	result = a*seed + c;
	result = fmod(result, m);
	result /= m;
	
	return result;
}

double autocorr(double num[], int len){
	double corr = 0.0;
	
	for(int i=0; i < len-1; i++){
		corr += num[i] * num[i+1];
	}
	corr = corr/(12*(len-1)) - 1.0/48.0;
	
	return corr;
}

int main(){
	double seed;
	double x[1000];
	
	seed = 1.0;
	x[0] = lcg_random(2147483648.0*seed);
	for(int i=1; i < 1000; i++){
		x[i] = lcg_random(2147483648.0*x[i-1]);
	}
	cout<<"When seed is "<<seed<<", autocorrelation is "<<autocorr(x, 1000)<<endl;
	seed = 10.2;
	x[0] = lcg_random(2147483648.0*seed);
	for(int i=1; i < 1000; i++){
		x[i] = lcg_random(2147483648.0*x[i-1]);
	}
	cout<<"When seed is "<<seed<<", autocorrelation is "<<autocorr(x, 1000)<<endl;
	seed = 100.2;
	x[0] = lcg_random(2147483648.0*seed);
	for(int i=1; i < 1000; i++){
		x[i] = lcg_random(2147483648.0*x[i-1]);
	}
	cout<<"When seed is "<<seed<<", autocorrelation is "<<autocorr(x, 1000)<<endl;
	return 0;
}
