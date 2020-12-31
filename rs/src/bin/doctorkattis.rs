use std::io::{self, BufRead};
use std::collections::{HashMap, BTreeMap};
use std::cmp::{Reverse, min};

enum Command {
    ArriveAtClinic(String, u32),
    UpdateInfectionLevel(String, u32),
    Treated(String),
    Query,
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n: u32 = lines.next().unwrap().unwrap().parse().unwrap();

    let mut cat_register: HashMap<String, (u32, u32)> = HashMap::new();
    let mut infection_register: BTreeMap<(u32, Reverse<u32>), String> = BTreeMap::new();

    for id in 0..n {
        let raw_command = lines.next().unwrap().unwrap().split(" ")
            .map(|x| String::from(x)).collect::<Vec<String>>();
        let command = match &raw_command[0][..] {
            "0" => Command::ArriveAtClinic(raw_command[1].clone(), raw_command[2].parse().unwrap()),
            "1" => Command::UpdateInfectionLevel(raw_command[1].clone(), raw_command[2].parse().unwrap()),
            "2" => Command::Treated(raw_command[1].clone()),
            "3" => Command::Query,
            _ => panic!("Unrecognized command!"),
        };

        match command {
            Command::ArriveAtClinic(name, infection_level) => {
                cat_register.insert(name.clone(), (infection_level, id));
                infection_register.insert((infection_level, Reverse(id)), name.clone());
            },
            Command::UpdateInfectionLevel(name, increase_infection) => {
                let (infection_level, id) = cat_register[&name];
                cat_register.entry(name.clone())
                    .and_modify(|e| { *e = 
                        (min(100, infection_level + increase_infection), id)});
                infection_register.remove(&(infection_level, Reverse(id)));
                infection_register.insert(
                    (cat_register[&name].0, Reverse(cat_register[&name].1)), name);
            },
            Command::Treated(name) => {
                let (infection_level, id) = cat_register.remove(&name).unwrap();
                infection_register.remove(&(infection_level, Reverse(id)));
            },
            Command::Query => {
                match infection_register.iter().next_back() {
                    Some((_infection, name)) => { println!("{}", name); },
                    None => { println!("The clinic is empty"); },
                };
            },
        }
    }
}
