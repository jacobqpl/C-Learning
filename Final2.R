library(Rcpp)
cppFunction('
List RowSpread(NumericMatrix A){
	int n = A.nrow();
	int p = A.ncol();
	NumericVector v1(n);
	NumericVector v2(n);
	List result;
	double temp;
	double bar;
	
	//GMD
	for(int i=0; i < n; i++){
		temp = 0.0;
		for(int j=0; j < p-1; j++){
			for(int k=j+1; k < p; k++){
				temp += std::abs(A(i, j) - A(i, k));
			}
		}
		v1[i] = (temp*2)/(p*(p-1));
	}
	
	//COEF
	for(int i=0; i < n; i++){
		temp = 0.0;
		bar = 0.0;
		for(int j=0; j < p; j++){
			bar += A(i, j);
		}
		bar /= p;
		for(int j=0; j < p; j++){
			temp += std::pow(A(i, j)-bar, 2.0);	
		}
		temp /= p-1;
		v2[i] = bar/std::sqrt(temp);
	}
	
	result = List::create(Named("gmd") = v1, Named("coef.var") = v2);
	return result;
}
')
A1 <- cbind(1:3, 4:6, 7:9)
A2 <- matrix(rnorm(10000, mean=5, sd=1), nrow=500, ncol=20)
r1 <- RowSpread(A1)
r2 <- RowSpread(A2)
r1
summary(r2$gmd)
summary(r2$coef.var)