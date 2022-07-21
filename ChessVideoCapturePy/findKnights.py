import cv2
import numpy as np

bNvert_img = cv2.imread('bNvert.png', cv2.IMREAD_UNCHANGED)
fullscreen_img = cv2.imread('fullscreen.png', cv2.IMREAD_UNCHANGED)

result = cv2.matchTemplate(fullscreen_img, bNvert_img, cv2.TM_CCOEFF_NORMED)

w = bNvert_img.shape[1]
h = bNvert_img.shape[0]

threshold = .7

yloc, xloc = np.where(result >= threshold)


rectangles = []
for (x, y) in zip(xloc, yloc):
    rectangles.append([int(x), int(y), int(w), int(h)])

rectangles, weights = cv2.groupRectangles(rectangles, 1, 0.2)

rectangles = rectangles[:,:2]

print(rectangles)

