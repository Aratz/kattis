use std::io::{self, BufRead};
use std::collections::HashSet;

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let nt = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let (n, t) = (nt[0], nt[1]);

    let mut a = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<u32>().unwrap()).collect::<Vec<_>>();

    match t {
        1 => {
            println!("7");
        }
        2=> {
            if a[0] > a[1] {
                println!("Bigger");
            }
            else if a[0] == a[1] {
                println!("Equal");
            }
            else {
                println!("Smaller");
            }
        },
        3 => {
            a[..3].sort();
            println!("{}", a[1]);
        },
        4 => {
            println!("{}", a.iter().sum::<u32>());
        },
        5 => {
            println!("{}", a.iter().filter(|&&x| x % 2 == 0).sum::<u32>());
        },
        6 => {
            println!("{}", a.iter().map(|&x| ((x % 26) as u8 + 'a' as u8) as char).collect::<String>())
        },
        7 => {
            let mut i = 0;
            let mut visited: HashSet<usize> = HashSet::new();
            loop {
                if visited.contains(&i) {
                    println!("Cyclic");
                    break;
                }
                visited.insert(i);
                i = a[i] as usize;
                if i > a.len() {
                    println!("Out");
                    break;
                }
                else if i == n - 1 {
                    println!("Done");
                    break;
                }
            }
        },
        _ => panic!("Unrecognized action!"),
    }
}
