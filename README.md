# VisualLogic
Visualize a logical circuit and shows the result of circuit. coded by MFC

## Setup

C++, MFC on visual studio 2010

## Sample Image
![capture2](https://user-images.githubusercontent.com/24787741/29772114-25790492-8c32-11e7-92ad-400154cd227e.PNG)

## Motive

This project is an application coded by C++ MFC. Purpose of making this application is help you when you wants to draw logic gate which is an elementary building block of a digital circuit. Drawing logic gates is hard work, so I want to make application that can help drawing the circuit and want to see the result of that circuit. this can draw gate with one click, and move gate with drag and drop. and also it arranges the lines! and I can see an logical result. 

## How to Use

* Drawing Gate

You can draw the gates which is on top menu bar. (input, AND, OR, XOR, Encoder, Decoder, 7 Segment) <br>
Also you can Add NOT module on AND, OR, XOR. Input gate's first value is 1. If you click the gate, it's value will togle.

click the icon that you wants to draw, and click on the window.

* Connect the gate

If you places the mouse pointer on the end of the gate line (input or output), you will see the circle.
than drag and drop to other gate's circle that appears on the end of the gate. It will connect with line each other.

* Arrage the line

If you press the space bar, program will arrage the line of the circuit automatically.

* See the result

If you press the F5 button, program will give you the result of the circuit. If the ciruit has error or If it has a gate that is not connected, program will return error message.
