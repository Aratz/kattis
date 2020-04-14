use std::io::{self, BufRead};
use std::collections::BTreeSet;

enum Command {
    Add(u64, u64),
    Query(u64),
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n = lines.next().unwrap().unwrap().parse::<u64>().unwrap();

    let mut pool: BTreeSet<(u64, u64, u64)> = BTreeSet::new();

    for cid in 0..n {
        let raw_command = lines.next().unwrap().unwrap().split(" ")
            .map(|s| String::from(s)).collect::<Vec<_>>();

        let command = match &raw_command[0][..] {
            "add" => Command::Add(raw_command[1].parse().unwrap(), raw_command[2].parse().unwrap()),
            "query" => Command::Query(raw_command[1].parse().unwrap()),
            _ => panic!("Unrecognized command!"),
        };

        match command {
            Command::Add(e, g) => {
                pool.insert((e, g, cid));
            },
            Command::Query(x) => {
                let mut energy = x;
                let mut gold = 0;

                while let Some((e, g, cid)) = pool.range((0, 0, 0)..(energy + 1, 0, 0))
                    .next_back() {
                        gold += g;
                        energy -= e;
                        pool.remove(&(*e, *g, *cid));
                }

                println!("{}", gold);
            }
        }
    }

}
