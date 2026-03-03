# Web Programs and Sample Outputs

This document lists the 20 programs extracted from the JavaScript and PHP PDFs. Each entry now includes the **source code** and a **realistic sample output** that would appear when the program is run. Filenames are shown after each title.

## 1. Perfect Number  
*(file: `js/program1_perfect.html`)*

### Source Code
```html
<html>
  <body>
    <h1>Perfect Number</h1>
    Enter a number:
    <input type="text" id="num" />
    <input type="button" value="Find" onClick="findPerfect()" />
    <script>
      function findPerfect() {
        var n = document.getElementById('num').value;
        var sum = 0;
        for (var i = 0; i < n; i++) {
          if (n % i == 0) {
            sum = sum + i;
          }
        }
        if (sum == n)
          alert("The number is perfect ");
        else if (sum > n)
          alert("The number is abundant");
        else
          alert("The number is deficient");
      }
    </script>
  </body>
</html>
```
### Sample Output
Alerts: 'The number is perfect ' when input 6; 'The number is abundant' when input 12; 'The number is deficient' when input 5.

## 2. Triangle Check  
*(file: `js/program2_triangle.html`)*

### Source Code
```html
<html>
  <body>
    <script>
      var x, y, z;
      x = parseInt(window.prompt("Enter side 1"));
      y = parseInt(window.prompt("Enter side 2"));
      z = parseInt(window.prompt("Enter side 3"));
      alert("sides =" + x + "  " + y + "   " + z);
      if (x + y > z && x + z > y && z + y > x) {
        if (x == y && y == z)
          document.write("Equilateral Triangle");
        else if (x == y || y == z || z == x)
          document.write("Isosceles Triangle");
        else
          document.write("Scalene Triangle");
      } else {
        window.alert("triangle canot make by this sides");
      }
    </script>
  </body>
</html>
```
### Sample Output
If inputs 3,4,5 page shows 'Scalene Triangle'; invalid sides triggers alert 'triangle canot make by this sides'.

## 3. Input Tutorial  
*(file: `js/program3_input_tutorial.html`)*

### Source Code
```html
<html>
  <head>
    <title>Input tutorial</title>
    <script language="javascript">
      function addNumbers() {
        var val1 = parseInt(document.getElementById("value1").value);
        var val2 = parseInt(document.getElementById("value2").value);
        var ansD = document.getElementById("answer");
        ansD.value = val1 + val2;
      }
      function subNumbers() {
        var val1 = parseInt(document.getElementById("value1").value);
        var val2 = parseInt(document.getElementById("value2").value);
        var ansD = document.getElementById("answer");
        ansD.value = val1 - val2;
      }
      function mulNumbers() {
        var val1 = parseInt(document.getElementById("value1").value);
        var val2 = parseInt(document.getElementById("value2").value);
        var ansD = document.getElementById("answer");
        ansD.value = val1 * val2;
      }
      function divNumbers() {
        var val1 = parseInt(document.getElementById("value1").value);
        var val2 = parseInt(document.getElementById("value2").value);
        var ansD = document.getElementById("answer");
        ansD.value = val1 / val2;
      }
    </script>
  </head>
  <body>
    value1 = <input type="text" id="value1" name="value1" value="1"/>
    value2 = <input type="text" id="value2" name="value2" value="2"/>
    <input type="button" name="Sumbit" value="Add" onclick="javascript:addNumbers()"/>
    <input type="button" name="Sumbit" value="Sub" onclick="javascript:subNumbers()"/>
    <input type="button" name="Sumbit" value="Mul" onclick="javascript:mulNumbers()"/>
    <input type="button" name="Sumbit" value="Div" onclick="javascript:divNumbers()"/>
    Answer = <input type="text" id="answer" name="answer" value=""/>
  </body>
</html>
```
### Sample Output
Entering 4 and 5 then clicking 'Add' sets Answer=9; clicking 'Mul' sets Answer=20, etc.

## 4. Changing Background Color  
*(file: `js/program4_change_bg.html`)*

### Source Code
```html
<!DOCTYPE html>
<html>
  <body>
    <center>
      <script>
        function myArray(n) {
          var backcolor=["#00f00","#ff0000","#0000ff","#cce"];
          document.bgColor=backcolor[n];
        }
      </script>
      <a href="#" onmouseover="myArray(1)">Red</a>
      <a href="#" onmouseover="myArray(2)">Blue</a>
      <a href="#" onmouseover="myArray(4)">Green</a>
      <a href="#" onmouseover="myArray(3)">Ash</a>
      <h1>Changing background color</h1>
    </center>
  </body>
</html>
```
### Sample Output
Moving mouse over 'Red' link changes background to red, etc.

