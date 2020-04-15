use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let nt = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let (n, t) = (nt[0], nt[1]);

    let mut a = lines.next().unwrap().unwrap().split(" ")
        .map(|x| x.parse::<u32>().unwrap()).collect::<Vec<_>>();

    a.sort_unstable();

    let a = a;

    match t {
        1 => {
            let mut i = 0;
            let mut j = n - 1;
            while i < j {
                if a[i] + a[j] < 7777 {
                    i += 1;
                }
                else if a[i] + a[j] > 7777 {
                    j -= 1;
                }
                else {
                    println!("Yes");
                    return;
                }
            }
            println!("No");
        }
        2=> {
            match a.iter().zip(a.iter().skip(1)).filter(|(x, y)| x == y).next() {
                Some(_) => println!("Contains duplicate"),
                None => println!("Unique"),
            }
        },
        3 => {
            if a.iter().filter(|&&x| x == a[n/2]).count() > n/2 {
                println!("{}", a[n/2]);
            }
            else {
                println!("{}", -1);
            }
        },
        4 => {
            if n % 2 == 1 {
                println!("{}", a[n/2]);
            }
            else {
                println!("{} {}", a[n/2 - 1], a[n/2]);
            }
        },
        5 => {
            let mut first = true;
            for x in a.iter().filter(|&&x| 100 <= x && x <= 999) {
                if first {
                    first = false;
                }
                else {
                    print!(" ");
                }

                print!("{}", x);
            }
            println!();
        },
        _ => panic!("Unrecognized action!"),
    }
}
