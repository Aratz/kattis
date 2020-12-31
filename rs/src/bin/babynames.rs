use std::io::{self, BufRead};
use std::collections::BTreeMap;

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let mut names: BTreeMap<String, u32> = BTreeMap::new();

    loop {
        let mut raw_command = lines.next().unwrap().unwrap().split(" ")
            .map(|x| String::from(x)).collect::<Vec<_>>();

        match &raw_command[0][..] {
            "0" => {
                break;
            },
            "1" => {
                let gender:u32 = raw_command.remove(2).parse().unwrap();
                let name = raw_command.remove(1);
                names.insert(name, gender);
            },
            "2" => {
                names.remove(&raw_command[1]);
            },
            "3" => {
                let query_gender: u32 = raw_command.remove(3).parse().unwrap();
                let end = raw_command.remove(2);
                let start = raw_command.remove(1);
                println!("{}",
                         names.range(start..end)
                         .filter(|(_name, &gender)| query_gender == 0 || query_gender == gender)
                         .count());
            },
            _ => { panic!("Unrecognized command!"); },
        }
    }
}
