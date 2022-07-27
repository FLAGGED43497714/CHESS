import numpy as np
import pyautogui
import time
   
print("starting")

import win32api, win32con

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,x,y,0,0)
    win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,x,y,0,0)



vert_jaune = [186,202,43]
blanc_jaune = [246, 246, 105]



while True :
    
    # print("...")
    time.sleep(.5)

    image = np.array(pyautogui.screenshot())

    # print(image[360][400])

    # filtre = [0,0]

    res = []

    for ligne in range(333,940,83) :
        for colonne in range(415,1000,83) :
            # win32api.SetCursorPos((colonne,ligne))
            # time.sleep(0.2)
            # print(filtre)
            # if (( ligne >= filtre[0]) and (ligne <= filtre[0]+85 )) :
                # if (( colonne >= filtre[1]) and (colonne <= filtre[1]+85 )) :
                    # print("continuing")
                    # continue

            if image[ligne][colonne][0] == vert_jaune[0] :
                if image[ligne][colonne][1] == vert_jaune[1] :
                    if image[ligne][colonne][2] == vert_jaune[2] :
                        # print("found")
                        res += [[ligne, colonne]]
                        # filtre = [ligne, colonne]

            if image[ligne][colonne][0] == blanc_jaune[0] :
                if image[ligne][colonne][1] == blanc_jaune[1] :
                    if image[ligne][colonne][2] == blanc_jaune[2] :
                        # print("found")
                        res += [[ligne, colonne]]
                        # filtre = [ligne, colonne]
            
            if (len(res) == 2 ) :
                found = True
                break
        
    
    print("res = "+str(res))

    if (len(res) ==2 ) :
        # if (len(res[0]) !=0 ) :
            x = res[0][1]
            y = res[0][0]
            xNum = 7 - ((x-415)//83)
            yNum = 56 - 8*((y-333)//83) 
            square1 = xNum + yNum

            # print(xNum)
            # print(yNum)
            # print(x)
            # print(y)
            # print(xNum+yNum)
            # win32api.SetCursorPos((x,y))
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,x,y,0,0)
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,x,y,0,0)
            # time.sleep(0.5)
            x = res[1][1]
            y = res[1][0]
            xNum = 7 - ((x-415)//83)
            yNum = 56 - 8*((y-333)//83) 
            square2 = xNum + yNum

            print(square1, square2)
            
            # pyautogui.keyDown('alt')
            # time.sleep(.3)
            # pyautogui.press('tab')
            # time.sleep(.3)
            # pyautogui.keyUp('alt')

            # time.sleep(1.5)
            # pyautogui.keyDown('delete')
            # time.sleep(0.3)
            # pyautogui.keyDown('delete')
            # time.sleep(0.3)
            # pyautogui.typewrite(str(square1))
            # time.sleep(0.3)
            # pyautogui.keyDown('enter')
            # time.sleep(0.3)
            # pyautogui.typewrite(str(square2))
            # time.sleep(0.3)
            # pyautogui.keyDown('enter')
            # time.sleep(1)
            # pyautogui.keyDown('delete')
            # time.sleep(0.3)
            # pyautogui.keyDown('delete')
            # time.sleep(0.3)
            # pyautogui.typewrite(str(square2))
            # time.sleep(0.3)
            # pyautogui.keyDown('enter')
            # time.sleep(0.3)
            # pyautogui.typewrite(str(square1))
            # time.sleep(0.3)
            # pyautogui.keyDown('enter')
            # time.sleep(0.3)


            # print(xNum)
            # print(yNum)
            # print(x)
            # print(y)
            # print(xNum+yNum)
            # win32api.SetCursorPos((x,y))
            # # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,x,y,0,0)
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,x,y,0,0)

            # #click pour pas perdre le control
            # x = res[0][1]
            # y = res[0][0]
            # win32api.SetCursorPos((x,y))
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,x,y,0,0)
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,x,y,0,0)
            
            # time.sleep(0.1)
            # x = res[1][1]
            # y = res[1][0]
            # win32api.SetCursorPos((x,y))
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,x,y,0,0)
            # win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,x,y,0,0)
            

    # print('sleeping')
    # time.sleep(5)
