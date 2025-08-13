function findPerfect() {
    var n = document.getElementById('num').value;
    var sum = 0;
    for (var i = 0; i < n; i++) {
        if (n % i == 0 ) {
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