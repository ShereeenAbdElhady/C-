/* Primitive variable types
integers, strings, float

 - standard library types > std::string

vector : is the simplist and the default data type in C++ and one of C++ container type
        it is a linear sequence of contiguously allocated memory 
        -> 1D vector: are a sequence of elements of single type and have usefull
                      methods for getting the size, testing if the vector is empty
                      and adding elements to the vector
        -> 2D vector: There is no built in way to print vectors in C++ using cout
                      but we will write out own function to do so 
                      
Auto keyword: compiler can determine the variable type based on the value
              being assigned 
              
- For loop with a container 

- Data  input:-
(reading data from a file 4 steps)
    -> Create an File input stream object
    by creating input stream object (std::ifstream) and this object
    can be used also as a boolean to check if the stream has been
    created successfully > true
    and if there were an error opening the file or creating the stream
    then > false
    
    -> Reading data from the stream 
    
- Processing string: To process each line and store the data, istringstream
                     from <sstream> header file and also using 
                     the extraction operator (>>) this operator will read
                     until the white space is reached or until the stream fails

- Define your own type with Enum: C++ custom type has values limited to
                                 a specific range                     
                       
- Pass by reference vs Pass by value:
                    > Pass by reference: function operates on the original data itself
                    > Pass by value: function operates on a copy of the data
                    
- Constants
          > Const: promise not to change this value
          > Const Expr: to be evaluated at complie time  
          
- Array: Is a C++ container much like a vector, althoug without the ability
         to change size after it's initialization
         
- Writing Multiple files progams:
      > g++ -c file.cpp ( produce file.o)          
      > g++ file.o ( covert it into the executable)  
      > For multiple files 
        g++ -c *.cpp
        g++ *.o
        ./a.out
      > If you want to recompile only the changed file and use the existing object files
        g++ -c file.cpp
        g++ *.o
        ./a.out         
        
- References: is anither name given to an existing variable 

- Pointers: C++ pointer is a variable that stores the memory address of an object
            in your program
            
 NB: & > If it appears on the left side of an equation, it means that the variable
         is declared as a reference int &f =1;
        > If it appears on the right side of an equation or before a previously defined variable
          Then is is used to return a memory address cout << &f << std::endl                  */
#include <iostream>
#include <vector>
#include <numeric>
/* Step1: Header which provides the file streaming classes*/
#include <fstream>
#include <string>
/* to use istringstream  to process each line and store the data*/
#include <sstream>

using std::vector;
using std::cout;
using std::string;
using std::istringstream;
using std::ifstream ;

/* access by reference instead of copy */
int Addition (const vector <int> &v)
{
    int sum =0;

    for (int i=0; i<v.size(); ++i)
    {
        sum += v[i];
    }

   /* Another soultion */
    // int sum =0;

    // for (auto i=v.begin() ; i != v.end(); ++i)
    // {
    //     sum += *i;
    // }

    /* Another solution, accumulate from zero  */
    //return std::accumulate(v.begin(), v.end(),0);


   /* Another solution*/

//    int sum =0;

//    for (int i:v)
//    {
//     sum += i;
//    }
    return sum;
}

// Function to process a string and save it in a vector and return it
vector <int> ParseLine (string MyString)
{
    istringstream MyStream(MyString);

    char c;
    int n;
    vector <int> v;

    while (MyStream >> n >> c)
    {
        v.push_back(n);
    }

    return v;
}

/* function to read board file and process each line using the ParseLine function, 
then finally, put the output of the file in a 2D vector  */
vector <vector <int>> ReadBoardFile (string path)
{
    ifstream MyFile ("files/file.board");

    vector < vector <int>> board{};

    if (MyFile)
    {
        string line;

        while (getline(MyFile,line))
        {
            vector <int> row = ParseLine(line);
            board.push_back(row);
        }

    }
  return board;
}

// Pass by value function example
int MultiplyByTwoValue (int i)
{
    i = 2 * i;
    return i;
}

// Pass by reference function example, (i) is another name for whatever variable that is passed to the function
int MultiplyByTwoReference (int &i)
{
    i = 2 * i;
    return i;
}

