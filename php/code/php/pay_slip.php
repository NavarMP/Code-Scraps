<html>
  <head>
    <title>Pay Slip</title>
  </head>
  <body>
    <form method="post">
      Name: <input type="text" name="txtName"><br>
      salary: <input type="text" name="txtBasicSal"><br>
      designation: <input type="text" name="selDesig"><br>
      <input type="submit" value="submit">
    </form>
    <?php
    $conveyance_allowance = array('Manager'=> 1000, 'Supervisor'=> 750, 'Clerk'=> 500, 'Peon'=> 250);
    $extra_allowance = array('Manager'=> 500, 'Supervisor'=> 200, 'Clerk'=> 100, 'Peon'=> 0);

    $name = isset($_POST['txtName']) ? $_POST['txtName'] : '';
    $basicSal = isset($_POST['txtBasicSal']) ? $_POST['txtBasicSal'] : '';
    $desig = isset($_POST['selDesig']) ? $_POST['selDesig'] : '';

    if($name == '' || $basicSal == '' || $desig == '') {
      echo "ERROR: All fields are mandatory.";
      exit;
    }

    $hra = $basicSal * 0.25;
    $gross = $basicSal + $hra + $conveyance_allowance[$desig] + $extra_allowance[$desig];

    if($gross < 2500) {
      $it = 0;
    } else if($gross >= 2500 && $gross <= 4000) {
      $it = 0.03;
    } else if($gross <= 5000) {
      $it = 0.05;
    } else {
      $it = 0.08;
    }

    $net = $gross - ($it*$gross);

    echo "<h1>Pay Slip of $name</h1>";
    echo "<p><label>Name: </label> $name</p>";
    echo "<p><label>Designation: </label> $desig</p>";
    echo "<hr/><p><label>Basic Salary: </label> $basicSal</p>";
    echo "<p><label>Conveyance Allowance: </label>".$conveyance_allowance[$desig]."</p>";
    echo "<p><label>Extra Allowance: </label>".$extra_allowance[$desig]."</p>";
    echo "<p><label>HRA: </label> $hra</p>";
    echo "<p><label>Gross Salary: </label> $gross</p>";
    echo "<p><label>Income Tax: </label> ".($it*$gross).'  ('.($it*100).'%) </p>";
    echo "<p style='font-weight:bold'><label>Net Salary: </label> $net</p>";
    ?>
  </body>
</html>