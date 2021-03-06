#include <iostream>
#include <cmath>
#include "testlib.h"

using namespace std;

#define CASE_NUM 10

const long long MIN_R = 1LL;
const long long MAX_R = 10LL;

void start(int id) {
  ofstream out(format("10_large_%02d.in", id).c_str());
  long long N = pow(2,rnd.next(MIN_R,MAX_R));
  long long M = rnd.next(MIN_R,MAX_R);
  while(M%2==0)M/=2;
  N *= M;
  N--;
  out << N << endl;
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  for(int t = 0; t < CASE_NUM; ++t) {
    start(t);
  }
  return 0;
}
