use std::io::{self, BufRead};
use std::cmp;

const MAX_H:usize = 155;
const MAX_W:usize = 132;

fn quickselect(list: &mut [f32], k:usize) -> f32 {
    if list.len() == 1 {
        list[0]
    }
    else {
        let pivot = list.len()/2;
        list.swap(pivot, list.len() - 1);
        let mut j = 0;
        for i in 0..list.len() - 1 {
            if list[i] <= list[list.len() - 1] {
                list.swap(i, j);
                j += 1;
            }
        }
        list.swap(j, list.len() - 1);

        if k < j {
            quickselect(&mut list[..j], k)
        }
        else if k > j{
            quickselect(&mut list[j + 1..], k - j - 1)
        }
        else {
            list[j]
        }
    }
}

fn quickselect_median(list : &mut [f32]) -> f32 {
    if list.len() % 2 == 1 {
        quickselect(list, list.len()/2)
    }
    else {
        (quickselect(list, list.len()/2)
         + quickselect(list, list.len()/2 - 1))/2.
    }
}

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
        for r_w in (a as f32/r_h as f32).ceil() as usize..cmp::min(b/r_h, w) + 1 {
            for i_h in 1..h - r_h + 2 {
                for i_w in 1..w - r_w + 2 {
                    //eprintln!("Rec {}x{} ({}, {}) ({}, {})",
                    //r_h, r_w, i_h - 1, i_w - 1, i_h + r_h - 1, i_w + r_w - 1);
                    densities.push(
                        (cmap[i_h + r_h - 1][i_w + r_w - 1]
                        + cmap[i_h - 1][i_w - 1]
                        - cmap[i_h - 1][i_w + r_w - 1]
                        - cmap[i_h + r_h - 1][i_w - 1]) as f32/(r_h * r_w) as f32);
                }
            }
        }
    }

    //densities.sort_by(|a, b| b.partial_cmp(a).unwrap());

    println!("{}", quickselect_median(&mut densities));
}
