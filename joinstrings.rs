use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n:usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut strings:Vec<String> = Vec::new();

    for _ in 0..n {
        strings.push(String::from(lines.next().unwrap().unwrap()));
    }

    for i in 0..n - 1 {
        let ab = lines.next().unwrap().unwrap().split(" ")
            .map(|v| v.parse::<usize>().unwrap()).collect::<Vec<_>>();
        let (a, b) = (ab[0] - 1, ab[1] - 1);

        let new_string = String::from(&strings[a]) + &strings[b];

        strings[a] = new_string;

        if i == n - 2 {
            println!("{}", strings[a]);
        }
    }
}
