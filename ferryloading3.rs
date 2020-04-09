use std::io::{self, BufRead};
use std::collections::VecDeque;

fn main() {
    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    let c = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

    for tc in 0..c {
        let data = lines.next().unwrap().unwrap().split(" ")
            .map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
        let (n, t, m) = (data[0], data[1], data[2]);

        let mut banks = vec![VecDeque::new(), VecDeque::new()];
        let mut central_time = 0;
        let mut ferry_side = 0;

        let mut arrivals = vec![0; m];

        for car_id in 0..m {
            let car = lines.next().unwrap().unwrap()
                .split(" ").map(|s| String::from(s)).collect::<Vec<_>>();
            let (arrival, side) = (
                car[0].parse::<usize>().unwrap(),
                if car[1] == "left" { 0 } else { 1} );

            banks[side].push_back((car_id, arrival));
        }

        while !banks[0].is_empty() || !banks[1].is_empty() {
            let side_car = banks[ferry_side].front();
            let other_side_car = banks[1 - ferry_side].front();

            //Experimental rust feature :(
            //if let Some((car, arrival)) = banks[ferry_side].front()
            //    && arrival <= central_time {
            if side_car.is_some()
                && side_car.unwrap().1 <= central_time {
                // Load
                eprintln!("Loading");
                let mut free_spots = n;
                while free_spots > 0
                    && banks[ferry_side].front().is_some()
                    && banks[ferry_side].front().unwrap().1 <= central_time {
                    //Experimental rust feature :(
                    //&& let Some((car, arrival)) = banks[ferry_side].front()
                    //&& arrival <= central_time {
                        let (car, _) = banks[ferry_side].pop_front().unwrap();
                        free_spots -= 1;
                        arrivals[car] = central_time + t;
                }

                // Cross
                central_time += t;
                ferry_side = 1 - ferry_side;
            }
            //Experimental rust feature :(
            //else if let Some((car, arrival)) = banks[1 - ferry_side].front()
            //    && arrival <= central_time {
            else if other_side_car.is_some()
                && other_side_car.unwrap().1 <= central_time {
                eprintln!("Crossing empty");
                // Cross
                central_time += t;
                ferry_side = 1 - ferry_side;
            }
            else {
                eprint!("Waiting {} ", central_time);
                // Wait until next car arrives on either side
                central_time = banks.iter().map(|bank| bank.front())
                    .filter_map(|x| x).map(|x| x.1).min().unwrap();
                eprintln!("{}", central_time);
            }
        }

        for arrival in arrivals.iter() {
            println!("{}", arrival);
        }

        if tc < c - 1 {
            println!("");
        }
    }
}
