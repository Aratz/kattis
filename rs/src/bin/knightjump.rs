use std::io::{self, BufRead};
use std::collections::VecDeque;

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let mut map: Vec<Vec<i32>> = Vec::new();

    let n = lines.next().unwrap().unwrap().parse::<i32>().unwrap();

    let mut queue: VecDeque<(i32, i32)> = VecDeque::new();

    let moves = vec![
        (2, 1), (2, -1), (-2, 1), (-2, -1),
        (1, 2), (1, -2), (-1, 2), (-1, -2),
    ];

    for i in 0..n {
        map.push(lines.next().unwrap().unwrap().chars().enumerate()
                 .map(|(j, c)| match c {
                     'K' => {
                         queue.push_back((i, j as i32));
                         0
                     },
                     '.' => -1,
                     _ => -2,
                 }).collect());
    }

    while !queue.is_empty() {
        let (x, y) = queue.pop_front().unwrap();
        for (dx, dy) in moves.iter().filter(|(dx, dy)| 0 <= x + dx && x + dx < n
                                                    && 0 <= y + dy && y + dy < n) {
            if map[(x + dx) as usize][(y + dy) as usize] == -1 {
                map[(x + dx) as usize][(y + dy) as usize] = map[x as usize][y as usize] + 1;
                queue.push_back((x + dx, y + dy));
            }
        }

        if map[0][0] > -1 {
            break;
        }
    }

    println!("{}", map[0][0]);
}
