
# class Solution {
# public:
#     int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
#         int n=s.size();
#         int res=0;
#         for(int i=minSize;i<=maxSize;++i){
#             unordered_map<char,int> h1;
#             unordered_map<string,int> h2;
#             for(int j=0;j<=(i-1);++j)
#                 h1[s[j]]++;
#              if(h1.size()<=maxLetters){
#                 // ++res;
#                  // h2[]
#                  // cout<<i<<" "<<h1.size()<<endl;
#              }
#             for(int j=i;j<n;++j){
#                 h1[s[j-i]]--;
#                 if(h1[s[j-i]]==0){
#                     h1.erase(s[j-i]);
#                 }
#                 h1[s[j]]++;
#                 if(h1.size()<=maxLetters){
#                     ++res;
#                     // cout<<i<<" "<<h1.size()<<endl;
#                 }
#             }
#         }
#         return res;
#     }
# };
class Solution(object):
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        """
        :type s: str
        :type maxLetters: int
        :type minSize: int
        :type maxSize: int
        :rtype: int
        """
        n=len(s)
        res=-100001
        for i in range(minSize,maxSize+1):
            dict1={}
            dict2={}
            for j in range(i):
                if s[j] not in dict1.keys():
                    dict1[s[j]]=1
                else:
                    dict1[s[j]]+=1
            if len(dict1)<=maxLetters:
                if s[:i] not in dict2:
                    dict2[s[:i]]=1
                else:
                    dict2[s[:i]]+=1
            for j in range(i,n):
                dict1[s[j-i]]-=1
                if dict1[s[j-i]]==0:
                    del dict1[s[j-i]]
                if s[j] not in dict1:
                    dict1[s[j]]=1
                else:
                    dict1[s[j]]+=1
                if len(dict1)<=maxLetters:
                    if s[j-i+1:j+1] not in dict2:
                        dict2[s[j-i+1:j+1]]=1
                    else:
                        dict2[s[j-i+1:j+1]]+=1
            for j in dict2.keys():
                # print(dict2[j])
                res=max(res,dict2[j])
        if res==-100001:
            return 0
        return res
        