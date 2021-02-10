function calculate() 
{
    var radios = document.getElementsByClassName("btn-group");
    var scores = 0;
    for (var i = 0; i < radios.length; i++) {
        var t = document.getElementsByName("t" + (i + 1));
        for (var j = 0; j < t.length; j++) {
            if (t[j].checked) {
                scores += t[j].value * 1;
                break;
            }
        }
    }
    document.getElementById("score").value = scores;
}