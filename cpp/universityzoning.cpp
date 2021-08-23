#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>

using namespace std;

struct Student {
    int D;
    int r;
    int c;
    int dist;
};

int main () {
    int R, C, F, S, G;

    cin >> R >> C >> F >> S >> G;

    vector<vector<pair<int, int>>> faculties(F);
    vector<int> min_students(F);
    vector<vector<Student>> students(F);

    for(int f=0; f<F; f++) {
        int K;
        cin >> K;
        while(K--) {
            int rf, cf;
            cin >> rf >> cf;
            faculties[f].push_back(make_pair(rf, cf));
        }
    }

    for(int s=0; s<S; s++) {
        int r, c, D, f;
        cin >> r >> c >> D >> f;
        students[f-1].push_back(Student {D, r, c, -1});
    }

    for(int f=0; f<F; f++) {
        int T;
        cin >> T;
        min_students[f] = T;
    }


    vector<int> cost(F);

    for(int f=0; f<F; f++) {
        sort(faculties[f].begin(), faculties[f].end());
        sort(students[f].begin(), students[f].end(),
                [](const Student& a, const Student& b) {
                    return a.D < b.D;
                });

        for(int s=0; s<students[f].size(); s++) {
            students[f][s].dist =
                abs(faculties[f][s].first - students[f][s].r)
              + abs(faculties[f][s].second - students[f][s].c);
        }

        sort(students[f].begin(), students[f].end(),
                [](const Student& a, const Student& b) {
                    return a.dist < b.dist;
                });

        for(int s=0; s < min_students[f]; s++)
            cost[f] += students[f][s].dist;
    }

    sort(cost.begin(), cost.end());
    int res = accumulate(cost.begin(), cost.begin() + G, 0);

    cout << res << "\n";

    return 0;
}
