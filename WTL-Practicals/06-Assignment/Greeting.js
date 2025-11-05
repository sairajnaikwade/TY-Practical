import React from "react";

// Receiving data using props
function Greeting(props) {
  return (
    <h1>Hello, {props.userName}! 👋</h1>
  );
}

export default Greeting;
