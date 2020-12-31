//https://open.kattis.com/problems/snobollskrig2

fn count(victim: &[u32], aggressor: &[u32]) -> usize {
    let mut i_vic = 0;
    let mut i_agg = 0;

    let mut count = 0;

    while i_vic < victim.len() {
        while i_agg < aggressor.len() && aggressor[i_agg] <= victim[i_vic] {
            i_agg += 1;
        }
        if i_agg < aggressor.len() {
            count += 1;
            i_vic += 1;
            i_agg += 1;
        }
        else {
            break;
        }
    }

    count
}

fn solve(se: &[u32], fi: &[u32]) -> usize {
    count(se, fi) + count(fi, se)
}

fn main() {
    use std::io::{self, BufRead};

    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let _mn = lines.next()
        //.unwrap().unwrap().split(' ')
        //.map(|v| v.parse().unwrap())
        //.collect()
        ;

    let se: Vec<u32> = lines.next().unwrap().unwrap().split(' ')
        .map(|v| v.parse().unwrap())
        .collect();

    let fi: Vec<u32> = lines.next().unwrap().unwrap().split(' ')
        .map(|v| v.parse().unwrap())
        .collect();

    println!("{}", solve(&se, &fi));
}

#[cfg(test)]
mod test_snobollskrig2 {
    use super::*;

    #[test]
    fn test_solve_1() {
        let se = vec![1, 3, 4, 5];
        let fi = vec![2, 3];
        assert_eq!(solve(&se, &fi), 3);
    }

    #[test]
    fn test_solve_2() {
        let se = vec![1, 1, 1];
        let fi = vec![1, 1, 1];
        assert_eq!(solve(&se, &fi), 0);
    }

    #[test]
    fn test_solve_3() {
        let se = vec![1, 2, 3];
        let fi = vec![1, 2, 3];
        assert_eq!(solve(&se, &fi), 4);
    }

    #[test]
    fn test_solve_4() {
        let se = vec![1, 2, 3];
        let fi = vec![10];
        assert_eq!(solve(&se, &fi), 1);
    }
}
