from flask import Flask, request, jsonify, send_from_directory
import cv2
import numpy as np
import os

app = Flask(__name__)

@app.route('/')
def index():
    return send_from_directory('', 'index.html')

@app.route('/upload', methods=['POST'])
def upload_image():
    if 'image' not in request.files:
        return 'No image uploaded', 400

    file = request.files['image']
    filepath = os.path.join('uploads', file.filename)
    file.save(filepath)

    # Process the image
    control_points = process_image(filepath)

    # Return control points as JSON
    return jsonify(control_points)

def process_image(image_path):
    image = cv2.imread(image_path)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    edges = cv2.Canny(gray, 100, 200)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    control_points = []
    for contour in contours:
        for point in contour:
            control_points.append((int(point[0][0]), int(point[0][1])))

    # Remove duplicates and convert to a JSON-friendly format
    control_points = list(set(control_points))
    return control_points

if __name__ == '__main__':
    if not os.path.exists('uploads'):
        os.makedirs('uploads')
    app.run(debug=True)
