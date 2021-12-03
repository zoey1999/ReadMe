#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
string rep_letters(string word, int times, int single);
int main() {
  // problem 1
  double mold; double mnew; double lambda; double tol = 0.0001; double diff = 1; double num; int t;

  cout << "Enter the number of data points: ";
  cin >> num;
  vector<double> y(num); vector<double> z(num);
  cout << "Enter the initial value of location parameter: ";
  cin >> mold;
  cout << "Enter the steplength: ";
  cin >> lambda;
  double sum = 0;
  while(diff >= tol && t<=20){
    for(int k = 0; k < num; k++){
      y[k] = (rand()%100)/100.0 - 0.5;
      z[k] = (y[k]-mold)/(1+pow((y[k]-mold),2)/3);
      sum = sum + z[k];
    }
    mnew = mold + 4 * lambda / 3 * sum;
    cout << "\nIn iteration " << t << " the value of m is " << mold << "\n";
    diff = abs(mnew - mold);
    mold = mnew; t++;
  }

  // problem 2
  string word; int times; int single; string output;
  cout << "\nInput the string: ";
  cin >> word;
  cout << "Enter the number of repeat times: ";
  cin >> times;
  cout << "Single or not: ";
  cin >> single;
  output = rep_letters(word, times, single);
  cout << output << endl;
  return 0;
} 

string rep_letters(string word, int times, int single){
  string outcome;
  if(single == 0){
    for(int i = 0; i < times; i++){
      outcome = outcome + word;
    } 
  }else if(single == 1){
    int lens = (int)word.length();
    for(int k = 0; k < lens; k++){
      for(int i = 0; i < times; i++){
        outcome = outcome + word[k];
      }
    }
  }
  return outcome;
}
