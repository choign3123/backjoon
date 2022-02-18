def solution(s):
	answer = ''
	arr = []
	count = 0
	for value in s:
		arr.append(value)
	arr.sort(reverse = True)
	for value in arr:
		answer += value
	return answer
