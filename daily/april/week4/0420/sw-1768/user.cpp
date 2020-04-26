typedef struct {
    int strike;
    int ball;
} Result;

// API
extern Result query(int guess[]);

bool num[9877];
int number[5040];

bool flag = true;

int idx = 0;

void init() {
    if (flag) {
        flag = false;

        for (int i = 123; i < 9876; ++i) {
            int sb1 = i / 1000;
            int sb2 = i % 1000 / 100;
            int sb3 = i % 100 / 10;
            int sb4 = i % 10;

            if (sb1 != sb2 && sb1 != sb3 && sb1 != sb4 && sb2 != sb3 && sb2 != sb4 && sb3 != sb4)
                number[idx++] = i;
        }
    }

    for (int i = 0; i < idx; ++i)
        num[number[i]] = true;
}

Result cmp(int n, int c) {
    Result r;

    r.strike = 0;
    r.ball = 0;

    int chk[10] = {0};

    for (int i = 0; i < 4; ++i) {
        if (n % 10 == c % 10)
            r.strike++;
        else {
            chk[n % 10]++;
            chk[c % 10]++;
        }

        if (chk[n % 10] == 2)
            r.ball++;
        
        if (chk[c % 10] == 2)
            r.ball++;
        
        n /= 10;
        c /= 10;
    }

    return r;
}

void doUserImplementation(int guess[]) {

    init();

    while(1) {
        int ans;

        for (int i = 0; i < idx; ++i) {
            if (num[number[i]]) {
                ans = number[i];

                guess[0] = ans / 1000;
                guess[1] = ans % 1000 / 100;
                guess[2] = ans % 100 / 10;
                guess[3] = ans % 10;

                break;
            }
        }

        Result result = query(guess);

        if (result.strike == 4)
            break;
        else
            num[ans] = false;
        
        for (int i = 0; i < idx; ++i) {
            if (num[number[i]]) {
                Result rslt = cmp(ans, number[i]);

                if (result.strike != rslt.strike || result.ball != rslt.ball)
                    num[number[i]] = false;
            }
        }
        
    }
}