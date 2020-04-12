use std::io::{self,BufRead};
use std::collections::HashMap;

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let n = lines.next().unwrap().unwrap().parse::<u32>().unwrap();

    let mut combinations:HashMap<(u32, u32, u32, u32, u32), u32> = HashMap::new();

    for _ in 0..n {
        let mut courses = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<u32>().unwrap()).collect::<Vec<_>>();
        courses.sort();
        let codes = (courses[0], courses[1], courses[2], courses[3], courses[4]);
        combinations.entry(codes).and_modify(|e| { *e += 1 }).or_insert(1);
    }

    let most_popular = combinations.iter().max_by_key(|kv| kv.1).unwrap();
    let n_students:u32 = combinations.values().filter(|&v| v == most_popular.1).sum();

    println!("{}", n_students);
}
