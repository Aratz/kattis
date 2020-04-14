use std::io::{self, BufRead};
use std::collections::BTreeSet;

enum Command {
    Add(u32, u32),
    Query(u32),
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n = lines.next().unwrap().unwrap().parse::<u32>().unwrap();

    let mut pool: BTreeSet<(u32, u32)> = BTreeSet::new();

    for _ in 0..n {
        let raw_command = lines.next().unwrap().unwrap().split(" ")
            .map(|s| String::from(s)).collect::<Vec<_>>();

        let command = match &raw_command[0][..] {
            "add" => Command::Add(raw_command[1].parse().unwrap(), raw_command[2].parse().unwrap()),
            "query" => Command::Query(raw_command[1].parse().unwrap()),
            _ => panic!("Unrecognized command!"),
        };

        match command {
            Command::Add(e, g) => {
                pool.insert((e, g));
            },
            Command::Query(x) => {
                let mut energy = x;
                let mut gold = 0;

                while let Some((e, g)) = pool.range((0, 0)..(energy + 1, 0))
                    .next_back() {
                        gold += g;
                        energy -= e;
                        pool.remove(&(*e, *g));
                }

                println!("{}", gold);
            }
        }
    }

}
