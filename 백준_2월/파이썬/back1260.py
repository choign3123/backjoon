from collections import deque

node, line, start = list(map(int,input().split()))

graphDict = {0:[]}
visitDictd = {}
visitDictb = {}
order = []

def dfs(graph, start, visitd):
    visitd[0] = True
    visitd[start] = True # 방문한 노드이기에 True처리.
    order.append(str(start)) # 순서대로 Order에 append
    try : 
        for i in graph[start]:
            if visitd[i] == False: #방문하지 않았던 노드라면
                try :
                    dfs(graph, i, visitd) # 그 안으로 또 들어가기.
                except :
                    continue
    except :
        return []
    return order

def bfs(graph, start, visitb):
    visitb[0] = True #임의로 만든 dict이기에 해당 노드 True처리.
    visitb[start] = True # 방문한 노드이기에 True처리.
    order.append(str(start)) # 순서대로 Order에 append
    check = deque() #다음에 체크할노드 차례로 추가
    try : 
        while list(visitb.values()).count(True) != len(graphDict.keys()): # 모든 노드를 방문하기 전까지
            for i in graph[start]:
                if visitb[i] == False: #방문하지 않았다면
                    visitb[i] = True #방문하고
                    order.append(str(i)) #순서에 추가
                    check.append(i) #그 자식노드들은 check에 추가
            if len(check) != 0: #체크가 비어있지 않다면
                start = check.popleft() #체크에서 하나씩 꺼내서 다시 재귀
    except :
        return []
    return order
        
#graphDict 만들기
for i in range(line):
    tmp = list(map(int,input().split()))
    try :
        graphDict[tmp[0]].append(tmp[1])
    except KeyError:
        graphDict[tmp[0]] = list()
        graphDict[tmp[0]].append(tmp[1])
    try :
        graphDict[tmp[1]].append(tmp[0])
    except KeyError:
        graphDict[tmp[1]] = list()
        graphDict[tmp[1]].append(tmp[0])
        
for i in graphDict.items() :
    graphDict[i[0]] = sorted(i[1]) #정렬
    
for i in graphDict.keys():
    visitDictd[i] = False
    visitDictb[i] = False


res_dfs = dfs(graphDict, start, visitDictd)
print(" ".join(res_dfs)) #출력형식을 맞추기 위한 과정

order = []
res_bfs = bfs(graphDict, start, visitDictb)
print(" ".join(res_bfs)) #출력형식을 맞추기 위한 과정
