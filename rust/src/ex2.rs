

fn modification(var: &mut String){

    var.push_str(" le monde");
    return;

}

pub fn ex2(){
    
    let mut str = "Bonjour".to_string();
    modification(&mut str);
    println!("{}",str);
    return;

}
