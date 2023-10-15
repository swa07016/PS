    int getFifthPlayerScore() {
        if(players.size() < 5) return 987654321;
        return players[4];
    }

    int getScore() {
        if(players.size() < 4) return -1;
        return players[0] + players[1] + players[2] + players[3];
    }