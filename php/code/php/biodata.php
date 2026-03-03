<!DOCTYPE html>
<html>
  <head>
    <title></title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  </head>
  <body>
    <form method='POST'>
      <h2>Please input your name:</h2>
      <input type="text" name="name">
      <h2>Please input your address:</h2>
      <input type="text" name="add">
      <h2>Please input your phone:</h2>
      <input type="text" name="ph">
      <input type="submit" value="Submit Name">
    </form>
    <?php
    $name = isset($_POST['name']) ? $_POST['name'] : '';
    echo "<h3> Hello $name </h3>";
    $add = isset($_POST['add']) ? $_POST['add'] : '';
    echo "<h3> $add </h3>";
    $ph = isset($_POST['ph']) ? $_POST['ph'] : '';
    echo "<h3> $ph </h3>";
    ?>
  </body>
</html>