## 5. Clock with Timing Event  
*(file: `js/program5_clock.html`)*

### Source Code
```html
<html>
  <head>
  </head>
  <body>
    <div id="clock" onload="currentTime()"></div>
    <script>
      function currentTime() {
        let date = new Date();
        let hh = date.getHours();
        let mm = date.getMinutes();
        let ss = date.getSeconds();
        let session = "AM";
        if (hh > 12) {
          session = "PM";
        }
        hh = (hh < 10) ? "0" + hh : hh;
        mm = (mm < 10) ? "0" + mm : mm;
        ss = (ss < 10) ? "0" + ss : ss;
        let time = hh + ":" + mm + ":" + ss + " " + session;
        document.getElementById("clock").innerText = time;
        var t = setTimeout(function(){ currentTime() }, 1000);
      }
      currentTime();
    </script>
  </body>
</html>
```
### Sample Output
Page displays current time, e.g. '14:23:05 PM', updating every second.

## 6. Validate Email  
*(file: `js/program6_validate_email.html`)*

### Source Code
```html
<html>
  <body>
    <script>
      function validateemail() {
        var x = document.myform.email.value;
        var atposition = x.indexOf("@");
        var dotposition = x.lastIndexOf(".");
        if (atposition < 1 || dotposition < atposition + 2 || dotposition + 2 >= x.length) {
          alert("Please enter a valid e-mail address \n atpostion:" + atposition + "\n dotposition:" + dotposition);
          return false;
        }
      }
    </script>
    <form name="myform" method="post" action="http://www.javatpoint.com/javascriptpages/valid.jsp" onsubmit="return validateemail();">
      Email: <input type="text" name="email"><br/>
      <input type="submit" value="register">
    </form>
  </body>
</html>
```
### Sample Output
Entering 'foo@bar' brings alert about invalid address with positions; 'user@domain.com' submits normally.

## 7. Password Validation  
*(file: `js/program7_password_validation.html`)*

### Source Code
```html
<html>
  <head>
    <title> Verificatiom </title>
  </head>
  <script>
    function verifyPassword() {
      var pw = document.getElementById("pswd").value;
      var pw1 = document.getElementById("pswd1").value;
      if (pw == "") {
        document.getElementById("message").innerHTML = "**Fill the password!";
        return false;
      }
      if (pw.length < 8) {
        document.getElementById("message").innerHTML = "** length must be atleast 8 characters";
        return false;
      }
      if (pw.length > 15) {
        document.getElementById("message").innerHTML = "** length must not exceed 15 characters";
        return false;
      }
      if (pw != pw1) {
        document.getElementById("message").innerHTML = "** password and confirm password must be same";
        return false;
      } else {
        alert("Password is correct");
      }
    }
  </script>
  <body>
    <center>
      <h1 style="color:Orange">StudyTonight</h1>
      <h3> Validate password </h3>
      <form onsubmit="return verifyPassword()">
        <td> Enter Username</td>
        <input type="username" id="usr" value=""><br><br>
        <td> Enter Password </td>
        <input type="password" id="pswd" value="">
        Enter confirm password<input type="password" id="pswd1" value="">
        <span id="message" style="color:orange"> </span> <br><br>
        <input type="submit" value="Submit" style="border-color:orange">
        <button type="reset" value="Reset" style="border-color:orange">Reset</button>
      </form>
    </center>
  </body>
</html>
```
### Sample Output
Entering mismatched passwords shows message '** password and confirm password must be same'; matching valid length displays alert 'Password is correct'.

## 8. Array Prompt Sum  
*(file: `js/program8_array_prompt.html`)*

### Source Code
```html
<html>
  <body>
    <script>
      var n = window.prompt("Enter size of the array");
      var arr = new Array();
      var sum = 0;
      for (let i = 1; i <= n; i++) {
        arr[i] = parseInt(window.prompt("Enter element " + i));
        sum = sum + arr[i];
      }
      alert("Sum =" + sum);
    </script>
  </body>
</html>
```
### Sample Output
Prompts 3 elements 1,2,3 then alerts 'Sum =6'.

## 9. Focus/Blur Color Change  
*(file: `js/program9_focus_blur.html`)*

### Source Code
```html
<html>
  <body>
    Enter text :
    <input type="text" id="txtbox" onfocus=change(0) onblur=change(1)>
    <script>
      function change(i) {
        if (i == 0) {
          document.getElementById("txtbox").style.backgroundColor = "lightgrey";
          document.getElementById("txtbox").style.color = "blue";
        } else {
          document.getElementById("txtbox").style.backgroundColor = "white";
          document.getElementById("txtbox").style.color = "black";
        }
      }
    </script>
  </body>
</html>
```
### Sample Output
Focusing the textbox makes it lightgrey with blue text, blur returns to white/black.

