const boardWidth = 800;
const boardHeight = 800;
const circleRadius = 20;

function drawCircle(x , y)
{
    var theCanvas = document.getElementById("canvasOne");
    var context = theCanvas.getContext("2d");

    context.beginPath();
    context.strokeStyle = "black";
    context.lineWidth = 5;
    context.arc(x, y, circleRadius, (Math.PI/180)*0, (Math.PI/180)*360, false);
    context.stroke();
    context.closePath();
}

function drawBoard () {
    if (!canvasSupport()) {
        return;
    }
    var theCanvas = document.getElementById("canvasOne");
    var context = theCanvas.getContext("2d");

    Debugger.log("Drawing Canvas");

    function drawScreen() {
        //background
        context.fillStyle = "#ffffaa";
        context.fillRect(0, 0, boardWidth, boardHeight);
        //text
        context.fillStyle  = "#000000";
        context.font = "20px _sans";
        context.textBaseline = "top";
        context.fillText  ("Primjer teksta", 100, 50 );

        //box
        context.strokeStyle = "#000000";
        context.strokeRect(100, 200, 200, 250);


        drawCircle(100,100);
    }
    drawScreen();
}