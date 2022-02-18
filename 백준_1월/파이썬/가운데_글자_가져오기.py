def solution(s):
    answer = ''
    len1 = len(s)
    mid = int(len1/2) #int()안하면 소수 되더라.
    
    if len1 %2 == 0: #단어의 길이가 짝수
        answer = s[mid-1] + s[mid]
    else: #홀수
        answer = s[mid]

    return answer
