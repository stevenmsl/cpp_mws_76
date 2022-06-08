#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol125;
using namespace std;

/*takeaways
  - assume the window is [start, end] on s.
  - grow the window by increasing the end to include
    all chars from t then stop
  - shrink the window by increasing start while
    the window still contains all chars from t
    - record the min length of the window during the
      process
  - use a hash table to store the occurrences of
    each char in t so we only need to scan it once
*/

string Solution::minWindow(string s, string t)
{
  auto tm = unordered_map<char, int>();
  /* total number of chars in t */
  auto n = t.size();
  for (auto c : t)
    tm[c]++;

  auto minLen = INT_MAX;
  string result;
  for (auto start = 0, end = 0; end < s.size(); end++)
  {
    /* expand the window until it includes all chars in t
       - n will be reduced to zero if this is the case
    */
    if (tm.count(s[end]))
      tm[s[end]]--, n--;

    while (n == 0)
    {
      auto len = end - start + 1;
      if (len < minLen)
        minLen = len, result = s.substr(start, len);
      /*start shrinking the window */
      if (tm.count(s[start]))
        /* put the count back */
        tm[s[start]]++, n++;

      start++;
    }
  }

  return result;
}