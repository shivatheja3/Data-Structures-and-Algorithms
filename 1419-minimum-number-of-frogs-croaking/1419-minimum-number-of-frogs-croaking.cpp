class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c=0,r=0,o=0,a=0,k=0,ans = 0, count = 0;

    for(auto &x: croakOfFrogs)
    {
        switch(x)
        {
            case 'c':
                c++;
                count++;
                break;
                
             case 'r':
                r++;
                break;
                
             case 'o':
                o++;
                break;
                
             case 'a':
                a++;
                break;
                
             case 'k':
                k++;
                
                count--;
                break;
        }
        
        ans = max(ans,count);
        
        if((c<r) ||(r < o) ||(o < a) || (a < k))
        {
            return -1;
        }
        
    }
    
    if(count == 0 && c==r && c==o && c==a && c==k)
    {
      return ans;
    }
    
    return -1;
    }
};