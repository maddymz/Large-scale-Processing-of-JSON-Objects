# Large-scale-Processing-of-JSON-Objects

## Library used: jsoncpp
### Installation and linking 
```
Step1: Clone the library from github repository: https://github.com/open-source-parsers/jsoncpp.git
Step2: Navigate to the cloned directory and run "python amalgamate.py" to create an amalgamated source
Step3: Three files will get created as a result of this json.h, jsoncpp.cpp, json-forward.h, under dist directory
Step4: Add all these files to your project 
Step5: Add #include <json/json.h> to the main source code 
Step6: Copy the files under "include" directory of "jsoncpp" and paste them in "include"diretory of the compiler which you are using  
```
## Build
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
./executable.exe`

````

## Task 2
### 1. Performance enhancement techniques
1.Cashing

2.Conversion into bytes

## Task 3
### 1. Computer Configuration
1.Number of CPU Cores:  4 Core(s), 8 Logical Processor(s).

2.Type of Disk: SSD.

3.Operting System: Microsoft Windows 10 Home. 

4.Version:	10.0.17134.

5.Physical Memory (RAM)	8.00 GB.


### 2. Performance Bottlenecks
1. Without using any performance enhancement techniques, medium.txt was not even processed.



