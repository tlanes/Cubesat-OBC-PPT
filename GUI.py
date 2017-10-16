import serial
import time
import tkinter

def quit():
    global tkTop
    tkTop.destroy()

def setCheckButtonText():
    if varCheckButton.get():
        varLabel.set("LED ON")
        ser.write(bytes('H', 'UTF-8'))
    else:
        varLabel.set("LED OFF")
        ser.write(bytes('L', 'UTF-8'))

ser = serial.Serial('/dev/cu.usbmodem1421', 9600)
print("Reset Arduino")
time.sleep(3)
ser.write(bytes('L', 'UTF-8'))

tkTop = tkinter.Tk()
tkTop.geometry('600x300')

varLabel = tkinter.StringVar()
tkLabel = tkinter.Label(textvariable=varLabel)
tkLabel.pack()

varCheckButton = tkinter.IntVar()
tkCheckButton = tkinter.Checkbutton(
    tkTop,
    text="Control Arduino LED",
    variable=varCheckButton,
    command=setCheckButtonText)
tkCheckButton.pack(anchor=tkinter.CENTER)

tkButtonQuit = tkinter.Button(
    tkTop,
    text="Quit",
    command=quit)
tkButtonQuit.pack()

#tkRollButton = tkinter.Button(
#        tkTop,
#        text="Roll",
#        command=)

tkinter.mainloop()
