fn main() {
    use std::io::{self, BufRead};
    use std::collections::HashSet;

    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let T = lines.next().unwrap().unwrap().parse::<i32>().unwrap();

    for _ in 0..T {
        let nm = lines.next().unwrap().unwrap().split(" ")
            .map(|s| s.parse::<i32>().unwrap()).collect::<Vec<i32>>();
        let (n, m) = (nm[0], nm[1]);

        let mut rivers = Vec::new();
        for _ in 0..n {
            let abc = lines.next().unwrap().unwrap().split(" ")
            .map(|s| s.parse::<i32>().unwrap()).collect::<Vec<i32>>();
            let (a, b, c) = (abc[0], abc[1], abc[2]);

            rivers.push(move |x:i32, y:i32| (a*x + b*y + c).signum());
        }

        let mut zones = HashSet::new();
        for _ in 0..m {
            let xy = lines.next().unwrap().unwrap().split(" ")
                .map(|s| s.parse::<i32>().unwrap()).collect::<Vec<i32>>();
            let (x, y) = (xy[0], xy[1]);
            let zipcode = rivers.iter().map(|f| f(x, y)).collect::<Vec<i32>>();
            zones.insert(zipcode);
        }
        if zones.len() as i32 == 1 + n*(n + 1)/2 {
            println!("PROTECTED");
        }
        else {
            println!("VULNERABLE");
        }
    }

}
