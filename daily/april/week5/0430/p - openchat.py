def solution(records):
    answer = []
    id_nickname = {}
    for record in records:
        record = record.split()

        if len(record) == 3:
            cmd, id, nick_name = record[0], record[1], record[2]
        else:
            cmd, id = record[0], record[1]

        if id not in id_nickname.keys():
            id_nickname[id] = nick_name
        
        if cmd == "Change":
            id_nickname[id] = nick_name
        elif cmd == "Enter":
            answer.append([cmd, id])
            id_nickname[id] = nick_name
        else:
            answer.append([cmd, id])
    
    for idx, string in enumerate(answer):
        if string[0] == 'Enter':
            answer[idx] = id_nickname[string[1]] + "님이 들어왔습니다."
        else:
            answer[idx] = id_nickname[string[1]] + "님이 나갔습니다."

    return answer

if __name__ == "__main__":
    records = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    print(solution(records))