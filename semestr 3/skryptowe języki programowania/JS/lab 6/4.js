const userTodo = document.querySelector("#user-todo");
const clear = document.querySelector("#clear");
const list = document.querySelector("#list");

const addElement = el => list.innerHTML += `<li>${el}</li>`; //dodanie elementu

userTodo.addEventListener("keypress", e => { //ustawianie zdażenia
    if(e.key == "Enter"){ //sprawdzanie cz naciśnięto "enter"
        e.preventDefault(); //wyłączenie domyślnej akcji
        addElement(userTodo.value); //wywołanie funkcji
        userTodo.value = ""; //czyszczenie pola
    }
})

clear.addEventListener("click", e => list.innerHTML = ""); //zdażenie czyszczące