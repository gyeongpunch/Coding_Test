n=int(input())
def mx(lst):
    xl=[]
    lst=[[None]*n]+lst+[[None]*n]
    for i,l in enumerate(lst[1:n+1]):
        st=0
        for j in range(n):
            if j<n-1 and l[j]==l[j+1]: continue
            xl.append(j-st+1)
            if j<n-2 and l[j]==l[j+2]: xl[-1]+=1
            if st>0 and l[j] in [lst[i][st-1], lst[i+2][st-1]]:
                xl.append(j-st+2)
                for c in l[st-2:-1:-1]:
                    if c==l[j]: xl[-1]+=1
                    else: break
            if j<n-1 and l[j] in [lst[i][j+1], lst[i+2][j+1]]:
                xl.append(j-st+2)
                for c in l[j+2:]:
                    if c==l[j]: xl[-1]+=1
                    else: break
            st=j+1
    return max(xl)
    
rows=[list(input()) for _ in range(n)]
cols=list(map(list, zip(*rows)))
print(max([mx(rows), mx(cols)]))