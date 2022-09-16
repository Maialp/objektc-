#include "std_lib_facilities.h"

//2a)
double sum(vector<double>& x){
	double sum = 0;
	for(double i : x){
		sum += i;
	}
	return sum;
}
//2b)
double mean(vector<double>& x){
	return sum(x)/(x.size());
}
//2c)
void read_csv(string filename, vector<double>& x, vector<double>& y){
	double xi;
	double yi;
	ifstream myfile{filename};
	if(!myfile) {
		throw runtime_error("Couldn't read file " + filename);
	}
	while (myfile >> xi >> yi) {
		x.push_back(xi);
		y.push_back(yi);
	}
}
//2d)
pair<double,double> linreg(vector<double>& x, vector<double>& y){
	double sumVar = 0.0;
	double sumCov = 0.0;
	for(int i = 0; i < x.size(); i++){
		sumVar += (x[i]-mean(x))*(x[i]-mean(x));
		sumCov += (x[i]-mean(x))*(y[i]-mean(y));
	}
	double var = sumVar/x.size();
	double cov = sumCov/x.size();
	pair<double, double> linreg;
	linreg.first = cov/var;
	linreg.second = mean(y) - linreg.first*mean(x);
	return linreg;
}
//2e)
vector<double> linpred(vector<double>& x, double a, double b){
	vector<double> y;
	for(double xi : x){
		y.push_back(a*xi + b);
	}
	return y;
}
//2f)
double r2(vector<double>& y, vector<double>& y_pred){
	double sumTop = 0.0;
	double sumBottom = 0.0;
	double ymean = mean(y);
	for (int i = 0; i < y.size(); i++){
		sumTop += (y[i]-y_pred[i])*(y[i]-y_pred[i]);
		sumBottom += (y[i]-ymean)*(y[i]-ymean);
	}
	return (1-(sumTop/sumBottom));
}