use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();
    loop {
        let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

        if n == 0 { break; }

        //Doesn't work, `take` will drop the lines variable :(
        //let mut cars = lines.take(n).enumerate().map(|(i, w)| (w.unwrap().parse::<f32>().unwrap(), i))
        //    .collect::<Vec<_>>();

        let mut cars = Vec::<_>::new();
        for i in 1..(n+1) {
            cars.push((lines.next().unwrap().unwrap().parse::<f32>().unwrap(), i));
        }
        cars.sort_by(|a, b| b.partial_cmp(a).unwrap());
        let cars = cars;

        let mut port_lane = Vec::<usize>::new();
        let mut port_weight = 0.0;

        let mut starboard_lane = Vec::<usize>::new();
        let mut starboard_weight = 0.0;

        for &(w, i) in cars.iter() {
            if port_weight <= starboard_weight {
                port_lane.push(i);
                port_weight += w;
            }
            else {
                starboard_lane.push(i);
                starboard_weight += w;
            }
        }

        let mut lane = port_lane.iter();
        print!("{}", lane.next().unwrap());
        for car in lane {
            print!(" {}", car);
        }
        println!();

        //Check into stderr
        if (1.0 - port_weight / starboard_weight).abs() < 0.02 {
            eprintln!("OK");
        }
        else {
            eprintln!("KO");
        }

    }
}
