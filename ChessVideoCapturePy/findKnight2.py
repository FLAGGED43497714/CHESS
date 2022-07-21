import numpy as np
import cv2
import pyautogui
import time 
   
print("starting")

import win32api, win32con

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,x,y,0,0)
    win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,x,y,0,0)

while True :
    print("...")
    time.sleep(1)
    image = pyautogui.screenshot()

    image = cv2.cvtColor(np.array(image),cv2.COLOR_RGB2BGR)
    
    cv2.imwrite("full_screen.png", image)

    blanc_jaune_img = cv2.imread('blanc-jaune.png', cv2.IMREAD_UNCHANGED)
    vert_jaune_img = cv2.imread('vert-jaune.png', cv2.IMREAD_UNCHANGED)
    fullscreen_img = cv2.imread('full_screen.png', cv2.IMREAD_UNCHANGED)


    result_blanc = cv2.matchTemplate(fullscreen_img, blanc_jaune_img, cv2.NORM_L2SQR  )
    result_vert = cv2.matchTemplate(fullscreen_img, vert_jaune_img, cv2.NORM_L2SQR )

    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result_vert)

    print("max val vert = "+str(max_val))

    w_b = blanc_jaune_img.shape[1]
    h_b = blanc_jaune_img.shape[0]
    w_v = vert_jaune_img.shape[1]
    h_v = vert_jaune_img.shape[0]

    threshold_low = .83
    threshold_high = .86
    yloc_b, xloc_b = np.where(result_blanc >= threshold_low)
    yloc_v, xloc_v = np.where(( threshold_low <= result_vert ) & (result_vert <= threshold_high ))


    rectangles_blanc = []
    rectangles_vert = []
    for (x, y) in zip(xloc_b, yloc_b):
        rectangles_blanc.append([int(x), int(y), int(w_b), int(h_b)])
    for (x, y) in zip(xloc_v, yloc_v):
        rectangles_vert.append([int(x), int(y), int(w_v), int(h_v)])


    # if len(rectangles_blanc) ==0 : #0 on trouve rien, 1 il faut merge des rectangles
    #     print("0 occurence")
    #     print("rectangles_blanc : "+str(rectangles_blanc))
    #     continue 
    # if len(rectangles_blanc) >=2 : #0 on trouve rien, 1 il faut merge des rectangles
    #     print("more than 2 occurences")
    #     rectangles_blanc, weights_b = cv2.groupRectangles(rectangles_blanc, 0, 0.2)
    
     

    if(len(rectangles_blanc) != 0) :
        rectangles_blanc = rectangles_blanc[0]
    
    if(len(rectangles_vert) != 0) :
        rectangles_vert = rectangles_vert[0]

    print("rectangles_blanc = "+str(rectangles_blanc))
    print("rectangles_vert = "+str(rectangles_vert))   

    if(len(rectangles_blanc) > 1) :
        print("rectangles_blanc = "+str(rectangles_blanc))
        click(rectangles_blanc[0]+rectangles_blanc[2]//2,rectangles_blanc[1]+rectangles_blanc[3]//2)
        
    if(len(rectangles_vert) > 1) :
        print("rectangles_vert = "+str(rectangles_vert))
        click(rectangles_vert[0]+rectangles_vert[2]//2,rectangles_vert[1]+rectangles_vert[3]//2)