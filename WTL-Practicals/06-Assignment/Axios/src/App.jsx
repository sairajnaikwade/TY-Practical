import React, { useState } from "react";
import axios from "axios";


function App() {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  function fetchData() {
    setLoading(true);
    axios.get("/data.json")   //https://jsonplaceholder.typicode.com/users
      .then(res => {
        console.dir(res.data);
        setData(res.data);
        setLoading(false);
      })
      .catch(() => {
        setError("Failed to load data");
        setLoading(false);
      });
  }

  return (
    <div>
      <h2>User List</h2>
      <button onClick={fetchData}>Fetch Data</button>

      {loading && <p>Loading...</p>}
      {error && <p>{error}</p>}

      <ul>
        {data.map((user) => (
          <li >
            {user.name} - {user.age} - {user.country}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default App;
