use std::io::{self, BufRead};
use std::cmp;

const MAX_H:usize = 155;
const MAX_W:usize = 132;

fn main() {
    let mut map = [[0; MAX_W]; MAX_H];
    let mut cmap = [[0; MAX_W]; MAX_H];

    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let hw = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let (h, w) = (hw[0], hw[1]);

    let ab = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let (a, b) = (ab[0], ab[1]);

    for i_h in 0..h {
        for (i_w, s) in lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<usize>().unwrap()).enumerate() {
            // Leave first column & rows empty for building the cumulative map
            map[i_h + 1][i_w + 1] = s;
        }
    }

    for i_h in 0..h {
        for i_w in 0..w {
            cmap[i_h + 1][i_w + 1] = map[i_h + 1][i_w + 1]
                                        + cmap[i_h][i_w + 1]
                                        + cmap[i_h + 1][i_w]
                                        - cmap[i_h][i_w];
        }
    }

    let cmap = cmap;

    let mut densities = Vec::<f32>::new();

    for r_h in 1..cmp::min(b,h) + 1 {
        for r_w in cmp::max(1, a/r_h)..cmp::min(b/r_h, w) + 1 {
            for i_h in 1..h - r_h + 2 {
                for i_w in 1..w - r_w + 2 {
                    densities.push(
                        (cmap[i_h + r_h - 1][i_w + r_w - 1]
                        + cmap[i_h - 1][i_w - 1]
                        - cmap[i_h - 1][i_w + r_w - 1]
                        - cmap[i_h + r_h - 1][i_w - 1]) as f32/(r_h * r_w) as f32);
                }
            }
        }
    }

    densities.sort_by(|a, b| b.partial_cmp(a).unwrap());

    println!("{}", if densities.len() % 2 == 0
             { (densities[densities.len()/2 - 1] + densities[densities.len()/2])/2.}
             else { densities[densities.len()/2] });
}
