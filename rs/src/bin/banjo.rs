use std::ops;

#[derive(Clone, Copy, Debug, PartialEq)]
struct Point { x: f32, y: f32, }

impl ops::Add<Point> for Point {
    type Output = Point;

    fn add(self, other: Point) -> Self::Output {
        Self::Output { x: self.x + other.x, y: self.y + other.y }
    }
}

impl ops::Sub<Point> for Point {
    type Output = Point;

    fn sub(self, other: Point) -> Self::Output {
        Self::Output { x: self.x - other.x, y: self.y - other.y }
    }
}

impl ops::Mul<f32> for Point {
    type Output = Point;

    fn mul(self, k: f32) -> Self::Output {
        Self::Output { x: k * self.x, y: k * self.y }
    }
}

impl ops::Mul<Point> for f32 {
    type Output = Point;

    fn mul(self, p: Point) -> Self::Output {
        Self::Output { x: self * p.x, y: self * p.y }
    }
}

fn dot(a: Point, b: Point) -> f32 {
    a.x * b.x + a.y * b.y
}

fn norm(p: Point) -> f32 {
    dot(p, p).sqrt()
}

/// Compute tangent point going through S and touching circle centered in c
/// with radius r. The points returned is the closest one to s0.
fn get_tangent_point(st: Point, mut s0: Point, ce: Point, r: f32) -> Point {
    let tol = 1e-5;

    let f = |p: Point| Point {
        x: dot(p - st, p - ce),
        y: norm(p - ce) * norm(p - ce) - r * r,
    };

    loop {
        let a = 2.*s0.x - (st.x + ce.x);
        let b = 2.*s0.y - (st.y + ce.y);

        let c = 2.*(s0.x - ce.x);
        let d = 2.*(s0.y - ce.y);

        let inv = 1./(a*d - b*c);

        let s1 = {
            let fs0 = f(s0);
            s0 - inv * Point {
                x: d*fs0.x - b*fs0.y,
                y: -c*fs0.x + a * fs0.y
            }
        };

        if norm(s1 - s0) < tol {
            return s1;
        }
        else {
            s0 = s1;
        }
    }
}

/// Compute angle between points aob
fn angle(o: Point, a: Point, b: Point) -> f32 {
    (dot(a - o, b - o)/(norm(a - o)*norm(b - o))).acos()
}

#[allow(non_snake_case)]
fn solve(s: Point, e: Point, c: Point, r: f32, t: f32) -> f32{
    //Compute projection of e over sc
    let p0 = (dot(e - s, c - s)/(norm(e - s).powi(2))) * (e - s) + Point { x: 0.101234, y: 0.11234 };
    let e0 = (1./norm(e - s)) * (e - s);
    let mut e1 = Point { x: e0.y, y: -e0.x };

    if dot(e1, p0 - c) < 0. {
        e1 = -1. * e1;
    }

    //If e not in lava, return |sc| or if can cross lava in one go
    if dot(p0 - c, p0 - c) > r * r || t > 2. * r {
        return norm(e - s);
    }

    let p0 = r * e1;

    //else compute tangent points
    let mut sc = get_tangent_point(s, p0, c, r);
    let mut ec = get_tangent_point(e, p0, c, r);

    //compute angle between tangent points
    let A = angle(c, sc, ec);

    //compute max angle from t
    let a_max = (t/(2.*r)).asin()*2.;


    let t_lava = if a_max < A {
        let n_full_chords = (A/a_max).floor();

        //compute remainder angle
        let a_rem = A - n_full_chords * a_max;
        let t_rem = 2.*r*((a_rem/2.).sin());

        n_full_chords * t + t_rem
    }
    else {
        // Do one crossing of len t, adjust entry and exit points
        let d = (r*r - t*t/4.).sqrt();

        sc = c + d*e1 - (t/2.)*e0;
        ec = c + d*e1 + (t/2.)*e0;

        t
    };

    //add up all distances
    norm(sc - s) + t_lava + norm(e - ec)
}


fn main() {
    use std::io::{self, BufRead};

    let stdin = io::stdin();

    let mut lines = stdin.lock().lines();

    while let Some(l) = lines.next() {
        let raw_input: Vec<f32> = l.unwrap().split(' ')
            .map(|v| v.parse().unwrap()).collect();

        let s = Point { x: raw_input[0], y: raw_input[1] };
        let e = Point { x: raw_input[2], y: raw_input[3] };
        let c = Point { x: raw_input[4], y: raw_input[5] };
        let (r, t) = (raw_input[6], raw_input[7]);

        if r == 0. { break; }

        println!("{:.2}", solve(s, e, c, r, t));
    }
}
