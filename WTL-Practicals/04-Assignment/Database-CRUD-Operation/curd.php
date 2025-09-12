<?php
$conn = new mysqli("localhost", "root", "", "info");

if ($conn->connect_error) {
    die("Error in connection: " . $conn->connect_error);
}

// === Insert ===
if (isset($_POST["sname"]) && isset($_POST["smarks"])) {
    $name = $_POST["sname"];
    $marks = $_POST["smarks"];

    $stat = $conn->prepare("INSERT INTO userinfo (Name, Mark) VALUES (?, ?)");
    $stat->bind_param("si", $name, $marks);

    if ($stat->execute()) {
        echo "Data inserted successfully";
    } else {
        echo "Insert failed";
    }
}

// === Delete ===
if (isset($_POST["delete_name"])) {
    $name = $_POST["delete_name"];

    $stat = $conn->prepare("DELETE FROM userinfo WHERE Name=?");
    $stat->bind_param("s", $name);

    if ($stat->execute()) {
        echo "Data deleted successfully";
    } else {
        echo "Delete failed";
    }
}

// === Update Name ===
if (isset($_POST["old_name"]) && isset($_POST["new_name"])) {
    $old = $_POST["old_name"];
    $new = $_POST["new_name"];

    $stat = $conn->prepare("UPDATE userinfo SET Name=? WHERE Name=?");
    $stat->bind_param("ss", $new, $old);

    if ($stat->execute()) {
        echo "Name updated successfully";
    } else {
        echo "Update failed";
    }
}

// === Update Marks (Optional) ===
if (isset($_POST["update_name"]) && isset($_POST["update_marks"])) {
    $name = $_POST["update_name"];
    $marks = $_POST["update_marks"];

    $stat = $conn->prepare("UPDATE userinfo SET Mark=? WHERE Name=?");
    $stat->bind_param("is", $marks, $name);

    if ($stat->execute()) {
        echo "Marks updated successfully";
    } else {
        echo "Update failed";
    }
}

// === Display All ===
if (isset($_GET["fetch_all"])) {
    $result = $conn->query("SELECT Name, Mark FROM userinfo");
    $rows = [];

    while ($row = $result->fetch_assoc()) {
        $rows[] = $row;
    }

    echo json_encode($rows);
}
?>
