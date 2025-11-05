import React, { useState } from "react";
import Greeting from "./Greeting";

function App() {
  
  const [name, setName] = useState("Bharat");

  // Function to update state
  const changeName = () => {
    setName("Kolhe");
  };

  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      {/* Passing data using props */}
      <Greeting userName={name} />
      
      {/* Button to change state */}
      <button onClick={changeName}>Change Name</button>
    </div>
  );
}

export default App;
