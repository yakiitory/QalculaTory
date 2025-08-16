# QalculaTory

#### VIDEO DEMO:

#### Description:

<p align="center" width="100%">
  <img src="https://github.com/yakiitory/QalculaTory/blob/main/assets/qalculatory.png?raw=true" alt="QalculaTory's logo">
</p>
A scientific calculator that handles infix notation and evaluates into answers, written in C/C++ with Qt. It makes use of the Shunting Yard Algorithm in parsing infix notation to postfix notation / Reverse Polish Notation, a notation that computers can understand. Users can input an equation onto the text field or use the GUI buttons and then receive an output after pressing the equals button. It supports math functions shown in the GUI. The name is a pun on the username 'yakiitory', calculator, and the Qt framework.
<p align="center" width="100%">
  <img src="https://github.com/yakiitory/QalculaTory/blob/main/assets/example.png?raw=true" alt="Screenshot of the program">
</p>

<h2>Features</h2>
<ul>
  <li>Cross-platform interfaced implemented using Qt 6</li>
  <li>Human-readable notation equation evaluation</li>
  <li>Mathematical functions </li>
  <li>Lightweight and easy to use</li>
</ul>

<h2>Tech Stack</h2>
<ul>
  <li>C, for main calculator logic from evaluation to syntax error handling.</li>
  <li>C++, for handling UI as well as user-level abstractions.</li>
  <li>Qt, for cross-platform UI and GUI builder.</li>
</ul>

<h2>Project Structure</h2>
In the <code>src/</code> directory, all C-related code are stored and is included by the <code>main</code> related source files in <code>gui/</code>. The directory <code>src/</code> stores as follows.
<p>Source Files:</p>
<ul>
  <li><code>helpers.c</code> defines the functions for removing whitespace, retrieving binary or unary operators, their precedence, their implementation, as well as getter and setter functions for global variables such as ANS and the calculator mode.</li>
  <li><code>stack.c</code> defines the stack implementation used in the program, as well as their respective stack operations. It makes use of a singly linked list to create the stack structure for both <code>NumStack</code> and <code>OpStack</code>.</li>
  <li><code>shunting_yard.c</code> defines the implementation of the Shunting Yard Algorithm to turn an infix string to a postfix string, as well as the postfix evaluation. Both functions make ues of functions defined by previously mentioned source files. The added function, <code>handle_math_function()</code> is used to map functions that require more than one char to type (for example, <code>sin(n)</code>) into a shorthand char that <code>helpers.c</code> can understand and pushing onto an operator stack.</li>
  <li><code>parser.c</code> defines a function that accepts a string as a parameter to be used by the proper shunting yard functions. The source file is merely used for abstraction when called by the GUI.</li>
  <li><code>main.c</code> defines the CLI version of the program. It is merely a leftover from when the project has not had a GUI yet and was used extensibly for debugging.</li>
</ul>
In the <code>gui/</code> directory, all C++ / Qt-related code are stored. The directory stores as follows.
<ul>
  <li><code>main.cpp</code> defines the <code>main</code> function, which implements <code>QApplication</code> and instantiates it.</li>
  <li><code>mainwindow.cpp</code> defines the implementation of the MainWindow, which sets the functionality of the buttons implemented by <code>mainwindow.ui</code>. It makes use of it by a simple loop to check for all of the buttons and add their respective functions with the use of other methods defined in the source file. This also defines the window title as well as window icon for <code>QIcon</code>.</li>
  <li><code>mainwindow.ui</code> defines the GUI used by the program in QML. It is created with the use of the GUI UI Builder in the Qt Creator IDE. Styling of the program is also defined here.</li>
  <li><code>aboutdialog.cpp</code> defines the implemntation of the <code>Help > About</code> window. It displays information about the program.</li>
  <li><code>gui.pro</code> defines the Qt project, as well as including all the source files written in C and C++/</li>
</ul>