## 10. Capitals and Countries  
*(file: `js/program10_capitals.html`)*

### Source Code
```html
<html>
  <body>
    Select a country :
    <select id="countries" onchange=getCapital()>
      <option value="0">Australia</option>
      <option value="1">Poland</option>
      <option value="2">Mexico</option>
      <option value="3">Germany</option>
      <option value="4">India</option>
    </select>
    <br/><br/>
    Capital: <input type="text" id="txtbox">
    <script>
      function getCapital() {
        var capitals=["Canberra","Warsaw","Mexico City","Berlin","New Delhi"];
        var i = document.getElementById("countries").selectedOptions[0].value;
        document.getElementById("txtbox").value = capitals[i];
      }
    </script>
  </body>
</html>
```
### Sample Output
Selecting 'India' fills textbox with 'New Delhi'.

## 11. First January Sunday  
*(file: `js/program11_jan_sunday.html`)*

### Source Code
```html
<html>
  <head>
  </head>
  <body>
    <label for="Year1">Year1:</label>
    <input type="number" id="year1" name="Year1"><br><br>
    <label for="Year2">Year2:</label>
    <input type="number" id="year2" name="Year2"><br><br>
    <button onClick="sun_year()">
       Get Result
    </button>
    <p id="disp"></p>
    <script>
      function sun_year() {
        var y1 = Number(document.getElementById('year1').value);
        var y2 = Number(document.getElementById('year2').value);
        var res = " ";
        for (let year = y1; year <= y2; ++year) {
          const c_year = new Date(year, 0, 1);
          if (c_year.getDay() === 0) {
            res += year + " ,";
          }
        }
        if (y1 > y2) {
          document.getElementById('disp').innerHTML = "Year2 must be greater than Year1";
        } else {
          if (res === " ") {
            document.getElementById('disp').innerHTML = `<p>No Year Exist</p>`;
          } else {
            document.getElementById('disp').innerHTML = `<p> Year having Sunday on 1st January are :${res}</p>`;
          }
        }
      }
    </script>
  </body>
</html>
```
### Sample Output
Entering years 2000 to 2020 displays 'Year having Sunday on 1st January are :2006 ,2012 ,2017 ,'; error if start > end.

## 12. Display Bio-data  
*(file: `php/biodata.php`)*

### Source Code
```php
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
```
### Sample Output
Submitting name=Alice,address=1 Rd,phone=123 prints three <h3> lines: Hello Alice, 1 Rd, 123.

## 13. Reverse a String  
*(file: `php/reverse_string.php`)*

### Source Code
```php
<?php
function Reverse($str2)
{
    for($i2=strlen($str2)-1, $j2=0; $j2<$i2; $i2--, $j2++)
    {
        $temp2 = $str2[$i2];
        $str2[$i2] = $str2[$j2];
        $str2[$j2] = $temp2;
    }
    return $str2;
}
$str2 = "PAVANKUMARSAKE";
print_r(Reverse($str2));
?>
```
### Sample Output
Outputs 'EKASRAMUKNAVAP' for the hardcoded string.

## 14. Perfect/Abundant/Deficient (duplicate)  
*(file: `js/program14_perfect_duplicate.html`)*

### Source Code
```html
<html>
  <body>
    <h1>Perfect Number (Duplicate)</h1>
    Enter a number:
    <input type="text" id="num" />
    <input type="button" value="Find" onClick="findPerfect()" />
    <script>
      function findPerfect() {
        var n = document.getElementById('num').value;
        var sum = 0;
        for (var i = 0; i < n; i++) {
          if (n % i == 0) {
            sum = sum + i;
          }
        }
        if (sum == n)
          alert("The number is perfect ");
        else if (sum > n)
          alert("The number is abundant");
        else
          alert("The number is deficient");
      }
    </script>
  </body>
</html>
```
### Sample Output
Same alert behavior as the first program.

## 15. Pay Slip of an Employee  
*(file: `php/pay_slip.php`)*

### Source Code
```php
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
```
### Sample Output
For name Bob,basic=2000,desig=Clerk shows calculated gross and net salary values.

## 16. Display Last Visited Date/Time  
*(file: `php/last_visit.php`)*

### Source Code
```php
<html>
  <body bgcolor="87ceeb">
    <center><h2> Last visited time on the web page</h2></center>
    <br>
    <?php 
    $inTwoMonths = 60 * 60 * 24 * 60 + time();
    setcookie('lastVisit', date("G:i - m/d/y"), $inTwoMonths);
    if(isset($_COOKIE['lastVisit'])) {
        $visit = $_COOKIE['lastVisit'];
        echo "Your last visit was - ". $visit;
    } else
        echo "You've got some stale cookies!";
    ?>
  </body>
</html>
```
### Sample Output
First visit shows stale cookie message; second visit shows 'Your last visit was - 13:45 - 03/03/26'.

