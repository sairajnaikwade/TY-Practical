// This program takes user input and displays a message
// Get elements from the page
var input = document.getElementById("username");
var button = document.getElementById("btn");
var result = document.getElementById("result");
// When button is clicked
button.addEventListener("click", function () {
    var name = input.value.trim();
    if (name) {
        result.textContent = "Hello, ".concat(name, "! Welcome to the TypeScript web app \uD83D\uDE0A");
    }
    else {
        result.textContent = "Please enter your name!";
    }
});
