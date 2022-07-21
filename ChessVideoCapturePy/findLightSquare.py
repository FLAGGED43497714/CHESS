import numpy as np
import cv2
import pyautogui
import time 
   
print("starting")

while True :
    print("...")
    time.sleep(1)
    image = pyautogui.screenshot()

    image = cv2.cvtColor(np.array(image),cv2.COLOR_RGB2BGR)
    
    cv2.imwrite("full_screen.png", image)

    blanc_jaune_img = cv2.imread('blanc-jaune.png', cv2.IMREAD_UNCHANGED)
    vert_jaune_img = cv2.imread('vert-jaune.png', cv2.IMREAD_UNCHANGED)
    fullscreen_img = cv2.imread('full_screen.png', cv2.IMREAD_UNCHANGED)

    print("1")

    result_blanc = cv2.matchTemplate(fullscreen_img, blanc_jaune_img, cv2.TM_CCOEFF_NORMED)
    result_vert = cv2.matchTemplate(fullscreen_img, blanc_jaune_img, cv2.TM_CCOEFF_NORMED)

    w_b = blanc_jaune_img.shape[1]
    h_b = blanc_jaune_img.shape[0]
    w_v = vert_jaune_img.shape[1]
    h_v = vert_jaune_img.shape[0]

    threshold = .7

    yloc_b, xloc_b = np.where(result_blanc >= threshold)
    yloc_v, xloc_v = np.where(result_vert >= threshold)

    print("2")

    rectangles_blanc = []
    rectangles_vert = []
    for (x, y) in zip(xloc_b, yloc_b):
        rectangles_blanc.append([int(x), int(y), int(w_b), int(h_b)])
    for (x, y) in zip(xloc_v, yloc_v):
        rectangles_vert.append([int(x), int(y), int(w_v), int(h_v)])

    print("3")

    rectangles_blanc, weights_b = cv2.groupRectangles(rectangles_blanc, 1, 0.2)
    rectangles_vert, weights_v = cv2.groupRectangles(rectangles_vert, 1, 0.2)

    print("4")

    rectangles_blanc = rectangles_blanc[:,:2]
    rectangles_vert = rectangles_vert[:,:2]

    print("5")

    print(rectangles_blanc)
    print(rectangles_vert)

