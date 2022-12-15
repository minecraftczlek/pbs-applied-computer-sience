function funkcja(dzien){
    switch(dzien){
        case "Poniedziałek":
            return 2500;
        case "Wtorek":
            return 3200;
        case "Środa":
            return 3500;
        case "Czwartek":
            return 4100;
        case "Piątek":
            return 4400;
        case "Sobota":
            return 4800;
        case "Niedziela":
            return 2137;
        default:
            return "zły dzień";
    }
}

console.log(funkcja("Niedziela"));