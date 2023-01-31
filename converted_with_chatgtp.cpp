#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <tqdm/tqdm.h>
#include <chrono>
#include <math.h>
#include <fstream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int m = 10000;
vector<pair<string, string>> dataset;
map<char, int> human_vocab;
map<char, int> machine_vocab;
map<int, char> inv_machine_vocab;

void load_dataset(int m) {
  // code to load dataset
}

void preprocess_data(vector<pair<string, string>> &dataset, map<char, int> &human_vocab, map<char, int> &machine_vocab, 
                    map<int, char> &inv_machine_vocab, int Tx, int Ty, MatrixXf &X, MatrixXf &Y, MatrixXf &Xoh, MatrixXf &Yoh) {
  // code to preprocess data
}

int main() {
  load_dataset(m);
  int Tx = 30, Ty = 10;
  MatrixXf X, Y, Xoh, Yoh;
  preprocess_data(dataset, human_vocab, machine_vocab, inv_machine_vocab, Tx, Ty, X, Y, Xoh, Yoh);
  
  cout << "X.shape: " << X.rows() << " x " << X.cols() << endl;
  cout << "Y.shape: " << Y.rows() << " x " << Y.cols() << endl;
  cout << "Xoh.shape: " << Xoh.rows() << " x " << Xoh.cols() << endl;
  cout << "Yoh.shape: " << Yoh.rows() << " x " << Yoh.cols() << endl;

  int index = 0;
  cout << "Source date: " << dataset[index].first << endl;
  cout << "Target date: " << dataset[index].second << endl;
  cout << endl;
  cout << "Source after preprocessing (indices):" << endl << X.row(index) << endl;
  cout << "Target after preprocessing (indices):" << endl << Y.row(index) << endl;
  cout << endl;
  cout << "Source after preprocessing (one-hot):" << endl << Xoh.block(index, 0, 1, Xoh.cols()) << endl;
  cout << "Target after preprocessing (one-hot):" << endl << Yoh.block(index, 0, 1, Yoh.cols()) << endl;
  
  return 0;
}
