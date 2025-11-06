import express from "express";
const app = express();
const port = 3000;

const students = [
  {
    id: "S001",
    firstName: "Alice",
    lastName: "Smith",
    age: 16,
    grade: 10,
    major: "Science",
    courses: ["Physics", "Chemistry", "Biology", "Math"],
    contact: {
      email: "alice.smith@example.com",
      phone: "123-456-7890",
    },
  },
  {
    id: "S002",
    firstName: "Bob",
    lastName: "Johnson",
    age: 17,
    grade: 11,
    major: "Arts",
    courses: ["Literature", "History", "Art", "Music"],
    contact: {
      email: "bob.johnson@example.com",
      phone: "987-654-3210",
    },
  },
  {
    id: "S003",
    firstName: "Charlie",
    lastName: "Brown",
    age: 16,
    grade: 10,
    major: "Mathematics",
    courses: ["Algebra", "Geometry", "Calculus", "Statistics"],
    contact: {
      email: "charlie.brown@example.com",
      phone: "555-111-2222",
    },
  },
  {
    id: "S004",
    firstName: "Diana",
    lastName: "Prince",
    age: 18,
    grade: 12,
    major: "Computer Science",
    courses: ["Programming", "Data Structures", "Web Development"],
    contact: {
      email: "diana.prince@example.com",
      phone: "444-333-2222",
    },
  },
  {
    id: "S005",
    firstName: "Eve",
    lastName: "Adams",
    age: 17,
    grade: 11,
    major: "Business",
    courses: ["Economics", "Accounting", "Marketing"],
    contact: {
      email: "eve.adams@example.com",
      phone: "111-222-3333",
    },
  },
];

app.get("/", (req, res) => {
  res.send("Hello I am Atharva!");
});

app.get("/students", (req, res) => {
  res.status(200).json(students);
});

app.get("/student", (req, res) => {
  const id = req.query.id;
  const student = students.find((student) => student.id === id);
  if (student) {
    res.status(200).json(student);
  } else {
    res.status(404).json({ error: "Student not found" });
  }
});

app.post("/student", (req, res) => {
    const newStudent = req.body;
    students.push(newStudent);
    console.log(students);
    res.status(201).json(students);

});

app.listen(port, () => {
  console.log(`Example app listening on port http://localhost:${port}`);
});
