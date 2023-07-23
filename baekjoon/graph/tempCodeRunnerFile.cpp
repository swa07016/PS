// 같은 깊이 전부 담고 그중에서 결정하기
            vector<Point> v; v.push_back(Point(y, x));

            while(!q.empty()) {
                Point tmpP = q.front().first;
                if(q.front().second == depth && board[tmpP.y][tmpP.x] >= 1) {
                    v.push_back(q.front().first);
                    q.pop();
                }
                else break;
            }
            
            return decidePoint(v);