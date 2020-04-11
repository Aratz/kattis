use std::io::{self, BufRead};

fn spread(mut map: &mut Vec<Vec<usize>>, start: (usize, usize), color: usize) {
    let neighbors:Vec<(i32, i32)> = vec![
        (start.0 as i32 - 1, start.1 as i32),
        (start.0 as i32 + 1, start.1 as i32),
        (start.0 as i32, start.1 as i32 - 1),
        (start.0 as i32, start.1 as i32 + 1),
    ];

    let zone = map[start.0][start.1];

    map[start.0][start.1] = color;

    let valid_neighbors = neighbors.iter().filter(|(i, j)|
        0 <= *i && *i < map.len() as i32
     && 0 <= *j && *j < map[0].len() as i32).collect::<Vec<_>>();

    for (i, j) in valid_neighbors.iter() {
        if map[*i as usize][*j as usize] == zone {
            spread(&mut map, (*i as usize, *j as usize), color);
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let rc = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let (r, c) = (rc[0], rc[1]);

    let mut map = Vec::new();

    for _ in 0..r {
        map.push(
            lines.next().unwrap().unwrap().chars()
            .map(|x| x.to_digit(10).unwrap() as usize).collect::<Vec<_>>()
            );
    }

    let mut current_color_bin = 2;
    let mut current_color_dec = 3;

    for i in 0..r {
        for j in 0..c {
            if map[i][j] < 2 {
                if map[i][j] == 0 {
                    spread(&mut map, (i, j), current_color_bin);
                    current_color_bin += 2;
                }
                else {
                    spread(&mut map, (i, j), current_color_dec);
                    current_color_dec += 2;
                }
            }
        }
    }

    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    for _ in 0..n {
        let rcrc = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
        let (r1, c1, r2, c2) = (rcrc[0] - 1, rcrc[1] - 1, rcrc[2] - 1, rcrc[3] - 1);

        if map[r1][c1] != map[r2][c2] {
            println!("neither");
        }
        else {
            if map[r1][c1] % 2 == 0 {
                println!("binary");
            }
            else {
                println!("decimal");
            }
        }
    }
}
