fn main() {
    use std::io::{self, BufRead};
    use std::collections::HashSet;

    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let T = lines.next().unwrap().unwrap().parse::<i64>().unwrap();

    for _ in 0..T {
        let nm = lines.next().unwrap().unwrap().split(" ")
            .map(|s| s.parse::<i64>().unwrap()).collect::<Vec<i64>>();
        let (n, m) = (nm[0], nm[1]);

        let mut rivers = Vec::new();
        let mut coefs = Vec::new();
        for _ in 0..n {
            let abc = lines.next().unwrap().unwrap().split(" ")
            .map(|s| s.parse::<i64>().unwrap()).collect::<Vec<i64>>();
            let (a, b, c) = (abc[0], abc[1], abc[2]);

            coefs.push(vec![a, b, c]);

            rivers.push(move |x:i64, y:i64| (a*x + b*y + c).signum());
        }

        let mut zones = HashSet::new();
        for _ in 0..m {
            let xy = lines.next().unwrap().unwrap().split(" ")
                .map(|s| s.parse::<i64>().unwrap()).collect::<Vec<i64>>();
            let (x, y) = (xy[0], xy[1]);
            let zipcode = rivers.iter().map(|f| f(x, y)).collect::<Vec<i64>>();
            zones.insert(zipcode);
        }

        let mut n_zones = 1;
        for i in 0..n as usize {
            let (ai, bi) = (coefs[i][0], coefs[i][1]);
            n_zones += 1 + coefs[..i].iter().filter(|v| ai*v[1] != v[0]*bi).count() as i64;
        }

        if zones.len() as i64 == n_zones {
            println!("PROTECTED");
        }
        else {
            println!("VULNERABLE");
        }
    }

}
