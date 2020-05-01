import re

def solution(files:[])->[]:
    answer = []
    head_dict = {}
    for file in files:
        head = re.findall('[a-zA-Z \*.\-]+', file)[0]
        number = re.findall('\d{1,5}', file)[0]
        tail = file[len(head + number):]
        if head.lower() not in head_dict:
            head_dict[head.lower()] = {}
        
        if int(number) not in head_dict[head.lower()]:
            head_dict[head.lower()][int(number)] = []
        head_dict[head.lower()][int(number)].append(file)
    
    head_dict = sorted(head_dict.items(), key = lambda x: x[0])
    for head, number in head_dict:
        number = sorted(number.items(), key = lambda x: x[0])
        for num, filenames in number:
            for filename in filenames:
                answer.append(filename)

    return answer


if __name__ == "__main__":
    files = ["img12.png", "img000101.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]
    files = ["F* -5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"]
    solution(files)