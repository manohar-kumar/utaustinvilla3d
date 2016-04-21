import subprocess,pyautogui,time,os

subprocess.call(["ps axu | grep rcs | awk '{print $2}' | xargs -n1 kill -9"],shell = True)

subprocess.Popen(["rcsoccersim3d"])
time.sleep(2)
subprocess.call(["rm end_out"],shell=True)
subprocess.call(["./start.sh"])
time.sleep(1)
pyautogui.PAUSE = 2.5
pyautogui.click()
pyautogui.press('b')
count = 1
while True:
	count = count + 1
	if (os.path.isfile("end_out")) or (count>=8000000):
		if count >= 8000000:
			with open("end_out",'w') as text_file:
				text_file.write(str(300.00));
		break
