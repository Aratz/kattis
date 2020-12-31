use std::io::{self, BufRead};
use std::collections::VecDeque;

enum Command {
    PushBack(u32),
    PushFront(u32),
    PushMiddle(u32),
    Get(usize),
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n = lines.next().unwrap().unwrap().parse::<u32>().unwrap();

    let mut lower: VecDeque<u32> = VecDeque::new();
    let mut higher: VecDeque<u32> = VecDeque::new();

    for _ in 0..n {
        let raw_command = lines.next().unwrap().unwrap().split(" ")
            .map(|s| String::from(s)).collect::<Vec<_>>();

        let command = match &raw_command[0][..] {
            "push_back" => Command::PushBack(raw_command[1].parse().unwrap()),
            "push_front" => Command::PushFront(raw_command[1].parse().unwrap()),
            "push_middle" => Command::PushMiddle(raw_command[1].parse().unwrap()),
            "get" => Command::Get(raw_command[1].parse().unwrap()),
            _ => panic!("Unrecognized command!"),
        };

        match command {
            Command::PushBack(x) => {
                higher.push_back(x);
            },
            Command::PushFront(x) => {
                lower.push_front(x);
            },
            Command::PushMiddle(x) => {
                if lower.len() == higher.len() {
                    lower.push_back(x);
                }
                else {
                    higher.push_front(x);
                }
            },
            Command::Get(x) => {
                if x < lower.len() {
                    println!("{}", lower[x]);
                }
                else {
                    println!("{}", higher[x - lower.len()]);
                }
            },
        }

        if lower.len() > higher.len() + 1 {
            higher.push_front(lower.pop_back().unwrap());
        }
        else if lower.len() < higher.len() {
            lower.push_back(higher.pop_front().unwrap());
        }
    }
}
