def solution(num_bus : int, time_interval:int, bus_capacity:int, time_table:[])->str:
    answer = ''
    start_time = 9 * 60
    arrival_time_bus = [start_time + i * time_interval for i in range(num_bus)]
    bus_person = {arrival_time : [] for arrival_time in arrival_time_bus}
    time_table.sort()
    min_time = start_time
    for time in time_table:
        time = time.split(':')
        time = int(time[0]) * 60 + int(time[1])
        if time <= min_time:
            bus_person[min_time].append(time)
            if len(bus_person[min_time]) == bus_capacity:
                min_time += time_interval
        elif any(time <= n for n in arrival_time_bus):
            min_time = min(n for n in arrival_time_bus if n >= time)
            bus_person[min_time].append(time)
        else:
            break
    
    if len(bus_person[arrival_time_bus[-1]]) == bus_capacity:
        ans_int = bus_person[arrival_time_bus[-1]][-1] - 1
    else:
        ans_int = arrival_time_bus[-1]
    
    answer = str(ans_int // 60).zfill(2) + ':' + str(ans_int % 60).zfill(2)
    return answer

if __name__ == "__main__":
    n, t, m, time_table = 1, 1, 5, ['08:00', '08:01', '08:02', '08:03']	
    n, t, m, time_table = 2, 10,2,['09:10', '09:09', '08:00']
    n, t, m, time_table = 2, 1,	2, ['09:00', '09:00', '09:00', '09:00']
    n, t, m, time_table = 1, 1, 1, ['23:59']
    print(solution(n, t, m, time_table))