#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n, m, tmp;
/*
    숫자버튼 배열
    true : 고장남
    false : 멀쩡함
*/
bool num_button[10];
int ans = 987654321;

/*  
    설정한 채널이 멀쩡한 버튼들로만 
    구성되어있는지 여부 반환
*/
bool isValidChannel(int channel) {
    if(channel == 100) return true;
    string string_channel = to_string(channel);
    for(int i=0; i<string_channel.size(); i++) {
        int idx = string_channel[i] - '0';
        if(num_button[idx]) return false;
    }
    return true;
}

/*
    설정한 채널로부터 목표 채널까지 
    + 또는 - 버튼을 몇 번 눌러야 하는지 반환
*/
int getClickCount(int channel) {
    int ret;
    if(channel > n) ret = channel - n;
    else ret = n - channel;
    return ret;
}

/*
    채널의 길이(자리수) 반환
*/
int getChannelLength(int channel) {
    if(channel == 100) return 0;
    return to_string(channel).size();
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    // 고장난 버튼 표시
    for(int i=0; i<m; i++) {
        cin >> tmp;
        num_button[tmp] = true;
    }
    /*
        유효한 채널이라면 
        숫자를 누른 횟수(채널의 자리수) + (+ 또는 -)를 누르는 횟수를
        구해서 최솟값을 갱신해줌
    */
    for(int i=0; i<=1000000; i++) {
        if(isValidChannel(i)) 
            ans = min(ans, getChannelLength(i) + getClickCount(i));
    }

    if(n == 100) ans = 0;
    cout << ans;
    return 0;
}
