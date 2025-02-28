/* Some Termonoligies:-

- OOP: is a style of coding that collects related data (object attributes) and
      functions (object methods) together to form a single data structure called an object

- Class, object, instance

- structures: user defined data type to aggregate data relevant to their needs

- Members -> Attributes (data)
          -> Behaviors (functions/methods)

- Scope resolution > :: 
                   ex: Person::Move();     // call move function that is a member of person class     

-NameSpaces: allow programmers to group logically related variables and functions togther
             also helps to avoid conflicts between 2 variables that have the same name 
             in different parts of a program                   

- Access specifiers: by default, all the members of any structure are public
                    The issue is when the members are public so they could be assigned
                    with any value, even if it is not correct
                    but if we defined it as a private using the private access modifier,
                    we will not be able to change it unless we create a public function 
                    in the structure (mutator) to update it  

- Invariants: is a rule that limts the values of member variables                      

- Initializer lists: Initialize the value of member variables before the class constructor runs
                    and this initialization ensures that class members automatically initialized
                    when an instance of the class of the class is created.  
                     but we will lose the usage of the invariants and there won't be range checks for the members values  

                     - Constructor now uses an initializer list, the members will be initialized with the i/p arguments 
                    Car (string c, int n) : color (c), number (n)    
                     {
                     }     

- Initializing constant members > why we use initializer list??
                                - The compiler can optimize the initialization faster 
                                  from an initialization list than from within constructor   
                                - If you have a const class attribute, you can only initialize
                                  it using an initialization list, otherwise, you would violate
                                  the const keyword simply by initializing the member in
                                  the constructor. Also you will not be able to develop the mutator functions (invariants)  
                                - Also the input arguments which are passed by reference must use initializer list                                 

           >>>>>>>>>>>>>> Encapsulation and Abstraction <<<<<<<<<<<<<<<<
                           2 of core properties of OOP

- Encapsulation: we bundle related properties together in a single class and sometimes we protect
                 those properties from unauthorized or accidental modifications 
             -> Private, Public, protected
NB: > Public members can be changed directly by any user of the class (pbject)
    > private members can only be changed by the class itself not by the user (not by the object)
    > private members of a class are accessible only from within other member functions
    of the same class or from their "friends"
    > Protected: members are accessible from other member functions of the same class
                 or from their friends and also from members of their derived classes
    > By default all members in the class are private 
    > By default all members of any structure are public  

- Abstraction: users of our class only need to be familiar with the interface we provide
               they don't have to know how we store member data or implement member functions

Encapsulation and Abstraction are related because encapsulation groups releveant data togther in a class
while abstraction hides the details of how we work with this data, so we have to provide an interface to act with it   

- Accessor functions ( Getters)  
                  - Public member functions that allow users to access an object's data indirectly
                  - Const accessor shall only retrive data, shouldn't change the data stored in the object
                    and this is to protect the member data

- Mutator functions ( Setters )    
                  - Public member functions that allow us to change the state of an object
                  - Can apply the invariants logic when updating member data                           

- Constructor: we build and use them to instantiate objects in C++
    - Functions which construct objects for the class
    - All classes comes with a default constructor which takes no arguments
      but we can create our own as there is multiple ways to instantiate an object of the class
    - Method with the same class/struct name and case senstive
    - Called automatically once an object is created
    - Has no return data type even void
    - Can be overloaded
    - Every class should have a constructor
    - should initialize the members of the class

- Default constructor: The compiler will define a default constructor which accepts
                       no arguments for any class or structure that doesn't contain 
                       an explicitly defined constructor

- Destructor
    - ~ (telda) Method with the same class name and case senstive
    - Last behavior at object's lifetime
    - Removed automatically once you remove the object 
    ( Called automatically when the object's lifetime comes to an end)
    - Has no return data type even void
    - Can't be overloaded ( every class has only one destructor)

NB: The constructor will start up to initialize the local variables and when you finish
    the destructor will be coordinated to clean up all of this.    

- Assocaition -> weak  (ex Desk and room)
                strong ( ex wall and room)
something shall exist to perform the correct functionality

- Instance member ( Non static member) -> l members l 3dya l ay object

- Static member > 
                - members related to the class not the object exist before the instance, 
                instance can call the static but the static can't

                - class members can be declared static which means that the member
                  belongs to the entire class, instead of belonging to a specific class instance

                - static member is created only once and then shared by all instances (objects)
                  of the class, that means that if the static member changed either by a user
                  of the class or within a member function of the class itself, then all
                  members of the class will see that change the next time they access this static member

- Static methods >
                 - static member functions are instance independant, they belong to the class
                 not to any particular instance of the class

                 - method invoke a static member function without ever creating an instance of the class                  

- Dynamic binding ( using virtual function)

- Abstract method ( pure virtual function) > is a method without body
Any class has one abstract method or more it converts to abstract class

- Scaling up:
        CP -> IncrementDistance();
        (* CP).IncrementDistance();
        
- This pointer: when working with classes it is often helpful to be able to refer to
                the current class instance or object and it is possible to do so
                usinig this pointer which points to the current class instance 


 */

