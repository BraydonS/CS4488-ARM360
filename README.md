# CS4488-ARM360

## Description
This program is meant as a learning tool to assist Computer Science students with understanding of the assembly instruction set.
- It allows students to build and walk through simple assembly programs to understand the instructions
- All instructions can be run with a single button press, or can be run just one at a time

### Installation
- Select a release from https://github.com/BraydonS/CS4488-ARM360/releases
- [Only one release currently]
- The program is not currently available in a executable form, so the code must be compiled and run locally
  - Ensure that you have an up to date version of C++ and Qt version 6.4.2

### Usage
This program provides a simple graphical user interface, allowing for intuitive interactions. It contains view of each register and
their values at the bottom of the interface, a view of the program counter's value at the top-right corner of the interface,
a view of the loaded instructions at the top-middle of the interface, and several labeled buttons - see below for use.
- A text file containing the instructions must be first loaded into the program by pressing "Load" and navigating to the desired file
  - If you attempt to build/run the program without a file loaded, the program will warn you and stall
  - <b>WARNING:</b> If you edit the instructions within the text box, it will edit them in the file they were loaded from
- Once the text is loaded, the instructions must be properly built into the system by pressing "Build"
- The instructions can now be executed either all at once, or one at a time
  - Press "Run" to execute all instructions, in sequence, until the end of the file is reached
  - Press "Next" to only execute the next, unexecuted instruction. This allows for detailed visuals of the changing registers

###Project Demo
![ARM360 Demo](https://user-images.githubusercontent.com/46699115/235189973-5bb7ffc5-5293-4793-8f19-b75c8e129646.gif)


### Contributing
This project is not accepting any external contributors.


#### Credits
- Original Authors
  - Traae Bloxham
  - David Hellwig
  - Daniel Igbokwe
  - Thomas Neyman
- Port/Upgrade Authors
  - Autumn Clark
  - Sushan Manandhar
  - Show Pratoomratana
  - Braydon Spaulding


#### MIT License

Copyright 2022 Traae Bloxham, David Hellwig, Daniel Igbokwe, Thomas Neyman</br>
Copyright 2023 Autumn Clark, Sushan Manandhar, Show Pratoomratana, Braydon Spaulding

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