int* Addone(int &j)
{
    j++;
    return &j;
}
int main ()
{
    /* declaration and initialization */
    int a=9; 
    cout << a << std::endl;

    std::string b;
    b = " Here is a string";
    cout << b<< std::endl;

    auto i=5;

    /* 3 ways of declaring and initializing 1D vectors */
    vector <int> v1 {0,1,2};
    vector <int> v2 = {3,4,5};
    vector <int> v3;
    v3 ={6};

     cout << v1[0] << std::endl;

    /* 2D vectors */
    vector < vector <int>> v {{1,2,3}, {3,4,5}};

     /* Getting vector's length */
    cout << v.size()<< std::endl;

   /* size of one of the inner vectors */
    cout << v[0].size() << std::endl;

    for (int i:v1)
    {
        cout << i<< " " <<std::endl;
        //cout << std::endl;
    }

// add int to the back of the vector using vector push,
//adding data to a vector
    v1.push_back(4);

    for (int i:v1)
    {
        cout << i<< " " <<std::endl;
        //cout << std::endl;
    }
    

    // set vector b to each inner vector of double vector v
    for (auto b:v)
    {
        for (int x:b)
        {
            cout << x << " ";
        }
        cout << std::endl;
    }

  cout << Addition(v1) <<std::endl; 

   /* Step2: New input stream object can be declared and 
   initialized using file path */
    std::ifstream my_file;
    my_file.open("files/file.board");
    /*Or*/
   // std::ifstream my_file (path);

   /* Step3: check if the stream has been created successfully */
  if (my_file)
  {
    std:: cout <<" The file stream has been created"<<std::endl;

    std::string line;

  /* Step4: loop accross the line in the file and read the lines
  of the input stream using getline function  */
    while (getline (my_file, line))
    {
        cout << line <<std::endl;
    }
  }

   /* Define a string */
   string c("199 2 2");
   /* To process each line and store the data */
   istringstream my_stream(c);
   int n;
   /*  the extraction operator (>>) this operator will read
    until the white space is reached or until the stream fails*/
   my_stream >> n;

   cout << n << std::endl;



   string s("123");
   istringstream mystream(s);
   int m;
/* istringstream object is used as a boolean to determine if the last
extraction operation failed and this happens if there wasn't any more of the string stream
for ex if the stream has more characters, you are able to stream again */
//    while (mystream)
//    {
//     mystream >> m;
//     if (mystream)
//     {
//         cout << " successfull:"<< m << "\n";
//     }
//     else
//     {
//         cout << " failed "<< "\n";
//     }
//    }

   /* Another solution */

/* this expression could be used as a boolean since the >> operator writes the stream
to the varaible on the right and returns the object */
   while (mystream >> m)
   {
    /* code */
    cout << " successfull:"<< m <<"\n";
   }
    cout << " failed "<< "\n";

    /* Strings with mixed tyypes */
    string q("10,12,13");

    istringstream stream(q);
    char k;
    int x;

// l 13 msh hatetl3 3shan mfesh char tany b3dha fl condition hi fail
    while (stream >>x>>k)
    {
        cout << " successfull:" << x << " " << k<< std::endl;
    }

    cout << "Failed" << std::endl;

    vector < vector <int>> board;

    board = ReadBoardFile ("files/file.board");

    //PrintBoard (board);

/* Create enum color with fixed values, color is the class name, Scoped Enum
it is possible to omit class and thus create Unscoped Enum */ 
   enum class color { white, black, blue, red};

// Create a color variable and set it to blue
   color my_color = color::blue;

   if (my_color == color::red)
   {
    cout << " Ok" << std::endl;
   }
   else 
   {
    cout << " NOk" << std::endl;
   }

// Pass by value logic, output is 5 10 5
   int l =5;
   cout << l << std::endl;
   int j = MultiplyByTwoValue (l);
   cout << j << std::endl;
   cout << l << std::endl;

// Pass by reference logic, output is 5 10 10
   int g = 5;
   cout << g << std::endl;
   int r = MultiplyByTwoReference (g);
   cout << g << std::endl;
   cout << r << std::endl;

   int P;

   std::cin >> P;
   
   // W can be evaluated only at runtime but I promise not to change it after it's initialization
   const int W = P * 2;

  // S is constant but can be evaluated at compile time
   constexpr int S =3;

   cout << W << std::endl;
   cout << S << std::endl;

                                     /* References */

    // h =1
    int h=1;
    // f =1
    int &f = h;   

    h =5 ;
    // h =5
    cout << h << std::endl;   
    // f =5
    cout << f << std::endl;

    f = 7;
    // h =7
    cout << h << std::endl;   
    // f =7
    cout << f << std::endl;
    /* Pointers */
   vector <int> vv {1,2,3};
   vector <int> *ptr_vv = &vv;
   // 1
   cout << (*ptr_vv)[0] << std::endl;

}


