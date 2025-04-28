function ex1() : void
{
    let tab: number[][] = [
        [0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]
    ];
    for (let i = 0; i < 3; i++)
    {
        console.log("-------------");
        let variable: String = "";
        for (let y = 0; y < 3; y++)
        {
            variable += "| " + tab[i][y] + " ";
        }
        console.log(variable+"|");
        
    }
    console.log("-------------");
    return;
}

ex1();