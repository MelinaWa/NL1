var firstslider = document.getElementById("myRange");
var output = document.getElementById("value");

output.innerHTML = slider.value;

slider.output = function() {

    output.innerHTML = this.value;

}

firstslider.addEventListener("mousemove", function() {

        var x = slider.value;
        var color = 'linear-gradient(90deg, #898989, 60%)' + x + '%, rgb(214, 214, 214) + x + ' % )
    ';
    slider.style.background = color;



}