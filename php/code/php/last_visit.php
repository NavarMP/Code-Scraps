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