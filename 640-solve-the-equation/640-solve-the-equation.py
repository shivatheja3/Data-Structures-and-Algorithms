class Solution(object):
    def solveEquation(self, s):
        """
        :type equation: str
        :rtype: str
        """
        s=s.split('=')
        c_x1,c_x2,c_v1,c_v2=0,0,0,0
        if s[0][0]=="-":
            pass
            # print(s[0][0])
        else:
            s[0]='+'+s[0]
        if s[1][0]!="-":
            s[1]='+'+s[1]
        i=0
        print(s)
        for i in range(len(s[0])):
            if s[0][i]=='+':
                j=i+1
                if s[0][j]=='x':
                    c_x1+=1
                    i=j
                else:
                    k=""
                    for j in range(i+1,len(s[0])):
                        if s[0][j]=='+' or s[0][j]=='-':
                            break
                        else:
                            k+=s[0][j]
                    print(k)
                    if k[-1]=='x':
                        if len(k)==1:
                            c_x1+=1
                        else:
                            c_x1+=int(k[:-1])
                    else:
                        k=int(k)
                        c_v1+=k
                    i=j
            elif s[0][i]=='-':
                j=i+1
                if s[0][j]=='x':
                    c_x1-=1
                    i=j
                else:
                    k=""
                    for j in range(i+1,len(s[0])):
                        if s[0][j]=='+' or s[0][j]=='-':
                            break
                        else:
                            k+=s[0][j]
                    print(k)
                    if k[-1]=='x':
                        if len(k)==1:
                            c_x1-=1
                        else:
                            c_x1-=int(k[:-1])
                    else:
                        k=int(k)
                        c_v1-=k
                    i=j
                
        for i in range(len(s[1])):
            if s[1][i]=='+':
                j=i+1
                if s[1][j]=='x':
                    c_x2+=1
                    i=j
                else:
                    k=""
                    for j in range(i+1,len(s[1])):
                        if s[1][j]=='+' or s[1][j]=='-':
                            break
                        else:
                            k+=s[1][j]
                    print(k)
                    if k[-1]=='x':
                        # c_x2+=int(k[:-1])
                        if len(k)==1:
                            c_x2+=1
                        else:
                            c_x2+=int(k[:-1])
                    else:
                        k=int(k)
                        c_v2+=k
                    i=j
            elif s[1][i]=='-':
                j=i+1
                if s[1][j]=='x':
                    c_x2-=1
                    i=j
                else:
                    k=""
                    for j in range(i+1,len(s[1])):
                        if s[1][j]=='+' or s[1][j]=='-':
                            break
                        else:
                            k+=s[1][j]
                    print(k)
                    if k[-1]=='x':
                        # c_x2-=int(k[:-1])
                        if len(k)==1:
                            c_x2-=1
                        else:
                            c_x2-=int(k[:-1])
                    else:
                        k=int(k)
                        c_v2-=k
                    i=j 
        
                
        print(c_x1,c_x2,c_v1,c_v2)
        if c_x1==c_x2 and c_v1==c_v2:
            return "Infinite solutions"
        elif c_x1==c_x2 and c_v1!=c_v2:
            return "No solution"
        else:
            if c_x1>c_x2:
                return "x="+str((-c_v1+c_v2)//(c_x1-c_x2))
            else:
                return "x="+str(-(-c_v1+c_v2)//(c_x2-c_x1))
        return ''
            
        
        