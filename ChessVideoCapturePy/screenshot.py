import numpy as np
import cv2
import pyautogui
   
  

image = pyautogui.screenshot()

image = cv2.cvtColor(np.array(image),
                     cv2.COLOR_RGB2BGR)
   
cv2.imwrite("image1.png", image)