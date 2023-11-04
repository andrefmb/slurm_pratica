#include<iostream>
#include<fstream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
	vector<double> results;
	double value;
	ifstream infile("simulation_results.txt");
	while(infile >> value) {
		results.push_back(value);
	}
	infile.close();
	double sum = accumulate(results.begin(), results.end(), 0.0);
	double mean = sum / results.size();

	cout << "Análise completa. Média das raízes: " << mean << endl;
	return 0;

}



