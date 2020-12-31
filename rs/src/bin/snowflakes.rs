use std::io::{self, BufRead};
use std::cmp::max;
use std::collections::HashMap;

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t = lines.next().unwrap().unwrap().parse::<i32>().unwrap();

    for _ in 0..t {
        let n = lines.next().unwrap().unwrap().parse::<i32>().unwrap();
        let mut last_seen = HashMap::new();

        let mut longest_streak = 0;
        let mut most_recent_dupl = -1;

        for i in 0..n {
            let snowflake = lines.next().unwrap().unwrap().parse::<i32>().unwrap();

            if let Some(prev) = last_seen.insert(snowflake, i) {
                most_recent_dupl = max(most_recent_dupl, prev);
            }

            longest_streak = max(longest_streak, i - most_recent_dupl);
        }
        println!("{}", longest_streak);
    }
}
