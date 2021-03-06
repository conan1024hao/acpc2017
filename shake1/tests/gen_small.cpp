#include <iostream>
#include <cmath>
#include "testlib.h"

using namespace std;

#define CASE_NUM 10

const long long MIN_N = 1LL;
const long long MAX_N = 50LL;

void start(int id) {
  ofstream out(format("30_small_%02d.in", id).c_str());
  long long N = pow(2,rnd.next(MIN_N, MAX_N))-1;
  out << N << endl;
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  for(int t = 0; t < CASE_NUM; ++t) {
    start(t);
  }
  return 0;
}
