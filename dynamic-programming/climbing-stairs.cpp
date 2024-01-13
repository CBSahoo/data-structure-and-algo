int climbStairs(int n) {
      if (n == 1 || n == 2) {
          return n;
      }

      int prev = 1, curr = 2;
      int ans = 0;

      for(int i = 2; i < n; i++) {
          ans = prev + curr;
          prev = curr;
          curr = ans;
      }

      return ans;
  }
