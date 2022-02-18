n_poketmon, n_quiz = map(int, input().split(" "))
map_name = {}
map_idx = []

for i in range(n_poketmon):
    name = input()
    map_idx.append(name)
    map_name[name] = i + 1

#print(map)

for i in range(n_quiz):
    ques = input()
    if ques.isalpha(): #문자
        print(map_name[ques])
    else: #숫자
        print(map_idx[int(ques) - 1])
        
