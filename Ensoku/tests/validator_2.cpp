#include <iostream>
#include <vector>
#include "testlib.h"

using namespace std;

const int MAX_N = 14;
const int MAX_X = 10000;
const int MAX_Y = 1000;
const int MAX_K = 300;
const int MAX_a = 1000;
const int MAX_b = 1000;
const int MAX_c = 1000;
const int MAX_d = 10000;

const int MIN_N = 1;
const int MIN_X = 1;
const int MIN_Y = 1;
const int MIN_K = 1;
const int MIN_a = 1;
const int MIN_b = 1;
const int MIN_c = 1;
const int MIN_d = 0;

void input() {
  
  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int X = inf.readInt(MIN_X, MAX_X, "X");
  inf.readSpace();
  int Y = inf.readInt(MIN_Y, MAX_Y, "Y");
  inf.readEoln();
  ensuref(Y<=X,"Y must be lather than X or equal to X");
  
  for(int i = 0; i < N; i++) {
    int K = inf.readInt(MIN_K, MAX_K, "K");
    inf.readEoln();
    for(int j=0;j<K;j++) {
      int a = inf.readInt(MIN_a, MAX_a, "a");
      inf.readSpace();
      int b = inf.readInt(MIN_b, MAX_b, "b");
      inf.readSpace();
      int c = inf.readInt(MIN_c, MAX_c, "c");
      inf.readEoln();
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(j) inf.readSpace();
      int d = inf.readInt(MIN_d, MAX_d, "d");
      ensuref(i!=j || d == 0,"if i == j, d must be 0");
    }
    inf.readEoln();
  }
  inf.readEof();
}


int main() {
  registerValidation();
  input();
  return 0;
}
