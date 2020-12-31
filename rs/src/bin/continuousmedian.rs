use std::io::{self, BufRead};
use std::cmp::Reverse;
use std::collections::BinaryHeap;

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let t = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    for _ in 0..t {
        let _n = lines.next();
        let a = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<usize>>();

        let mut res_sum = 0;
        let mut lower = BinaryHeap::new();
        let mut upper = BinaryHeap::new();

        for &a_i in a.iter() {
            // Push new item
            if let Some(&l) = lower.peek() {
                if a_i < l {
                    lower.push(a_i);
                }
                else {
                    upper.push(Reverse(a_i));
                }
            }
            else {
                lower.push(a_i);
            }

            // Balance heaps
            if lower.len() < upper.len() {
                lower.push(upper.pop().unwrap().0)
            }
            else if lower.len() > upper.len() + 1 {
                upper.push(Reverse(lower.pop().unwrap()));
            }

            // Compute new median
            res_sum += if lower.len() == upper.len() {
                (lower.peek().unwrap() + upper.peek().unwrap().0)/2
            }
            else {
                *lower.peek().unwrap()
            }
        }

        println!("{}", res_sum);
    }
}
