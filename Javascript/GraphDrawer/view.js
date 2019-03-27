/**
 * Created by JetBrains WebStorm.
 * User: zvanjak
 * Date: 13.09.12.
 * Time: 22:13
 * To change this template use File | Settings | File Templates.
 */

function autoAdjustYScaleClicked()
{
    if( MainForm.automaticallyAdjust.checked == true )
    {
        MainForm.yStart.disabled = true;
        MainForm.yEnd.disabled = true;
    }
    else
    {
        MainForm.yStart.disabled = false;
        MainForm.yEnd.disabled = false;
    }
}

function drawScreen() {
    var theCanvas = document.getElementById("canvasOne");
    var context = theCanvas.getContext("2d");

    // rectangle
    context.beginPath();
    context.lineWidth="5";
    context.strokeStyle="black";
    context.rect(0, 0, Config.canvasWidth, Config.canvasHeight);
    context.stroke();

    //background
    context.fillStyle = "#ffffaa";
    context.fillRect(3, 3, Config.canvasWidth-6, Config.canvasHeight-6);

    // rectangle
    context.beginPath();
    context.lineWidth="2";
    context.strokeStyle="black";
    context.rect(Config.boardDelta, Config.boardDelta, Config.canvasWidth-2*Config.boardDelta, Config.canvasHeight-2*Config.boardDelta);
    context.stroke();
}

function drawBoard () {
    if (!canvasSupport()) {
        return;
    }
    //Debugger.log("Drawing Canvas");

    drawScreen();
}

function drawEvent(e)
{
    functionDefinition = MainForm.funcDefinition.value; //document.getElementByName("funcDefinition").value;

    Config.yScaleFactor = parseFloat(MainForm.yScaleFactor.value);
    Config.xPointsNum = parseInt(MainForm.xPointsNum.value);

    Config.xStart = parseFloat(MainForm.xStart.value);
    Config.xEnd = parseFloat(MainForm.xEnd.value);

    drawScreen();

    drawFunction(functionDefinition);

    drawCoordinateSystem(functionDefinition);
}
