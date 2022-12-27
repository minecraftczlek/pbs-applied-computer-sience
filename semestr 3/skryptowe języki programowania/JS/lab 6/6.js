const square = document.querySelector("#square");

square.style["transition-duration"] = "10s";
square.style["transition-timing-function"] = "linear";

square.addEventListener("click", e =>square.style.left = "100px");