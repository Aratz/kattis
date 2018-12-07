fn main() {
    use std::io::{self, BufRead};

    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let _ = lines.next();
    println!("{:.3}", lines.map(|s| s.unwrap().split(" ").map(|e| e.parse::<f64>().unwrap()).collect::<Vec<f64>>())
        .map(|v| v[0]*v[1]).sum::<f64>());
}
