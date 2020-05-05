import re

def solution(dartResult):
    answer = 0
    strings = re.findall('\d+[SDT][\*#]*', dartResult)
    scores = []
    for string in strings:
        num = int(re.search('\d+', string).group())
        sdt = re.search('[SDT]', string).group()
        app = re.search('[#\*]+', string)

        if sdt == 'D':
            num *= num
        elif sdt == 'T':
            num **= 3
        
        if app is not None:
            app = app.group()
            if app == '#':
                scores.append(-num)
            else:
                if len(scores) != 0:
                    scores[-1] *= 2
                scores.append(2 * num)
        else:
            scores.append(num)
            
    return sum(scores)

if __name__ == "__main__":
    dartResult = "1S2D*3T"
    print(solution(dartResult))