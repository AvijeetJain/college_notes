from collections import defaultdict
import copy
graph = defaultdict(list)

def addEdge(graph,u,v):
    graph[u].append(v); 
   
vis={'WA':0,'NT':0,'SA':0,'Q':0,'NSW':0,'V':0}

vis2={'T':0}

colors={'1':0,'2':0,}

addEdge(graph,'WA','NT')
addEdge(graph,'WA','SA')
addEdge(graph,'NT','SA')
addEdge(graph,'NT','Q')
addEdge(graph,'SA','Q')
addEdge(graph,'SA','NSW')
addEdge(graph,'SA','V')
addEdge(graph,'V','NSW')
addEdge(graph,'Q','NSW')

addEdge(graph,'NT','WA')
addEdge(graph,'SA','WA')
addEdge(graph,'SA','NT')
addEdge(graph,'Q','NT')
addEdge(graph,'Q','SA')
addEdge(graph,'NSW','SA')
addEdge(graph,'V','SA')
addEdge(graph,'NSW','V')
addEdge(graph,'NSW','Q')

a=0
answers=[]
answers2=[]
def find(node,key,vis):
    for i in graph[node]:
        if(vis[i]==key):
            return False
    return True 

def color(node,vis,total,colors):
    for key,value in colors.items():
        key=int(key)
        canwe=find(node,key,vis)
        if(canwe):
            vis[node]=key
            if(total==vis.__len__()-1):
                found=-1
                for i in answers:
                    if(i==vis):
                        found=1
                        break
                if(found==-1):
                    copi=copy.deepcopy(vis)
                    if(copi.__len__()==1):
                        answers2.append(copi)
                    else:
                        answers.append(copi) 

            for i,j in vis.items():
                if(j==0): 
                    color(i,vis,total+1,colors)
            vis[node]=0        
for key,value in vis.items():
    if(value==0):
        color(key,vis,0,colors)

for key,value in vis2.items():
    if(value==0):
        color(key,vis2,0,colors)    
final=[]     
for i in answers:
    for j in answers2:
        sol={}
        for key,value in i.items():
            if(value==1):
                sol[key]='RED'
            elif(value==2):
                sol[key]='GREEN'
            else:
                sol[key]='BLUE'
        for key,value in j.items():
            if(value==1):
                sol[key]='RED'
            elif(value==2):
                sol[key]='GREEN'
            else:
                sol[key]='BLUE'
        final.append(sol)        
for i in final:
    print(i)
