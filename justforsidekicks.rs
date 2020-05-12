use std::io::{self, BufRead};

fn lsone(i: i64) -> i64 {
    i & (-i)
}

struct FenwickTree {
    ft: Vec<i64>,
}

impl FenwickTree {
    fn rsq0(&self, mut b: usize) -> i64 {
        let mut sum = 0;
        while b > 0 {
            eprintln!("rsq0: {}", b);
            sum += self.ft[b];
            b -= lsone(b as i64) as usize;
        }

        sum
    }

    fn rsq(&self, a: usize, b: usize) -> i64 {
        self.rsq0(b) - if a == 1 { 0 } else { self.rsq0(a - 1) }
    }

    fn adjust(&mut self, mut k: usize, v: i64) {
        while k < self.ft.len() {
            eprintln!("adjust: {}", k);
            self.ft[k] += v;
            k += lsone(k as i64) as usize;
        }
    }
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let nq = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let (n, q) = (nq[0], nq[1]);

    let mut vs = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<i64>().unwrap()).collect::<Vec<_>>();

    let mut ps = lines.next().unwrap().unwrap().chars()
        .map(|x| x.to_digit(10).unwrap() as usize).collect::<Vec<_>>();

    let mut fts: Vec<FenwickTree> = vec!{};
    for _ in 0..6 {
        fts.push(FenwickTree { ft: vec!{0; n + 1} });
    }

    for (i, &p) in ps.iter().enumerate() {
        fts[p - 1].adjust(i + 1, 1);
    }

    for _ in 0..q {
        let command = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
        match command[0] {
            1 => {
                let (k, p) = (command[1], command[2]);
                fts[ps[k - 1] - 1].adjust(k, -1);
                ps[k - 1] = p;
                fts[ps[k - 1] - 1].adjust(k, 1);
            },
            2 => {
                let (p, v) = (command[1], command[2]);
                vs[p - 1] = v as i64;
            },
            3 => {
                let (l, r) = (command[1], command[2]);
                let total_value:i64 = fts.iter().map(|ft| ft.rsq(l, r)).zip(vs.iter())
                    .map(|(s, v)| s*v).sum();

                println!("{}", total_value);
            },
            _ => panic!("Unrecognized command!"),
        }
    }
}