#include <iostream>
#include <string>

using std::cout;
using std::string;

                                          /* Classes */
class Car
{
    public:

    // method to print data
    void PrintCarData ()
    {
        cout << " The distance that the" << color << "car"<< number << "has travelled is " << distance << std::endl;

    }

    // method to increment distance
    void IncremementDistance()
    {
        distance++;
    }

    // class object attributes
    std::string color;
    int distance =0;
    int number ;

};

   /* Class and this pointer */
// class Car
// {
//     public:

//     // method to print data
//     void PrintCarData ()
//     {
//         cout << " The distance that the" << this -> color << "car"<< this -> number << "has travelled is " <<
//          this -> distance << std::endl;

//     }

//     // method to increment distance
//     void IncremementDistance()
//     {
//        this ->  distance++;
//     }

//     // class object attributes
//     string color;
//     int distance =0;
//     int number ;

// };


/* Constructor for Car class
   - case sensitive, same class name
   - has no return , even void
   - called automatically once an object is created */
// Car (string c, int n)
// {
//     color = c;
//     number = n;

// }

/* Inheritance: it is possible for a class to use methods and attributes from another class
                for ex. if you want to make a "sedan" class with additional attributes or methods
                not found in the generic "Car" class, you could create a sedan class that inherited from the car.
           NBs: - when the class methods are defined outside the class, :: must be used
                  to indicate which class the method belongs to void Car :: PrintCarData
                  This prevents any compiler issues if there are 2 classes with methods that have the same name

                  
                   */


class Sedan : public Car 
{
    // sedan class declarations and defintions
};              


class ClassDate
{
    public:

    // Constructor declation, as we can define the constructor inside or outside the class
    ClassDate(int d, int m, int y);

   // Constructor inside class
    // ClassDate ( int d, int m, int y)
    // {
    //     ClassDay (d);

    //     ClassMonth (m);

    //     ClassYear (y);
    // }

    // This function is const, not going to change the data stored in an object of the class
    int ClassDay () const
    {
        return day_;
    }

    int ClassMonth () const
    {
        return month_;
    }

    int ClassYear () const
    {
        return year_;
    }

    /* Invaraints  */
    void ClassDay (int d)
    {
        if ( d>= 1 && d <= 31)
        {
            day_ = d;
        }
    }

    void ClassMonth (int m)
    {
        if (m >= 1 && m <= 12)
        {
            month_ = m;
        }
    }

    void ClassYear (int y)
    {
        year_ = y;
    }


    private:
    int day_{1};
    int month_{1};
    int year_{0};

};

/* constructor outside Date class 
we will use the scope resolution to connect the constructor to the class */
// ClassDate::ClassDate ( int d, int m, int y)
// {
//     ClassDay (d);

//     ClassMonth (m);

//     ClassYear (y);
// }

/* constructor outside Date class 
we will use the scope resolution to connect the constructor to the class
and uses the initializer list  */
ClassDate::ClassDate ( int d, int m, int y): day_(d), month_(m), year_(y)
{

}
                   /* Structures */
struct Date
{
    public:

    // accessor (acts as a getter to update the private members)
    int Day() 
    { 
        return day;
    }

    // mutator (acts as a setter to update the private members)
    void Day (int d)
    {
        if (d>1)
        {
            day = d;
        }
    }
    // members' initialization from within the struct definition 
    int month{1};
    int year{0};

    private:
    int day {1};

}; 

                              /*         NameSpaces       */
namespace English
{
    void Hello () 
    {
        cout << "Hello" << std::endl;
    }
}

namespace Spanish
{
    void Hello () 
    {
        cout << "Hola" << std::endl;
    }
}  

class sphere
{
    private:
    static float const Pi;
};

float const sphere::Pi{3.14159};

// static float const Pi {3.14159};
// static float constexpr Pi {3.14159};
int main ()
{
                                  /* Class's App */
    // create class instances for each car
    Car car1, car2, car3;

    /* The main function doesn't seem such more organized as the code still sets the attributes
    for each car after the car has been created, so we will use constructor to fix this */
    car1.color = "green";
    car2.color = "red";
    car3.color = "blue";
    car1.number = 1;
    car2.number = 2;
    car3.number = 3;

    // Equal to
    // Car car1 = Car ("green",1);
    // Car car2 = Car ("red",2);
    // Car car3 = Car ("blue",3);

    car1.IncremementDistance();

    car1.PrintCarData();
    car2.PrintCarData();
    car3.PrintCarData();

                              /* Struct's App */
    Date date;

    date.Day(-7);
    // _ASSERT(date.Day == -7);
    // _ASSERT(date.month == 1);
    // _ASSERT(date.year == 0 );

    std::cout << date.Day() << "/" << date.month << "/" << date.year << std::endl;   

    English::Hello();
    Spanish::Hello();   

    /* Initializer list App */
    // instance creation
    ClassDate Obj(-2,1000,1981);  

    cout << Obj.ClassDay() << std::endl;             
}