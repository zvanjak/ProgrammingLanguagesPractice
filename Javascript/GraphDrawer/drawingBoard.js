var Config = {
    canvasWidth: 1000,
    canvasHeight: 700,
    boardDelta: 50,
    yScaleFactor: 100,
    xPointsNum: 50,
    xStart: -1,
    xEnd: 1,
    yMin: -1,
    yMax: 1,

    adjustYRange: function(funcBody)
    {
        // idemo naći najveću i najmanju vrijednost po y-osi
        var y = Config.evaluateFuncValue(Config.xStart, funcBody);

        Config.yMin = y;
        Config.yMax = y;

        for(i=0; i<=Config.xPointsNum; i++)
        {
            x = Config.xStart + i / Config.xPointsNum * (Config.xEnd - Config.xStart);
            y = Config.evaluateFuncValue(x, funcBody);

            if( y < Config.yMin ) Config.yMin = y;
            if( y > Config.yMax ) Config.yMax = y;
        }

        return [Config.yMin, Config.yMax];
    },

    evaluateFuncValue: function(x, funcBody)
    {
        var expr = "x="+x+";"+funcBody;
        var y = eval(expr);

        return y;
    },

    getDrawAreaWidth: function() { return Config.canvasWidth - 2 * Config.boardDelta; },
    getDrawAreaHeight: function() { return Config.canvasHeight- 2 * Config.boardDelta; },

    getGraphPointScreenCoordinates: function(x, funcBody)
    {
        var y = Config.evaluateFuncValue(x);

        var xCanvasCoord = (x - Config.xStart) / (Config.xEnd - Config.xStart) * Config.getDrawAreaWidth() + Config.boardDelta;
        var yCanvasCoord = (y - Config.yMin) / (Config.yMax - Config.yMin) * Config.getDrawAreaHeight() + Config.boardDelta;

        return [xCanvasCoord, yCanvasCoord];
    }
};

function drawCoordinateSystem(funcBody)
{
    var theCanvas = document.getElementById("canvasOne");
    var context = theCanvas.getContext("2d");

    // najprije ćemo riješiti x-os
    for( i=0; i<=10; i++ )
    {
        var xValue = Config.xStart + (Config.xEnd - Config.xStart) / 10 * i;
        var xGraphPixel = Config.boardDelta + (Config.canvasWidth - 2*Config.boardDelta) / 10 * i;

        context.beginPath();
        context.strokeStyle = "black";
        context.lineWidth = 2;
        context.moveTo(xGraphPixel, Config.canvasHeight-Config.boardDelta-5);
        context.lineTo(xGraphPixel, Config.canvasHeight-Config.boardDelta+5);
        context.stroke();
        context.closePath();

        // labela
        context.fillStyle  = "#000000";
        context.font = "13px _sans";
        context.textBaseline = "top";
        context.fillText  ("" + Math.round(xValue*100)/100, xGraphPixel - 10, Config.canvasHeight - Config.boardDelta + 15 );
    }

    // zatim cemo rijesiti y-os
    for( i=0; i<=10; i++ )
    {
        var yValue = Config.yMax - (Config.yMax - Config.yMin) / 10 * i;
        var yGraphPixel = Config.boardDelta + (Config.canvasHeight - 2*Config.boardDelta) / 10 * i;

        context.beginPath();
        context.strokeStyle = "black";
        context.lineWidth = 2;
        context.moveTo(Config.boardDelta - 5, yGraphPixel);
        context.lineTo(Config.boardDelta + 5, yGraphPixel);
        context.stroke();
        context.closePath();

        // labela
        context.fillStyle  = "#000000";
        context.font = "13px _sans";
        context.textBaseline = "top";
        context.fillText  ("" + Math.round(yValue*100)/100, Config.boardDelta - 30, yGraphPixel-5);
    }

    // i zatim cemo nacrtati koordinatne osi (ako ih ima, odnosno nalaze se unutar view-a)
    context.beginPath();
    context.strokeStyle = "black";
    context.lineWidth = 2;
    if( Config.xStart < 0 && Config.xEnd > 0 )
    {
        var xAxis = Math.abs(Config.xStart) / (Config.xEnd - Config.xStart) * Config.getDrawAreaWidth() + Config.boardDelta;

        context.moveTo(xAxis, Config.boardDelta);
        context.lineTo(xAxis, Config.canvasHeight - Config.boardDelta );
    }
    if( Config.yMin < 0 && Config.yMax > 0 )
    {
        var yAxis = Math.abs(Config.yMax) / (Config.yMax - Config.yMin) * Config.getDrawAreaHeight() + Config.boardDelta;

        context.moveTo(Config.boardDelta, yAxis);
        context.lineTo(Config.canvasWidth - Config.boardDelta, yAxis);
    }
    context.stroke();
    context.closePath();
}

function automaticallyAdjustYScale(funcBody)
{
    var yVals = Config.adjustYRange(funcBody);

    var yBig = Math.max(Math.abs(Config.yMin), Math.abs(Config.yMax));
    yScaleFactor = Config.canvasHeight/2 / yBig;

    MainForm.yStart.value = Config.yMin;
    MainForm.yEnd.value = Config.yMax;

    alert("yScalefactor = " + Config.yScaleFactor);
}

function drawFunction(funcBody)
{
    if( typeof funcBody === "undefined")
        return;

    try
    {
        var theCanvas = document.getElementById("canvasOne");
        var context = theCanvas.getContext("2d");

        if( MainForm.automaticallyAdjust.checked )
            automaticallyAdjustYScale(funcBody);

        if( funcBody == null)
            return;
//        else
//            alert("drawing function: " + funcBody);

        x = Config.xStart;
        expr = "x="+x+";"+funcBody;
        y = eval(expr) * Config.yScaleFactor;

        if( y != NaN ) {
            context.beginPath();
            context.strokeStyle = "black";
            context.lineWidth = 2;
            context.moveTo(Config.boardDelta,y + Config.canvasHeight/2);
        }

        for(i=0; i<=Config.xPointsNum; i++)
        {
            x = Config.xStart + i / Config.xPointsNum * (Config.xEnd - Config.xStart);
            expr = "x="+x+";"+funcBody;
//            y = eval(expr) * Config.yScaleFactor;
            y = eval(expr);
            var yCoord = Config.canvasHeight - Config.boardDelta - (y - Config.yMin)/(Config.yMax - Config.yMin) * (Config.canvasHeight - 2 * Config.boardDelta);

            context.lineTo(Config.boardDelta + i * (Config.canvasWidth-2*Config.boardDelta)/Config.xPointsNum, yCoord);
//            context.lineTo(Config.boardDelta + i * (Config.canvasWidth-2*Config.boardDelta)/Config.xPointsNum, y + Config.canvasHeight/2);
            context.stroke();
        }
        context.closePath();
    }
    catch(err)
    {
        txt="There was an error on this page.\n\n";
        txt+="Error description: " + err.message + "\n\n";
        txt+="Click OK to continue.\n\n";
        alert(txt);
    }
}

