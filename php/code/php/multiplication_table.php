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