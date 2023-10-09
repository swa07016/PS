#include <iostream>
#include <algorithm>

using namespace std;

int n;

class Player {
public:
    int back;
    int p, q, r;
    Player(int b, int p, int q, int r) {
        this->back = b;
        this->p = p;
        this->q = q;
        this->r = r;
    }

    int getMultScore() {
        return p * q * r;
    }

    int getSumScore() {
        return p + q + r;
    }
};

bool compare(Player& pa, Player& pb) {
    if(pa.getMultScore() == pb.getMultScore()) {
        if(pa.getSumScore() == pb.getSumScore()) {
            return pa.back < pb.back;
        }
        else return  pa.getSumScore() < pb.getSumScore();
    }
    return pa.getMultScore() < pb.getMultScore();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<Player> players;

    for(int i=0; i<n; i++) {
        int b, p, q, r;
        cin >> b >> p >> q >> r;

        players.push_back(Player(b, p, q, r));
    }

    sort(players.begin(), players.end(), compare);

    for(int i=0; i<3; i++) {
        cout << players[i].back << " ";
    }

    return 0;
}