const input = document.getElementById("username") as HTMLInputElement;
const button = document.getElementById("btn") as HTMLButtonElement;
const result = document.getElementById("result") as HTMLHeadingElement;

// When button is clicked
button.addEventListener("click", () => {
  const name = input.value.trim();
  if (name) {
    result.textContent = `Hello, ${name}! Welcome to the TypeScript web app 😊`;
  } else {
    result.textContent = "Please enter your name!";
  }
});
