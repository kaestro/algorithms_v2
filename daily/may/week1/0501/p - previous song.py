def exchange(string: str):
    string = string.replace("C#", "H")
    string = string.replace("D#", "I")
    string = string.replace("F#", "J")
    string = string.replace("G#", "K")
    string = string.replace("A#", "L")
    return string


def solution(m, musicinfos):
    answer = '(None)'
    m = exchange(m)

    maxlength = 0
    for info in musicinfos:
        info = info.split(',')

        start_time, end_time = info[0].split(":"), info[1].split(":")
        start_time = int(start_time[0]) * 60 + int(start_time[1])
        end_time = int(end_time[0]) * 60 + int(end_time[1])

        length, title, melody = end_time - start_time, info[2], info[3]
        melody = exchange(melody)

        melody = melody * (length // len(melody)) + melody[0:(length % len(melody))]

        if melody.find(m) != -1 and length > maxlength:
            maxlength = length
            answer = title

    return answer

if __name__ == "__main__":
    m = "ABCDEFG"
    musicinfos = ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]
    print(solution(m, musicinfos))

    m = "CC#BCC#BCC#BCC#B"
    musicinfos = ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]
    print(solution(m, musicinfos))