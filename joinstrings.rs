use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n:usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut strings:Vec<String> = Vec::with_capacity(n);
    let mut next: Vec<usize> = Vec::with_capacity(n);
    let mut end: Vec<usize> = Vec::with_capacity(n);

    for i in 0..n {
        strings.push(String::from(lines.next().unwrap().unwrap()));
        next.push(i);
        end.push(i);
    }


    let mut last = 0;

    for _ in 0..n - 1 {
        let ab = lines.next().unwrap().unwrap().split(" ")
            .map(|v| v.parse::<usize>().unwrap()).collect::<Vec<_>>();
        let (a, b) = (ab[0] - 1, ab[1] - 1);

        last = a;
        let e_s = end[a];
        next[e_s] = b;
        end[a] = b;
    }

    loop {
        print!("{}", strings[last]);

        if last == next[last] {
            println!();
            break;
        }
        else {
            last = next[last];
        }
    }
}
