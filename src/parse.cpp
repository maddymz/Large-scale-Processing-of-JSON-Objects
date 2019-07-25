/*
** This file contains the code for processing 
**small to large sacle json data
 */

#include <json/json.h>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace Json;


using namespace std; 
  
class LRUCache { 
    // store keys of cache 
    list<int> dq; 
  
    // store references of key in cache 
    unordered_map<int, list<int>::iterator> ma; 
    int csize; // maximum capacity of cache 
  
public: 
    LRUCache(int); 
    void refer(int); 
    void display(); 
}; 
  
// Declare the size 
LRUCache::LRUCache(int n) 
{ 
    csize = n; 
} 
  
// Refers key x with in the LRU cache 
void LRUCache::refer(int x) 
{ 
    // not present in cache 
    if (ma.find(x) == ma.end()) { 
        // cache is full 
        if (dq.size() == csize) { 
            // delete least recently used element 
            int last = dq.back(); 
  
            // Pops the last elmeent 
            dq.pop_back(); 
  
            // Erase the last 
            ma.erase(last); 
        } 
    } 
  
    // present in cache 
    else
        dq.erase(ma[x]); 
  
    // update reference 
    dq.push_front(x); 
    ma[x] = dq.begin(); 
} 
  
// Function to display contents of cache 
void LRUCache::display() 
{ 
  
    // Iterate in the deque and print 
    // all the elements in it 
    for (auto it = dq.begin(); it != dq.end(); 
         it++) 
        cout << (*it) << " "; 
  
    cout << endl; 
}


void printValues(double avg, double maxOfMax, vector<int> idArry, vector<int> idList)
{
    cout << "1: " << avg << "\n";
    cout << "2: " << maxOfMax << "\n";
    cout << "3: ";
    for (auto itr = idArry.begin(); itr != idArry.end(); itr++)
    {
        cout << (*itr) << ", ";
    }
    cout << "\n";
    cout << "4: " << idList.size() << "\n";
    for (auto itr = idList.begin(); itr != idList.end(); itr++)
    {
        cout << (*itr) << ", ";
    }
}

bool parseJson(const char *begin, const char *end)
{
    clock_t parseTime;
    parseTime = clock();
    CharReaderBuilder charBuilder;
    CharReader *read = charBuilder.newCharReader();
    Value root;
    Value test;
    String error;
    double sum = 0;
    double avg;

    vector<double> componentVal;
    vector<double> componentMaxVal;
    vector<double> componentArray;
    vector<int> maxList;
    double maxOfMax;
    Value maxcomp;
    vector<int> idArry;
    vector<int> idList;

    bool parseSuccess = read->parse(begin, end, &root, &error);
    delete read;

    if (parseSuccess)
    {
        for (Value::const_iterator outer = root.begin(); outer != root.end(); outer++)
        {
            for (Value::const_iterator inner = (*outer).begin(); inner != (*outer).end(); inner++)
            {
                if (inner.key() == "cost")
                {
                    sum = sum + (*inner).asDouble();
                    avg = sum / (root.size());
                }
                else if (inner.key() == "cost_components")
                {
                    for (size_t i = 0; i < (*inner).size(); i++)
                    {
                        componentVal.push_back((*inner)[i].asDouble());
                    }
                    double maxvalue = *max_element(componentVal.begin(), componentVal.end());
                    componentMaxVal.push_back(maxvalue);
                    maxOfMax = *max_element(componentMaxVal.begin(), componentMaxVal.end());
                }
                else{}
            }
        }

        for(Value::const_iterator itr = root.begin(); itr != root.end(); itr++){
            if((*itr)["cost"].asDouble() > 95){
                idArry.push_back((*itr)["id"].asInt());
            }
        }
        printValues(avg, maxOfMax, idArry, maxList);
    }

    parseTime = clock() - parseTime;

    cout <<"time to parse"<< parseTime << "\n";
    return parseSuccess;
}

int main()
{
    clock_t time;

    time = clock();
    ifstream inputTextFile;
    ofstream outputJsonFile;
    stringstream stringFile;
    OStream *josnOutput;

    StreamWriterBuilder streamBuilder;
    StreamWriter *josnWriter = streamBuilder.newStreamWriter();

    string output;
    string textFile;

    inputTextFile.open("M:\\Documents\\data\\medium.txt");
    textFile.assign(istreambuf_iterator<char>(inputTextFile), istreambuf_iterator<char>());

    outputJsonFile.open("textfile.json");
    outputJsonFile << "[" << textFile << "]";
    outputJsonFile.close();
    inputTextFile.close();

    inputTextFile.open("textfile.json");
    textFile.assign(istreambuf_iterator<char>(inputTextFile), istreambuf_iterator<char>());

    //function to parse json 

    bool parseSuccess = parseJson(textFile.c_str(), textFile.size() + textFile.c_str());

    time = clock() -time;


    cout << "time taken by main thread:" << time << "\n"; 

    return 0;

    
}