## 17. List of Fruits in a List Box  
*(file: `php/fruits_list.php`)*

### Source Code
```php
<html>
  <body>
    <form action="" method="POST">
      Choose any fruit
      <select name="fruits">
        <option value="Mango">Mango</option>
        <option value="Grape">Grape</option>
        <option value="Banana">Banana</option>
        <option value="Chicku">Chicku</option>
        <option value="Apple">Apple</option>
        <option value="Orange">Orange</option>
        <option value="Pine Apple">Pine Apple</option>
      </select><br><br>
      <input type="submit" value="SELECT">
    </form>
  </body>
</html>
<?php 
if ($_POST) {
    echo "<h2> You have selected : </h2>";
    echo $_POST["fruits"];
}
?>
```
### Sample Output
Selecting Mango and submitting yields 'You have selected : Mango'.

## 18. Store 10 Names in an Array  
*(file: `php/names_array.php`)*

### Source Code
```php
<html>
  <body>
    <h1>Array Operations</h1>
    <form action="" method="post">
      <input type=radio name=choice value=display>Display Array<br />
      <input type=radio name=choice value=sort>Sorted Array<br />
      <input type=radio name=choice value=dupli>Without Duplicate<br />
      <input type=radio name=choice value=pop>Delete Last<br />
      <input type=radio name=choice value=rev>Array Reverse<br />
      <input type=radio name=choice value=search>Array Search<br /><br/>
      <input type=Submit>
    </form>
  </body>
</html>
<?php 
if ($_POST) {
    $countries = array("Chile", "Colombia", "Pakistan", "Pakistan", "Italy","Chile", "Austria", "New Zealand", "United States");
    $val = $_POST['choice'];
    switch ($val) {
        case "display":
            foreach ($countries as $value)
                echo "<br>" . $value;
            break;
        case "sort":
            sort($countries);
            foreach ($countries as $value)
                echo "<br>" . $value;
            break;
        case "dupli":
            $uarray = array_unique($countries);
            foreach ($uarray as $value)
                echo "<br>" . $value;
            break;
        case "pop":
            array_pop($countries);
            foreach ($countries as $value)
                echo "<br>" . $value;
            break;
        case "rev":
            $revarr = array_reverse($countries);
            foreach ($revarr as $value)
                echo "<br>" . $value;
            break;
        case "search":
            echo "<br/><br/>Position - " . array_search("Italy", $countries, true);
            break;
    }
}
?>
```
### Sample Output
Choosing 'display' prints each country on a new line; 'search' prints 'Position - 4'.

## 19. Multiplication Table using PHP (+ AJAX)  
*(file: `php/multiplication_table.php`)*

### Source Code
```php
<html>
  <head>
  </head>
  <script>
    function loadDoc() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("demo").innerHTML = this.responseText;
        }
      };
      xhttp.open("GET", "ajax_info.txt", true);
      xhttp.send();
    }
  </script>
  <body>
    <center>
      <h3>
        Program to print multiplication<br>
        table of any number in PHP
      </h3>
      <form method="POST">
        Enter a number:
        <input type="text" name="number">
        <input type="submit" value="Get Multiplication Table" >
      </form>
    </center>
    <div id="demo">
      <h2>Let AJAX display the details</h2>
      <button type="button" onclick="loadDoc()">Explaind the details of program by ajax</button>
    </div>
  </body>
</html>

<?php 
if($_POST) {
    $num = $_POST["number"];
    for ($i = 1; $i <= 10; $i++) {
        echo ("<p style='text-align: center;'>$num" . " X " . "$i" . " = " . $num * $i . "</p>");
    }
}
?>
```
### Sample Output
Entering 3 produces lines '3 X 1 = 3' through '3 X 10 = 30'; clicking AJAX button loads explanation text.

## 20. Upload File to Server  
*(file: `php/upload_file.php`)*

### Source Code
```php
<html>
  <body>
    <form action = "" method = "POST" enctype = "multipart/form-data">
      Select a File
      <input type = "file" name = "image" />
      <input type = "submit"/>
    </form>
  </body>
</html>

<?php if(isset($_FILES['image'])) {
    echo "File Name: ".$_FILES['image']['name']."<br>";
    echo "File Size: ".$_FILES['image']['size']."<br>";
    echo "File Type: ".$_FILES['image']['type']."<br>";
    echo "<br>Success Uploaded ";
} 
?>
```
### Sample Output
Uploading file 'test.txt' outputs 'File Name: test.txt' followed by size and type and 'Success Uploaded'.