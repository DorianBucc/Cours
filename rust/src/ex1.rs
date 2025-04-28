pub fn ex1(){
    let tab: [[i32; 3]; 3] = [[0,0,0],[0,1,0],[0,0,0]];//[[0; 4]; 3]

    for i in 0..3 {
        println!("-------------");
        for y in 0..3 {
            print!("| {} ",tab[i][y]);
        }
        println!("|");
    }
    println!("-------------");
    return ;
}
