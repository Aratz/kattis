fn main() {
    use std::io::{self, BufRead};

    let stdin = io::stdin();

    let input = stdin.lock().lines().next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<usize>>();

    match input[..] {
        [X, Y, N] => {
            for i in 1..(N+1) {
                if i % X == 0{ print!("Fizz"); }
                if i % Y == 0{ print!("Buzz"); }
                if i % X != 0 && i % Y != 0 { print!("{}", i); }
                println!("");
            }
        },
        _ => panic!("Unrecognized input")
    }

}
