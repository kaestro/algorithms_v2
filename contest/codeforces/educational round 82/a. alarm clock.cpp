#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int time_needed, first_alarm, alarm_distance, boot_time;
        cin >> time_needed >> first_alarm >> alarm_distance >> boot_time;
        if (time_needed <= first_alarm) {
            cout << first_alarm << endl;
            continue;
        }

        if (time_needed > first_alarm && alarm_distance <= boot_time) {
            cout << -1 << endl;
            continue;
        }

        int times = (time_needed - first_alarm) / (alarm_distance - boot_time);
        times += ((time_needed - first_alarm) % (alarm_distance - boot_time) != 0);
        cout << (long long)first_alarm + (long long)times * (alarm_distance) << endl;
    }
    return 0;
}