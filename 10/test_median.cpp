#include "median.hpp"
#include<iostream>
#include<vector>

using std::vector;
using std::endl;
using std::cout;

int main(){

//use with vector
vector<double> v1;
v1.push_back(1);
v1.push_back(2);
v1.push_back(4);
v1.push_back(3);
//v1.push_back(10);

cout << "Median of vector is: " << median<double>(v1.begin(), v1.end()) << endl;


//use with array
double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
cout << "Median of array is: " << median<double>(&balance[0], &balance[5]) << endl;

return 0;
}
