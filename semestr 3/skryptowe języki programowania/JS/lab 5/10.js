let gra = (gracz1, gracz2) => {
    if(gracz1==gracz2)return "remis";
    else if(gracz1=="papier"||gracz2=="kamień")return "gracz1";
    else if(gracz1=="papier"||gracz2=="nożyce")return "gracz2";
    else if(gracz1=="kamień"||gracz2=="papier")return "gracz2";
    else if(gracz1=="kamień"||gracz2=="nożyce")return "gracz1";
    else if(gracz1=="nożyce"||gracz2=="papier")return "gracz1";
    else if(gracz1=="nożyce"||gracz2=="kamień")return "gracz2";
}

console.log(gra("kamień", "kamień"));
console.log(gra("papier", "kamień"));
console.log(gra("nożyce", "papier"));