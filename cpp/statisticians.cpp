#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define HMAX 155
#define WMAX 132

using namespace std;

int main() {
    int map[HMAX][WMAX] = {0};
    int cmap[HMAX][WMAX] = {0};

    int h, w;
    int a, b;

    scanf("%d %d", &h, &w);
    scanf("%d %d", &a, &b);

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            scanf("%d", &(map[i + 1][j + 1]));
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cmap[i + 1][j + 1] = map[i + 1][j + 1]
                                    + cmap[i][j + 1]
                                    + cmap[i + 1][j]
                                    - cmap[i][j];
        }
    }

    fprintf(stderr, "Computing densities\n");
    vector<float> densities;
    for(int r_h=1; r_h<min(b, h) + 1; r_h++) {
        for(int r_w=ceil(1.0*a/r_h); r_w<min((int) 1.0*b/r_h, w) + 1; r_w++) {
            for (int i_h=1; i_h < h - r_h + 2; i_h++) {
                for(int i_w=1; i_w < w - r_w + 2; i_w++) {
                    densities.push_back(
                        1.0*(cmap[i_h + r_h - 1][i_w + r_w - 1]
                        + cmap[i_h - 1][i_w - 1]
                        - cmap[i_h - 1][i_w + r_w - 1]
                        - cmap[i_h + r_h - 1][i_w - 1])/(r_h * r_w));
                }
            }
        }
    }

    fprintf(stderr, "Sorting\n");
    sort(densities.begin(), densities.end());

    if(densities.size() % 2) {
        printf("%f\n", densities[densities.size()/2]);
    }
    else {
        printf("%f\n", (densities[densities.size()/2 - 1] + densities[densities.size()/2])/2.);
    }

    return 0;
}
