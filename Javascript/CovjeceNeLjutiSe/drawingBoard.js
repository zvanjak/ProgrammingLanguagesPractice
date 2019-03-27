const boardWidth = 800;
const boardHeight = 800;
const circleRadius = 20;

function drawPlayersHomes(startX, startY, deltaX, deltaY, numCircles)
{
    for(i=0; i<numCircles; i++ )
    {
        drawBoardCircle(startX + deltaX * i, startY + deltaY * i);
    }
}

function drawFields()
{
    for(i=0; i<10; i++ )
    {
        x = 200 * Math.cos(i*9/180*Math.PI);
        y = 200 * Math.sin(i*9/180*Math.PI);

        drawBoardCircle(x, y);
    }
}
function drawBoardCircle(x , y)
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
//        context.fillStyle  = "#000000";
//        context.font = "20px _sans";
//        context.textBaseline = "top";
//        context.fillText  ("Hello World!", 195, 0 );

        //box
        context.strokeStyle = "#000000";
        context.strokeRect(5,  5, boardWidth-10, boardHeight-10);

        drawPlayersHomes(100, boardHeight/2 - circleRadius/2, 60, 0, 4);
        drawPlayersHomes(boardWidth - 100, boardHeight/2 - circleRadius/2, -60, 0, 4);
        drawPlayersHomes(boardWidth/2, 100, 0, 60, 4);
        drawPlayersHomes(boardWidth/2, boardHeight - 100, 0, -60, 4);

        drawFields();
    }
    drawScreen();
}