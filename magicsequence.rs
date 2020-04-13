use std::io::{self, BufRead};
use std::mem;
use std::f32;
use std::cmp::max;

const BASE: u32 = 16;

struct MagicSequence {
        curr: u32,
        i: usize,
        a: Vec<u32>,
        b: u32,
        c: u32,
}

impl Iterator for MagicSequence {
    type Item = u32;

    fn next(&mut self) -> Option<u32> {
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

fn magicsequence(a: Vec<u32>, b: u32, c:u32, hash: bool) -> MagicSequence {
    MagicSequence {
        curr: if hash { a[0] % c } else { a[0] },
        i: 1,
        a: a,
        b: b,
        c: c }
}

fn bucket_sort(l: Vec<u32>, rad: u32) -> Vec<u32>{
    let mut buckets = vec![Vec::new(); BASE as usize];
    for &v in l.iter() {
        buckets[((v >> (rad << 2)) & 0xF) as usize].push(v);
        //buckets[((v / BASE.pow(rad)) % BASE) as usize].push(v);
    }

    let mut res = Vec::new();
    for i in 0..buckets.len() {
        if rad > 0 {
            let bucket = mem::replace(&mut buckets[i], Vec::new());
            buckets[i] = bucket_sort(bucket, rad - 1);
        }
        res.extend(buckets[i].iter());
    }

    res
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let tc = lines.next().unwrap().unwrap().parse::<u32>().unwrap();

    for _ in 0..tc {
        let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
        let abc = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<u32>().unwrap()).collect::<Vec<_>>();
        let (a, b, c) = (abc[0], abc[1], abc[2]);
        let xy = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<u32>().unwrap()).collect::<Vec<_>>();
        let (x, y) = (xy[0], xy[1]);

        // Compute S
        let s = magicsequence(vec![a; n], b, c, false).collect::<Vec<u32>>();

        // Sort S
        let r = bucket_sort(s, max((a as f32).log(BASE as f32) as u32, (c as f32).log(BASE as f32) as u32));

        // Compute hash
        let v = magicsequence(r, x, y, true).collect::<Vec<_>>();
        let hash: u32 = *v.iter().last().unwrap();

        println!("{}", hash);
    }
}
