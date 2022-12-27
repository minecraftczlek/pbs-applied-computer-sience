const myButton = document.querySelector("#myButton");
const laboratorium = document.querySelector("#laboratorium");
const prowadzacy = document.querySelector("#prowadzacy");
const temat = document.querySelector("#temat");
const rok = document.querySelector("#rok");

myButton.addEventListener("click", e => {
    const request = new XMLHttpRequest();
    request.open("get", "http://localhost:3000/test", true);
    // ja użyłem json server, a nie lokalnego pliku
    request.send();

    request.addEventListener("load", () => {
        const result = JSON.parse(request.response);
        laboratorium.innerHTML = result.laboratorium;
        prowadzacy.innerHTML = result.prowadzacy;
        temat.innerHTML = result.temat;
        rok.innerHTML = result.rok;
    });
})