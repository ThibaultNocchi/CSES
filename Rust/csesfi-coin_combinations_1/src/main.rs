// https://cses.fi/problemset/task/1635/
// Not passing everything

use std::io;

fn main() -> () {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("error");
    let first_line_split: Vec<&str> = buf.split_whitespace().collect();

    let sum: u32 = first_line_split[1].trim().parse().expect("not number");

    let mut buf = String::new();
    io::stdin().read_line(&mut buf).expect("error");
    let coins: Vec<&str> = buf.split_whitespace().collect();
    let mut coins: Vec<u32> = coins
        .iter()
        .map(|val| val.trim().parse().expect("not number"))
        .collect::<Vec<u32>>();
    coins.sort();

    let mut current_results: Vec<Option<Vec<String>>> = vec![None; sum as usize];

    combination(&coins, sum, &mut current_results);
    println!(
        "{}",
        current_results[(sum - 1) as usize]
            .clone()
            .expect("msg")
            .len()
    );
}

fn combination(coins: &[u32], sum: u32, current_results: &mut Vec<Option<Vec<String>>>) {
    let mut res: Vec<String> = Vec::new();

    if current_results[(sum - 1) as usize].is_some() {
        return;
    }

    for i in (0..coins.len()).rev() {
        // if sum < current coin, we can't make a combination with it
        if sum < coins[i] {
            continue;
        }

        if sum == coins[i] {
            res.push(coins[i].to_string());
            continue;
        }

        combination(coins, sum - coins[i], current_results);
        let mut partial_rest = current_results[(sum - coins[i] - 1) as usize]
            .clone()
            .expect("msg");
        for part in partial_rest.iter_mut() {
            if part != "" {
                part.push(',');
            }
            res.push(format!("{}{}", part, coins[i]));
        }
    }

    current_results[(sum - 1) as usize] = Some(res);
}
