#### Approach #1 Brute Force [Time Limit Exceeded]

**Intuition**

Check all the substring one by one to see if it has no duplicate character.

**Algorithm**

Suppose we have a function `boolean allUnique(String substring)` ....

**Java**

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (allUnique(s, i, j)) ans = Math.max(ans, j - i);
        return ans;
    }
}
```

**Complexity Analysis**

* Time complexity : $$O(n^3)$$.

To verify if characters within index range $$[i, j)$$ are all unique, we need to scan all of them. Thus, it costs $$O(j - i)$$ time.

For a given `i`, the sum of time costed by each $$j \in [i+1, n]$$ is

$$
\sum_{i+1}^{n}O(j - i)
$$

Thus, the sum of all the time consumption is:

$$
O\left(\sum_{i = 0}^{n - 1}\left(\sum_{j = i + 1}^{n}(j - i)\right)\right) =
O\left(\sum_{i = 0}^{n - 1}\frac{(1 + n - i)(n - i)}{2}\right) =
O(n^3)
$$

* Space complexity : $$O(min(n, m))$$. We need $$O(k)$$ space for checking a substring has no duplicate characters, where $$k$$ is the size of the `Set`. The size of the Set is upper bounded by the size of the string $$n$$ and the size of the charset/alphabet $$m$$.

---
#### Approach #2 Sliding Window [Accepted]

**Algorithm**

The naive approach ...

**Java**

```java
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
        }
    }
}
```

**Complexity Analysis**

* Time complexity : $$O(2n) = O(n)$$. In the worst case each character will be visited twice by $$i$$ and $$j$$.

* Space complexity : $$O(min(m, n))$$. Same as the previous approach. We need $$O(k)$$ space for the sliding window, where $$k$$ is the size of the `Set`. The size of the Set is upper bounded by the size of the string $$n$$ and the size of the charset/alphabet $$m$$.
    