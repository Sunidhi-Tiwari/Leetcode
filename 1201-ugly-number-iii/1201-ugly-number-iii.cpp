typedef long long ll;
class Solution {
public:
    
     ll lcm(ll a, ll b)
        {
          return (a*b)/__gcd(a,b);
        }
    int nthUglyNumber(int n, int a, int b, int c) {
        
      ll N = ll(n); 
      ll A = ll(a);
      ll B = ll(b);
      ll C = ll(c);
      
       ll lo = 1;
       ll hi = 2000000000;
       ll ans;
       ll mid;
      
      while(lo<=hi)
      {
      
      mid = lo + (hi - lo)/2;
      
      ll cnt = 0;
      
      cnt += (mid/A + mid/B + mid/C);
      cnt -= (mid/lcm(A,B) + mid/lcm(B,C) + mid/lcm(C,A));
      cnt += mid/lcm(A, lcm(B,C));
      
      if(cnt>=N)
      {
      ans = mid;
      hi = mid - 1;
      }
      else
      {
      lo = mid + 1;
      }
      
      }
      
      return ans;
    }
};