use std::io::{self, BufRead};
use std::collections::{BinaryHeap, HashSet};
use std::cmp::Reverse;

struct Adventurer {
    name: String,
    skills: [u32; 3],
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let _n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut skillheaps: [BinaryHeap<(u32, Reverse<&str>)>; 3] = [
            BinaryHeap::new(),
            BinaryHeap::new(),
            BinaryHeap::new()];

    let mut selected: HashSet<&str> = HashSet::new();

    let adventurers = lines.map(|l| {
        let a = l.unwrap().split(" ").map(|s| String::from(s)).collect::<Vec<_>>();
        Adventurer {
            name: String::from(&a[0]),
            skills: [
                a[1].parse().unwrap(),
                a[2].parse().unwrap(),
                a[3].parse().unwrap()] } }).collect::<Vec<Adventurer>>();

    for adventurer in adventurers.iter() {
        for i in 0..3 {
            skillheaps[i].push((adventurer.skills[i], Reverse(&adventurer.name)));
        }
    }

    loop {
        let mut team:Vec<&str> = Vec::new();

        for i in 0..3 {
            while let Some((_, Reverse(name))) =  skillheaps[i].pop() {
                if selected.contains(name) {
                    continue;
                }

                selected.insert(name);
                team.push(name);
                break;
            }
        }
        if team.len() < 3 { break; };
        team.sort();

        println!("{} {} {}", team[0], team[1], team[2]);
    }
}
