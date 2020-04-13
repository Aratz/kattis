use std::io::{self, BufRead};

struct MagicSequence {
        curr: u64,
        i: usize,
        a: Vec<u64>,
        b: u64,
        c: u64,
}

impl Iterator for MagicSequence {
    type Item = u64;

    fn next(&mut self) -> Option<u64> {
        if self.i < self.a.len() {
            let old = self.curr;
            self.curr = (old * self.b + self.a[self.i]) % self.c;

            self.i += 1;

            Some(old)
        }
        else if self.i == self.a.len() {
            self.i += 1;

            Some(self.curr)
        }
        else {
            None
        }
    }
}

fn magicsequence(a: Vec<u64>, b: u64, c:u64, hash: bool) -> MagicSequence {
    MagicSequence {
        curr: if hash { a[0] % c } else { a[0] },
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
        let mut s = magicsequence(vec![a; n], b, c, false).collect::<Vec<u64>>();

        // Sort S
        s.sort_unstable();

        // Compute hash
        let hash: u64 = magicsequence(s, x, y, true).last().unwrap();

        println!("{}", hash);
    }
}
