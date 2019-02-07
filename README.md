# graph-visualizer

A parser and visualizer for functions, using the Shunting yard algorithm for parsing and SFML for visualization.

## Controls
Press "Space" while focused on the main window to enter a function in the console window. Then, press "Enter" to graph that function.

Each function must be entered with each character being spaced out with a single space (' '). For example: `sin ( x )`

### Possible operations
- Addition (+) and Subtraction (-)
- Multiplication (*) and Division (/)
- Power (^) (Example: `2 ^ 3` = 8)
- Square root (`sqrt ( )`)
- Sine (`sin ( )`) and Cosine (`cos ( )`)
- Tangent (`tan ( )`) and Cotangent (`cot ( )`)

This project uses simple methods to parse the entered function. Mainly, using the Shunting-yard algorithm to convert the notation into postfix notation.

![Graph1](https://raw.githubusercontent.com/limepixl/graph-visualizer/master/img/g1.png)
![Graph2](https://raw.githubusercontent.com/limepixl/graph-visualizer/master/img/g2.png)
![Graph3](https://raw.githubusercontent.com/limepixl/graph-visualizer/master/img/g3.png)
![Graph4](https://raw.githubusercontent.com/limepixl/graph-visualizer/master/img/g4.png)
