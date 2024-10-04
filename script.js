const canvas = document.getElementById('bezierCanvas');
const ctx = canvas.getContext('2d');

let points = [
    { x: 100, y: 500 },  // Start point
    { x: 200, y: 100 },  // Control point 1
    { x: 600, y: 100 },  // Control point 2
    { x: 700, y: 500 }   // End point
];

let draggingPoint = null;

// Add event listeners for adding and updating points
document.getElementById('addPoint').addEventListener('click', addControlPoint);
document.getElementById('updatePoint').addEventListener('click', updateControlPoint);

canvas.addEventListener('mousedown', (event) => {
    const mousePos = getMousePos(canvas, event);
    draggingPoint = points.find(point => isPointInside(mousePos, point));
});

canvas.addEventListener('mouseup', () => {
    draggingPoint = null;
});

canvas.addEventListener('mousemove', (event) => {
    if (draggingPoint) {
        const mousePos = getMousePos(canvas, event);
        draggingPoint.x = mousePos.x;
        draggingPoint.y = mousePos.y;
        draw();
    }
});

function getMousePos(canvas, event) {
    const rect = canvas.getBoundingClientRect();
    return {
        x: event.clientX - rect.left,
        y: event.clientY - rect.top
    };
}

function isPointInside(mousePos, point) {
    const radius = 10;
    return (mousePos.x > point.x - radius && mousePos.x < point.x + radius &&
            mousePos.y > point.y - radius && mousePos.y < point.y + radius);
}

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    // Draw the Bezier curve
    ctx.beginPath();
    ctx.moveTo(points[0].x, points[0].y);
    ctx.bezierCurveTo(points[1].x, points[1].y, points[2].x, points[2].y, points[3].x, points[3].y);
    ctx.strokeStyle = 'blue';
    ctx.lineWidth = 2;
    ctx.stroke();

    // Draw guiding lines
    ctx.strokeStyle = 'lightgray';
    ctx.lineWidth = 1;

    for (let i = 0; i < points.length - 1; i++) {
        ctx.beginPath();
        ctx.moveTo(points[i].x, points[i].y);
        ctx.lineTo(points[i + 1].x, points[i + 1].y);
        ctx.stroke();
    }

    // Draw control points
    points.forEach(point => {
        ctx.fillStyle = 'red';
        ctx.beginPath();
        ctx.arc(point.x, point.y, 10, 0, Math.PI * 2);
        ctx.fill();
    });
}

function addControlPoint() {
    const newPoint = {
        x: Math.random() * canvas.width,
        y: Math.random() * canvas.height
    };
    points.splice(points.length - 1, 0, newPoint); // Add before the last point (end point)
    draw();
}

function updateControlPoint() {
    const index = parseInt(document.getElementById('pointIndex').value);
    const x = parseFloat(document.getElementById('pointX').value);
    const y = parseFloat(document.getElementById('pointY').value);

    if (index >= 0 && index < points.length) {
        points[index].x = x;
        points[index].y = y;
        draw();
    } else {
        alert('Index out of bounds');
    }
}

// Initial draw
draw();
