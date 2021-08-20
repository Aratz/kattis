#include<string>
#include<vector>
#include<iostream>
#include<deque>

#define WALL -2
#define TODO -1

using namespace std;

class Coord {
    public:
        int l;
        int r;
        int c;

    Coord() : l(0), r(0), c(0) {}
    Coord(int l, int r, int c) : l(l), r(r), c(c) {}

    Coord operator+(const Coord& b) const {
        Coord c {this->l + b.l, this->r+b.r, this->c + b.c};
        return c;
    }

    bool operator==(const Coord& b) const {
        return this->l == b.l && this->r == b.r && this->c == b.c;
    }

};

std::ostream& operator<< (std::ostream &out, Coord const& coord) {
    out << "(" << coord.l << ", " << coord.r << ", " << coord.c << ")";
    return out;
}

int main() {
    int L, R, C;
    while(true) {
        cin >> L >> R >> C;
        if(L==0) break;

        vector<vector<vector<int>>> dungeon(L, vector<vector<int>>(R, vector<int>(C, TODO)));
        Coord start, exit;

        for(int l=0; l<L; l++) {
            for(int r=0; r<R; r++) {
                string row;
                cin >> row;
                for(int c=0; c<C; c++) {
                    int i = 0;
                    if(row[c] == '#') dungeon[l][r][c] = WALL;
                    else if(row[c] == 'S') {
                        dungeon[l][r][c] = 0;
                        start = Coord(l, r, c);
                    }
                    else if(row[c] == 'E') {
                        exit = Coord(l, r, c);
                    }
                }
            }
        }

        vector<Coord> dir = {
            Coord(-1, 0, 0), Coord(1, 0, 0),
            Coord(0, -1, 0), Coord(0, 1, 0),
            Coord(0, 0, -1), Coord(0, 0, 1),
        };

        deque<Coord> queue = { start };

        int res = 0;

        while(!queue.empty()) {
            Coord current = queue.front(); queue.pop_front();
            for(auto d: dir) {
                Coord next = current + d;
                if (
                        0 <= next.l && next.l < L
                     && 0 <= next.r && next.r < R
                     && 0 <= next.c && next.c < C
                   ) {
                    if(dungeon[next.l][next.r][next.c] == TODO) {
                        dungeon[next.l][next.r][next.c] =
                            dungeon[current.l][current.r][current.c] + 1;
                        queue.push_back(next);

                        if(next == exit) {
                            res = dungeon[current.l][current.r][current.c] + 1;
                            break;
                        }
                    }
                }
            }
            if(res != 0) break;
        }
        if(res != 0) {
            cout << "Escaped in " << res << " minute(s).\n";
        }
        else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}
