<?php
header("Content-Type: application/json");

// Get raw JSON input
$rawData = file_get_contents("php://input");
$data = json_decode($rawData, true); // decode as array

// Safely extract variables
$name = isset($data['name1']) ? $data['name1'] : null;
$mark = isset($data['mark1']) ? (int)$data['mark1'] : null;

// Connect to DB
$conn = new mysqli('localhost', 'root', '', 'bt1');

// Check connection
if ($conn->connect_error) {
    die(json_encode(["error" => "Database connection failed: " . $conn->connect_error]));
}

if ($name && $mark !== null) {
    $stat = $conn->prepare("INSERT INTO student(name, mark) VALUES(?, ?)");
    $stat->bind_param("si", $name, $mark);

    if ($stat->execute()) {
        echo json_encode(["success" => true, "message" => "Data Inserted Successfully"]);
    } else {
        echo json_encode(["success" => false, "message" => "Data Insertion Failed"]);
    }

    $stat->close();
} else {
    echo json_encode(["success" => false, "message" => "Invalid input data"]);
}

$conn->close();
?>
