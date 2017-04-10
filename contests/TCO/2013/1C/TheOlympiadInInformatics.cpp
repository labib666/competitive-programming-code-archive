#include <algorithm>
#include <vector>
using namespace std;
 
struct TheOlympiadInInformatics {
    
    int find(vector <int> sums, int k)
    {
      int i,z,hi,lo,mid;
      bool a1;
      
      z = sums.size();
      hi = -1;
      
      for(i =0 ; i<z; i++){
        hi = max(hi,sums[i]);
        
      }
      lo = 0;
      long long kk;
      kk = k;
      while(lo<hi)
      {
        mid = (hi+lo)/2;
        
        //solve part
        long long tot = 0;
        for(i  = 0; i< z; i++)
          tot= tot +(sums[i]/(mid+1));
        
        if(tot>k)  a1 = false;
        else     a1 = true;
        // solve done
        if(a1==true) hi = mid;
        else lo = mid+1;
      }
      
      return lo;
    }
 
};