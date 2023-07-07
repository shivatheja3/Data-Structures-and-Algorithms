class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        if(k==0){
            int c=0;
            int res=0;
            for(int i=0;i<answerKey.size();++i){
                if(answerKey[i]=='T'){
                    ++c;
                    res=max(res,c);
                }
                else{
                    c=0;
                }
            }
            for(int i=0;i<answerKey.size();++i){
                if(answerKey[i]=='F'){
                    ++c;
                    res=max(res,c);
                }
                else{
                    c=0;
                }
            }
            return res;
        }
        if(k>=answerKey.size()){
            return answerKey.size();
        }
        int p1=0,p2=0;
        int c=0;
        for(int i=0;i<answerKey.size();++i){
            if(answerKey[i]=='T'){
                ++c;
            }
        }
        int res=0;
        if(c>=1){
            res=1;
        }
        if(c==answerKey.size()){
            return c;
        }
        if(c==0){
            return k;
        }
        c=0;
        for(int i=0;i<answerKey.size();++i){
            if(answerKey[i]=='F'){
                ++c;
            }
        }
        if(c==answerKey.size()){
            return c;
        }
        // int res=0;
        if(c>=1){
            res=1;
        }
        if(c==0){
            return k;
        }
        int temp=k;
        while(p2<answerKey.size()){
            if(answerKey[p2]=='T'){
                ++p2;
            }
            else if(temp>0&&answerKey[p2]=='F'){
                --temp;
                ++p2;
            }
            else{
                if(answerKey[p1]=='F')
                    temp++;
                ++p1;
            }
            res=max(res,p2-p1+1);
        }
        temp=k;
        p1=0;
        p2=0;
        while(p2<answerKey.size()){
            if(answerKey[p2]=='F'){
                ++p2;
            }
            else if(temp>0&&answerKey[p2]=='T'){
                --temp;
                ++p2;
            }
            else{
                if(answerKey[p1]=='T')
                    temp++;
                ++p1;
            }
            res=max(res,p2-p1+1);
        }
        return res-1;
    }
};