use std::f64;
use std::fmt;
use std::cmp;
use std::io::{self, BufRead};
use std::cmp::Ordering;


struct State {
    d: i32,
    c: i32,
    f: i32,
    u: i32,
}

impl State {
    fn t(&self) -> i32 { self.c + self.f + self.u }
    fn w(&self) -> i32 { cmp::max(0, (((self.t() + 1) as f64)/2.0).ceil() as i32 - self.c) }
    fn cost(&self) -> f64 {
        if self.w() <= self.u 
            { self.w() as f64 / self.d as f64 }
        else
            { f64::INFINITY }
    }
}

impl fmt::Debug for State {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "(d: {}, c: {}, f: {}, u: {}, t: {}, w: {}, cost: {})\n",
               self.d, self.c, self.f, self.u, self.t(), self.w(), self.cost())
    }
}

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let _s = lines.next().unwrap();

    let mut states = Vec::new();

    for line in lines {
        let line = line.unwrap();
        let mut data = line.split(" ").map(|x| x.parse::<i32>().unwrap());
        let d = data.next().unwrap();
        let c = data.next().unwrap();
        let f = data.next().unwrap();
        let u = data.next().unwrap();

        states.push(State { d:d, c:c, f:f, u:u });
    }

    let total_delegates:i32 = states.iter().map(|x| x.d).sum();
    let needed_delegates = (((total_delegates + 1) as f64)/2.0).ceil() as i32;

    states.sort_by(|a, b| a.cost().partial_cmp(&b.cost()).unwrap_or(Ordering::Equal));

    let winable_states = states.iter().filter(|&s| s.cost().is_finite());

    let mut delegates = 0;
    let mut voters = 0;
    for state in winable_states {
        delegates += state.d;
        voters += state.w();

        if delegates >= needed_delegates {
            break;
        }
    }
    if delegates >= needed_delegates {
        println!("{}", voters);
    }
    else {
        println!("impossible");
    }
}
