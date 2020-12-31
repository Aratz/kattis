fn main() {
    use std::io::{self, BufRead};

    let stdin = io::stdin();
    println!("{}", stdin.lock().lines().nth(1).unwrap().unwrap().split(" ")
        .map(|x| x.parse::<i32>().unwrap()).filter(|&x| x < 0).count());

}
