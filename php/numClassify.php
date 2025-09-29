<?php
$num=$_POST["num"];
$sum=0;
if(is_numeric($num)) {
    for($i=1;$i<$num;$i++) {
        $temp=$i;
        if($num%$temp==0)
            $sum=$sum+$temp;
    }
    if ($sum==$num) {
    echo "<b>".$num." is a perfect number"."</b>";
    }else if($sum < $num)
    echo "<b>".$num." is a deficient number"."</b>";
    else
    echo "<b>".$num." is an abundant number"."</b>";
}
?>