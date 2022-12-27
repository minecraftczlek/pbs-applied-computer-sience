const input = document.querySelector("#input");
const output = document.querySelector("#output");
const colors = ["#002147", "#8b2500", "#3c1414", "#36454f", "#d874e1", "#ffd700", "#fffeca", "#bb913b", "#68228b"];
let length = 0;

input.addEventListener("keypress", e => {
    if(e.key == "Enter"){
        output.innerHTML = "";
        for(i in input.value)output.innerHTML += `<span class="letter${i}">${input.value[i]}</span>`;
        length = input.value.length;
        input.value = "";
    }
});

setInterval(() => {
    for(i=0; i<length; i++)document.querySelector(`.letter${i}`).style.color = colors[Math.floor(Math.random()*colors.length)];
}, 1000);