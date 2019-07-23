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
Build the project using any c++ compiler or you can use Cmake
