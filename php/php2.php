<?php

# 13. Write a PHP function to reverse a string

function Reverse($str2) {
    for($i2 = strlen($str2) - 1, $j2 = 0; $j2 < $i2; $j2++, $i2--) {
        $temp2 = $str2[$i2];
        $str2[$i2] = $str2[$j2];
        $str2[$j2] = $temp2;
    }
    return $str2;
}
$str2 = "Help me bro";
print_r(Reverse($str2));

?>