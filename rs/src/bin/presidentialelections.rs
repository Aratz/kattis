use std::f64;
use std::fmt;
use std::cmp;
use std::io::{self, BufRead};
use std::cmp::Ordering;
use std::collections::HashMap;


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

fn update_map(h:&mut HashMap<(usize, i32), i32>, n:usize, size:i32, states:&Vec<&State>){
    if h.contains_key(&(n, size)) { () }
    else if n == 0 {
        if states[n].d <= size {
            h.insert((n, size), states[n].w());
        }
        else {
            h.insert((n, size), 0);
        }
    }
    else if size == 0{
        h.insert((n, size), 0);
    }
    else {
        update_map(h, n - 1, size, states) ;
        if states[n].d <= size { update_map(h, n -1 , size - states[n].d, states)};

        let best_fit = cmp::max(
                *(h.get(&(n - 1, size)).unwrap()),
                if states[n].d <= size
                    { h.get(&(n - 1, size - states[n].d)).unwrap() + states[n].w() }
                else
                    { 0 }
                );

        h.insert((n, size), best_fit);
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

    let unwinable_delegates:i32 = states.iter().filter(|&s| s.cost().is_infinite())
        .map(|x| x.d).sum();

    let knp_size = total_delegates - needed_delegates - unwinable_delegates;
    if knp_size < 0 {
        println!("impossible");
    }
    else {
        let mut h = HashMap::new();
        let loosable_states = states.iter().filter(|&s| s.cost().is_finite())
            .collect::<Vec<&State>>();

        update_map(&mut h, loosable_states.len() - 1, knp_size, &loosable_states);

        let total_winnable_voters:i32 = loosable_states.iter().map(|&v| v.w()).sum();
        println!("{}",
                 total_winnable_voters - h.get(&(loosable_states.len() - 1, knp_size)).unwrap());
    }

}
