library(Rcpp)
cppFunction('
List GibbsExponential(NumericVector U, double B){
	int p = U.size();
	int n = (int)(1+p/2);
	NumericVector v1(n);
	NumericVector v2(n);
	List result;
	double temp;
	
	v1[0] = v2[0] = 1.0;
	for(int i=1; i < n; i++){
		temp = U[2*i-2]*(1.0-std::exp(-v2[i-1]*B));
		v1[i] = -std::log(1.0-temp)/v2[i-1];
		temp = U[2*i-1]*(1.0-std::exp(-v1[i-1]*B));
		v2[i] = -std::log(1.0-temp)/v1[i-1];
	}
	result = List::create(Named("X") = v1, Named("Y") = v2);
	return result;
}
')
run1 <- GibbsExponential(runif(1000), 20.0)
run2 <- GibbsExponential(runif(10000), 20.0)
mean(run1$X)
mean(run1$Y)
sd(run2$X)
sd(run2$Y)