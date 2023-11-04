#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
#include<omp.h>
using namespace std;

int main(){
	const int size = 50000000;
	vector<double> results(size);
	double sum = 0.0;
	#pragma omp parallel for reduction(+:sum)
	for(int i = 0; i < size; ++i) {
		results[i] = sqrt(static_cast<double>(i));
		sum += results[i];

	}
	ofstream outfile("simulation_results.txt");
	for(auto &value: results){
		outfile << value << "\n";
	}
	outfile.close();
	cout << "Simulacao completa. Soma das raizes = " << sum << endl;
	return 0;
}



