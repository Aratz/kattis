fn main() {
    use std::io::{self, BufRead};

    let stdin = io::stdin();

    let rs = stdin.lock().lines().next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    let (r, s) = (rs[0], rs[1]);
    println!("{}", 2*s - r);
}
