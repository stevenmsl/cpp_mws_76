#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol125;

/*
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
*/

tuple<string, string, string>
testFixture1()
{
  return make_tuple("ADOBECODEBANC", "ABC", "BANC");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.minWindow(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  return 0;
}