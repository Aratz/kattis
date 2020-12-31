use std::io::{self, BufRead};

enum Seed {
    Magic(u64, usize),
    Hash(Vec<u64>),
}

struct MagicSequence {
        curr: u64,
        i: usize,
        a: Seed,
        b: u64,
        c: u64,
}

impl Iterator for MagicSequence {
    type Item = u64;

    fn next(&mut self) -> Option<u64> {
        let n = match &self.a {
            Seed::Magic(_, n) => *n,
            Seed::Hash(v) => v.len(),
        };

        if self.i < n {
            let old = self.curr;
            let a_i = match &self.a {
                Seed::Magic(v, _) => *v,
                Seed::Hash(v) => v[self.i],
            };

            self.curr = (old * self.b + a_i) % self.c;

            self.i += 1;

            Some(old)
        }
        else if self.i == n {
            self.i += 1;

            Some(self.curr)
        }
        else {
            None
        }
    }
}

fn magicsequence(a: Seed, b: u64, c:u64) -> MagicSequence {
    let (curr, a) = match a {
            Seed::Magic(v, n) => (v, Seed::Magic(v, n)),
            Seed::Hash(v) => (v[0] % c, Seed::Hash(v)),
        };

    MagicSequence {
        curr: curr,
        i: 1,
        a: a,
        b: b,
        c: c }
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let tc = lines.next().unwrap().unwrap().parse::<u64>().unwrap();

    for _ in 0..tc {
        let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
        let abc = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<u64>().unwrap()).collect::<Vec<_>>();
        let (a, b, c) = (abc[0], abc[1], abc[2]);
        let xy = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<u64>().unwrap()).collect::<Vec<_>>();
        let (x, y) = (xy[0], xy[1]);

        // Compute S
        eprintln!("Compute S");
        let mut s = magicsequence(Seed::Magic(a, n), b, c).collect::<Vec<u64>>();

        // Sort S
        eprintln!("Sort S");
        s.sort_unstable();

        // Compute hash
        eprintln!("Compute hash");
        let hash: u64 = magicsequence(Seed::Hash(s), x, y).last().unwrap();

        println!("{}", hash);
    }
}
