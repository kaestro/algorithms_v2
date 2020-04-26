def solution(s: str):
    answer = ''
    temp = list(map(str.capitalize, s.split()))
    
    return ' '.join(temp)