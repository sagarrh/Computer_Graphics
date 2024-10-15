const canvas = document.getElementById('bezierCanvas');
const ctx = canvas.getContext('2d');

const P0 = { x: 50, y: 350 };  
const P1 = { x: 200, y: 50 };  
const P2 = { x: 350, y: 350 }; 

function bezier(t, P0, P1, P2) {
    const x = Math.pow(1 - t, 2) * P0.x + 2 * (1 - t) * t * P1.x + Math.pow(t, 2) * P2.x;
    const y = Math.pow(1 - t, 2) * P0.y + 2 * (1 - t) * t * P1.y + Math.pow(t, 2) * P2.y;
    return { x, y };
}
function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

   
    ctx.fillStyle = 'black';
    ctx.beginPath();
    ctx.arc(P0.x, P0.y, 5, 0, Math.PI * 2);
    ctx.fill();
    ctx.beginPath();
    ctx.arc(P1.x, P1.y, 5, 0, Math.PI * 2);
    ctx.fill();
    ctx.beginPath();
    ctx.arc(P2.x, P2.y, 5, 0, 0);
    ctx.fill();

    ctx.strokeStyle = 'red';
    ctx.beginPath();
    ctx.moveTo(P0.x, P0.y);
    ctx.lineTo(P1.x, P1.y);
    ctx.moveTo(P1.x, P1.y);
    ctx.lineTo(P2.x, P2.y);
    ctx.stroke();

    ctx.strokeStyle = 'blue';
    ctx.beginPath();
    ctx.moveTo(P0.x, P0.y);
    for (let t = 0; t <= 1; t += 0.01) {
        const point = bezier(t, P0, P1, P2);
        ctx.lineTo(point.x, point.y);
    }
    ctx.stroke();
}


let t = 0;
function animate() {
    draw();

    
    const animatedPoint = bezier(t, P0, P1, P2);
    
    
    ctx.fillStyle = 'green';
    ctx.beginPath();
    ctx.arc(animatedPoint.x, animatedPoint.y, 5, 0, Math.PI * 2);
    ctx.fill();

    t += 0.01;
    if (t > 1) t = 0; 

    requestAnimationFrame(animate);
}

animate();
