//--------------------------------------------------------------

// les references en typescript ça n'existe pas

//--------------------------------------------------------------

function modification(variable:string): string{
    return variable + " le monde";
}

function ex2() : void
{
    let str = "Bonjour";
    str = modification(str);
    console.log(str);
    return;
}

ex2();