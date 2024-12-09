#include <iostream> 
#include <vector> 
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	ifstream myfile("locationID.txt");
	string line;
	vector<int> list_1;
	vector<int> list_2; 

	int count = 0;

	if (myfile.is_open()) { 
		
		while (getline(myfile, line)) {
			string str1, str2; 
			stringstream ss(line);
			ss >> str1 >> str2;
			list_1.push_back(stoi(str1));
			list_2.push_back(stoi(str2)); 
			//cout << str1 << " " << str2 << endl;
			count += 1; 
		}
		myfile.close();
	}
	else {
		cerr << "Unable to open file" << endl;
		perror(nullptr);
	}
	sort(list_1.begin(), list_1.end());
	sort(list_2.begin(), list_2.end());
	int vect_sum = 0;
	for (int i = 0; i <= count - 1; i++) {
		vect_sum += abs(list_1[i] - list_2[i]); 
		cout << "Sum " << i << ": " << vect_sum << endl;
		//cout << vect_sum << endl;
	}
	cout << vect_sum << endl;
	cout << "There are " << count << " location IDs counted!" << endl;
	
	return 0;
}