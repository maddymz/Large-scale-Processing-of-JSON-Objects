# Large-scale-Processing-of-JSON-Objects

## Library used: jsoncpp
### Installation and linking 
```
Step1: Clone the library from github repository: https://github.com/open-source-parsers/jsoncpp.git
Step2: Navigate to the cloned directory and run "python amalgamate.py" to create an amalgamated source
Step3: Three files will get created as a result of this json.h, jsoncpp.cpp, json-forward.h, under dist directory
Step4: Add all these files to your project 
Step5: Add #include <json/json.h> to the main source code 
Step6: Add path of "include" directory to "includepath" of the "c_cpp_properties.json"
```
## Build Instructions
1. Open terminal and run following command which creates an object file(this needs to be done only once) :

````
g++ -c  <file having main src code>

eg; g++ -c parse.cpp

````
2. Now run the follwoing command to create executable file:

````
g++ -o <name for executable file> <path to object code> <file having main src code>

eg; g++ -o executable M:\Documents\Large-scale-Processing-of-JSON-Objects\library\jsoncpp.o parse.cpp

````
2. The above command will create an executable file which can be now executed in following way:

````
./executable.exe

````

## Test Case outputs
Small: 
1: 49.2446

2: 52.5

3: 25, 34, 55, 65, 73, 111, 118, 132, 193, 261, 284, 309, 323, 334, 351, 425, 429, 433, 442, 447, 448, 463, 466, 506, 514, 564, 566, 568, 593, 604, 652, 669, 695, 736, 753, 755, 777, 806, 838, 842, 846, 864, 893, 935, 938, 968, 970,

4: 0

Medium:

1:

2: 

3:

4: 


Large:

1: 

2:

3: 

4: 

## Task 2
### 1. Performance enhancement techniques
Reading the files by converting them to binary.
Following this approach I got significant time improvement:
small:

time taken to parse function: 1 (in clock ticks)

time taken to read and write file : 64

time taken by main function thread: 68


medium:

time taken to parse function: 0 (in clock ticks) 

time taken to read and write file : 6189

time taken by main function thread: 6190


large:

time taken to parse function: 0 (in clock ticks)

time taken to read and write file : 65011

time taken by main function thread: 65011





## Task 3
### 1. Computer Configuration
1.Number of CPU Cores:  4 Core(s), 8 Logical Processor(s).

2.Type of Disk: SSD.

3.Operting System: Microsoft Windows 10 Home. 

4.Version:	10.0.17134.

5.Physical Memory (RAM)	8.00 GB.


### 2. Performance Bottlenecks
1. I have followed the brute force approach so all of my functions take considerable amount of time 
2. Without conversion in binary I was able to record following timestamps:

small:

time taken to parse function: 562 (in clock ticks)

time taken to read and write file : 237

time taken by main function thread: 807


medium and large: was not able to record 


