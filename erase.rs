use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();

    let n = stdin.lock().lines().next().unwrap().unwrap().parse::<u32>().unwrap();
    let file1 = stdin.lock().lines().next().unwrap().unwrap();
    let file2 = stdin.lock().lines().next().unwrap().unwrap();

    let res: Vec<bool> = file1.chars().zip(file2.chars()).map(|(c1, c2)| c1 == c2).collect();

    if n % 2 == 0 && res.iter().all(|&x| x) || n % 2 == 1 && !res.iter().any(|&x| x) {
        println!("Deletion succeeded");
    }
    else {
        println!("Deletion failed");
    }

}
