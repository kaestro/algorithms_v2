def str_to_int_time(time:str)->int:
    time = time.split(":")
    return int(time[0]) * 60 + int(time[1])


def remove_sharp(melody:str)->str:
    melody = melody.replace("C#", "c").replace("D#", "d").replace("F#", "f")
    return melody.replace("G#", "g").replace("A#", "a")


def solution(m, musicinfos):
    answer, max_length = '(None)', 0
    m = remove_sharp(m)
    for musicinfo in musicinfos:
        musicinfo = musicinfo.split(",")
        time_beg, time_end, title, melody = musicinfo[:]

        time_length = str_to_int_time(time_end) - str_to_int_time(time_beg)
        melody = remove_sharp(melody)

        melody = (time_length // len(melody)) * melody + melody[0:time_length % len(melody)]

        if m in melody:
            if time_length > max_length:
                max_length = time_length
                answer = title

    return answer