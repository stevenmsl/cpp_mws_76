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
    - use a hash table to record the frequency
      of each char
    - count how many chars are left in T but not
      included in the window
  - shrink the window by increasing start while
    the window still contains all chars from t
    - record the min length of the window during the
      process
  - use a hash table to store the occurrences of
    each char in t so we only need to scan it once
*/

string Solution::minWindow(string s, string t)
{

  const int n = s.length();
  const int m = t.length();
  /* use negative values to record the frequency
     for chars in s
   */
  vector<int> freq(128);
  for (char c : t)
    ++freq[c];
  int start = 0;
  int minLen = INT_MAX;
  for (int i = 0, j = 0, remain = m; j < n; ++j)
  {
    /* negative value of freq
       - s = "aaabbb" t = "bb"
       - freq['a'] = -3, freq['b'] = -1
    */
    /* in case s has more than t for
       the same char
    */
    if (--freq[s[j]] >= 0)
      --remain;
    /* the window includes all chars from t */
    while (remain == 0)
    {
      if (j - i + 1 < minLen)
      {
        minLen = j - i + 1;
        start = i;
      }
      /*
        - for the chars not in t, the best they
          can do is to come back to 0
        - for others that are both in s and t,
          once the frequency becomes zero,
          we have counted off the number of
          occurrences in s. Once it becomes 1,
          we are counting off the number of
          occurrences in t
      */
      if (++freq[s[i++]] == 1)
        ++remain;
    }
  }
  /* to achieve O(n), produce the string at the very end */
  return minLen == INT_MAX ? "" : s.substr(start, minLen);
}