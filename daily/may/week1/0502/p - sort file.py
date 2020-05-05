import re
def solution(files:[])->[]:
    answer = []
    heads = {}
    for file in files:
        head = re.search('[a-zA-Z \-\.]+', file).group().lower()
        numb = int(re.search('\d{1,5}', file).group())

        if head not in heads:
            heads[head] = {}
        
        if numb not in heads[head]:
            heads[head][numb] = []

        heads[head][numb].append(file)

    for head, nums in sorted(heads.items(), key = lambda x: x[0]):
        for num, files in sorted(nums.items(), key = lambda x: x[0]):
            for file in files:
                answer.append(file)

    return answer

if __name__ == "__main__":
    files =  ["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]
    solution(files)