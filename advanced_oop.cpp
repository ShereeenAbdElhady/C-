/*

- Inheritance: is one way that classes can relate to each other, 2 classes may have a parent-child
               relationship, the child inherits members from the parent

               - Inheritance -> Multi level, multiple  
               - Multi level: is term used for chained classes in an inheritance tree
                    -> O A parent
                    -> O B Child
                    -> O C Child ( Has all the content of the previous)
                    No limitation to the level but don't exceed 7 to avoid complexity
                - Multiple ( Child inherate directly from more than one parent)
                allows us to create a derived class from 2 different base classes.
                   O A            O B
                    ------ O C ----
                    > Multiple inheritance is tricky and may cause the diamond problem 
                    which occurs when a class inherits from 2 base classes, both of which
                    theselves inherit from the same abstarct class, a conflict can emerge

- Inherited Access Specifiers: Just as access specifiers (Public, Private, protected)   
                               define which class members users can access, the same access
                               modifiers also define which class members users of a derived
                               classes can access

       > Public Inheritance: The public & protected members of the base class listed after
                             the specifier keep their member access in the derived class.

       > Protected Inheritance: The public & protected members of the base class listed after
                                the specifier are protected members of the derived class.

       > Private Inheritance: The public & protected members of the base class lister after
                              the specifer are private members of the derived class.                                                                                      

- Composition: is an alternative to inheritance as a way to relate classes to each other
               it involves constructing classes from other classes.

- How to distinguish between composition & inheritance?
 Think about what an object can do rather that what it is
 Composition > cat has a head, has a tail
 Inheritance > cat is a mammel
 -> if a class needs only extend a small amount of functionality beyond what it is already offered
   by another class, it make sense to inherit from that other class
-> if a class needs to contain functionality from a variety of otherwise unrelated classes,
   it make sense to compose the class from those other classes.                 


- Friend keyword: > provides an alternative inheritance mechanism to derived classes
                  > grants access to the private members of a class

The main difference between classical inheritance and freind inheritance is that a friend class
can access private members of the base class which isn't the case for classical inheritance
in classical inheritance, a derived class can only access public and protected members of the base class                  

- Polymorphism: (assuming many forms)
               is a related concept that allows an interface to work with several different types
              --> overloading, overriding
                
                -Overloading: allows us to pass different arguments to the same function name
                              and have different implementation of that function that respond
                              to the different arguments.
                       -> Functions & operators
                       -> Same class
                       -> Same function name but different i/p arguments
                -Overriding
                       -> Functions only
                       -> different class by inherting a child
                       -> Same function name and same i/p arguments
               

- Operator overloading: allows us to assign our own logic to operators
                     - in order to overload an operator, use the operator keyword in the function signature
                     Complex operator + (const Complex& addend)
                     {
                       // logic to add complex numbers
                     }
                  
- Virtual functions: allows us to define an abstract class that can function as an interface
                     from which other classes can be derived.  
                     > polymorphic feature, these functions are declared and possibly defined in a base class
                     and can be overridden by derived class.  
                     > This approach declares an interface at the base level, but delegates the implementation
                     of the interface to the derived class.
                     > A pure virtual function is a virtual function that the base class
                       declares but doesn't define.

                     NB: Pure virtual function > virtual double Area() const = 0;
                         Virtual function      >  virtual double Area(); 
                     > Pure virtual function has the side effect of making it's class abstract
                     means that the class can't be instantiated but only classes that derived from
                     the abstract class and override the pure virtual function can be instantiated.   

- Function overriding occures when:
                      > A base class declares a virtual function
                      > A derived class overrides that virtual function by defining it's implementation
                      with an identical function signature ( same function name and same i/p arguments)          

- Function Hiding: A derived class hides a base class function, as opposed to overriding it
                   if the base class function is not specified to be virtual.    

- Generic Programming: is an example of polymorphism that genralizes the parameters of classes
                       and functions by using a C++ facility called templates.
                       You can build classes and functions that work with many different types of data.
                       and that way, you can reuse the same code in many different situations.
                       Ex: vector from std library, we can create a vector of ints, string, or some user defined classes.

- Templates: Templates are a tool for generic programming in C++, it allow us to specify a generic type      

- Deduction: Template deduction is when the compiler determines the type for a template automatically
             without us having to specify it.
             and we can do the same with the vector but use this command to compile
             use std = c++17 
             g++ -std=C++17 temp.cpp

- Class Template: can declare and implement generic attributes for use by generic methods
                 these templates can be very useful when building classes that will serve
                 multiple purposes.             
*/
#include <iostream>
#include <string>
#include <vector>
#include<math.h>
#include <cassert>
#include <sstream>
#include <ostream>

using std::cout;
using std::string;

#define PI 3.1459;

                                        /* Multi level Inheritance */
class Animal
{
       public:
       void Talk() const
       {
              cout << "Talk" << std::endl;
       }
};

// Class Human inherites from class Animal and can use all of it's members
// The public access specifier explains how class Human can access data and the methods from class Animal
class Human: public Animal
{
       public:

       void Talk(string content) 
       {
              cout << content << std::endl;
       }

       void Walk () const
       {
              cout << "walk" << std::endl;
       }

};

/* The Baby class itself can use Talk as it inherites from Human class
but Baby user (object) can't use it because of the private access modifier*/
class Baby : private Human
{
       public:

       void Cry ()
       {
              Talk("whaa");
       }
};

                                /* Inherited Access Specifiers */

class Vehicle
{
       public:
       int wheels = 0;
} ;                               

class Bicycle : protected Vehicle
{
       public:
       bool Kickstand = true;

       void Wheels (int w)
       {
              wheels = w;
       }
};

class Scooter: private Vehicle
{
       public:

       bool electric = false;

       void Wheels (int w)
       {
              wheels = w;
       }

};

                                 /* Multiple Inheritance */
class CarInher
{
       public:
       string Drive()
       {
              return "I'm driving";
       }

}; 

class Boat
{
       public:
       string Cruise()
       {
              return "I'm crusing";
       }
};
// Multiple Inheritance
class AmphibiousCar : public Boat, public CarInher
{

};
                                      /* Diamond Problem */
// class Vehilcle
// {
//        public:
//        virtual string Move() const  = 0;
// };  

// class Boat : Public Vehilcle
// {
//        public:
//        string Move() const{

//        }

// };   

// class Car : Public Vehilcle
// {
//        public:
//        string Move() const{
              
//        }

// }; 

// The problem is AmphibiousCar class inherits move() function from both boat and car class which going to conflict
// if the user called move() function, we don't know which one will be called
// class AmphibiousCar: public Car, Public Vehilcle
// {
     

// }; 
//                                        /* Composition */

class Wheel
{
       public:
       // default constructor and initializer list
       Wheel(): diameter(50)
       {

       }

       float diameter;
};

class Car
{
       public:
       // in the constructor we have a vector of 4 wheels
       Car(): wheels (4, Wheel())
       {

       }

       // car is composed of wheels, a car simply has wheels composed of wheels
       std::vector <Wheel> wheels;
};

struct LineSegment
{
       public:
       double Length;

};

// class Circle composed of a LineSegment that represents the circle's radius
class Circle
{
       public:
       Circle(LineSegment& radius);
       double Area();

       private:
       // reference
       LineSegment& radius_;

};

Circle::Circle(LineSegment& radius) : radius_(radius)
{

}

double Circle::Area()
{
       return pow(Circle::radius_.Length,2) * PI;
}

                                    /* Friend Keyword */

class Heart
{
       private:
       int rate {80};
       // to make the private members of class Heart accessible by class Human_
       friend class Human_;
};   

class Human_
{
       public:
       Heart heart;
       void Exercise() 
       {
              heart.rate = 150;
       }

       int HeartRate()
       {
              return heart.rate;
       }
};

                                  /* Overloading */
class Water
{

};

class Alcohol
{

};

class Coffee
{

};

class HumanNeeds
{
       public:
       string condition{"Happy"};

       void Drink (Water water)
       {
              condition = "hydarted";
       }

       void Drink (Alcohol alcohol)
       {
              condition = "drunk";
       }

       void Drink (Coffee coffee)
       {
              condition = "alert";
       }

};

                         /* operator overloading */
class Matrix
{
       public:
       Matrix (int rows, int cols): rows_(rows), cols_(cols), values_(rows * cols)
       {

       }

                   // overload parenthese operator to access the elements
       // overload parentheses operator for non const access
       int& operator() (int row,int col)
       {
              return values_[row * cols_ + col];
       }

       // overload parentheses operator for const access
       int operator() (int row, int col) const
       {
              return values_[row * cols_ + col];
       }
       // overload + operator for matrix addition
       //Prevents modification of the original matrices during addition
       Matrix operator + (const Matrix m) const
       {
              Matrix result(rows_, cols_);

             // Adds corresponding elements and stores the result in a new matrix.
              for (size_t i = 0; i < values_.size(); ++i) 
              {
                     result.values_[i] = values_[i] + m.values_[i];
              }
              return result;
       }

       // Function to display the matrix
       void display() const
       {
              for (int i = 0; i < rows_; ++i) 
              {
                     for (int j = 0; j < cols_; ++j) 
                     {
                            //Uses the overloaded () operator for element access.
                             std::cout << (*this)(i, j) << " ";
                     }
                     std::cout << std::endl;
              }
       }
       
       private:
       int rows_;
       int cols_;
       // used for storage
       std::vector<int> values_;

};

/* usecase: vector addition on a pair of points to add their x and y components
                the compiler won't recognize this because this data is user defined,
                so we will overload the + operator   */
class Point
{
       public:

       // public constructor uses initializer list
       Point (int x=0, int y =0) : x(x), y(y)
       {

       }

       // Define + operator overload
       Point operator + (const Point& addend)
       {
              Point sum;
              sum.x = x + addend.x;
              sum.y = y + addend.y;
              return sum;
       }

       int x,y;

};

                                /* Virtual functions */
/* We declared "Talk" to the pure virtual function that means that AnimalVirtual class
is purely abstract class and we are not able to create object of type AnimalVirtual.
it nearly serves as an interface for subsequent derived classes that will inherit from it */                                
class AnimalVirtual
{
       // zero means we are not going to define how animal talks
       virtual void Talk() const = 0;

};   

// Inherate HumanVirtual class from AnimalVirtual
class HumanVirtual : public AnimalVirtual
{
       public:

       // define the virtual function here
       void Talk () const
       {
              cout << " Hello" << std::endl;
       }

};

                                  /* Overriding */
class Shape
{
       public:
       // pure virtual functions, declared but not defined
       virtual double Area() const = 0;
       virtual double Perimeter() const = 0;
};

class Rectangle : public Shape
{
       public:
       Rectangle (double width, double height) : width_(width), height_(height)
       {

       }

       double Area() const override
       {
              return width_ * height_;
       }

       double Perimeter() const override
       {
              return 2 * (width_ + height_);
       }

       private:
       double width_, height_;

};

class CircleOverRide : public Shape
{
       public:
       CircleOverRide (double radius): radius_(radius)
       {

       }

       double Area() const override
       {
              // PI r square
              return pow(radius_,2) * PI;
       }

       double Perimeter() const override
       {
              return 2 * radius_ * PI;
       }

       private:
       double radius_;

};

                          /* Function hiding   */
class Cat
{
       public:
       string Talk() const
       {
              return string("meow");
       }

};

// when an object of type Lion calls Talk(), the object will run Lion.Talk() not Cat.Talk()
class Lion : public Cat
{
       public:
       string Talk() const
       {
              return string("Rear");
       }

};

                                 /* Templates */
// T is a generic type
template <typename T>  

T Max(T a, T b)        
{
       return a > b ? a:b;
}

/* - we use the keyword " template" to specify which function is generic, generic C code
   is the term for code that is independant of types
   - it is mandatory to put the " template <>" tag before the function signature
     to specify and mark that the declartion is generic.
   - in order to instantiate a templatized class, use a templatized constructor for
     ex, Sum <double> (20.0, 13.7 )*/
template <typename Type>
Type Sum ( Type a, Type b)
{
       return a + b;
}

// use a template to overload operator to average 2 numbers
template <typename T>
T Average (T a, T b)
{
       return (a+b) / 2;
}

// class template that maps a generic key to a generic value
template <typename KeyType, typename ValueType>
class Mapping
{
       public:
       // class consturctor and init it using initializer list
       Mapping (KeyType key, ValueType value) : Key(key), Value(value)
       {

       }

       string Print () const
       {
              std::ostringstream stream;

              stream << Key << ":" << Value;

              return stream.str();

       }

       KeyType Key;
       ValueType Value;

};

int main()
{

                              /* Inheritance example */
       Animal animal;
       animal.Talk();
       // error, class Animal has no member name Walk
       //animal.Walk();

       Human human;
       /* if we hadn't define another new Talk() function in Human class, 
       we would use the one which is defined in the Animal class */
       human.Talk("Hello");
       human.Walk();

       Baby baby;
       baby.Cry();

       /*error void Human::Talk().. is inaccessible within this context
       baby.Talk() */
      // baby.Talk("Hey");

      Vehicle vehicle;
      vehicle.wheels = 4;

      Bicycle bicycle;
      // can't access wheels member because of the protected access modifier
     // bicycle.wheels = 2;

      Scooter scooter;
      // can't access wheels member because of the private access modifier
      //scooter.wheels = 21;

      bicycle.Wheels(2);
      scooter.Wheels(1);

      /* So what is the difference between protected and private?
       lw 3mlt inheriate mn class Bicycle s3tha l inherted class hy2dr ywsl w access vehiecle brdo
       lakn lw 3mlt inheriate from scooter, s3tha msh h2dr access vehicle*/

                               /* Composition example  */
       Car car;
       //assert(car.wheels.size()> 1);

       LineSegment radius{3};
       Circle Circle(radius);
       //assert (int (Circle.Area() == 28));

                               /* Friend keyword example */
       Human_ hum;
       //80
       cout<< hum.HeartRate() << std::endl;

       hum .Exercise(); 
       //150
       cout<< hum.HeartRate() << std::endl;     

                                   /* Overloading example */        
       HumanNeeds david;
       cout << david.condition << std::endl;

       /* The compiler create a default constructor which we are using here
           and this creates an anonymous type of object, anonymous
           because we didn't gave a name to the object  */
       david.Drink(Water());    
       cout << david.condition << std::endl;    

       david.Drink(Alcohol());    
       cout << david.condition << std::endl;

       david.Drink(Coffee());    
       cout << david.condition << std::endl;

                        /* Operator overloading examples */

       //        int rows = 2, cols = 2;
//     Matrix mat1(rows, cols);
//     Matrix mat2(rows, cols);

       // create objects and initialize the class members using initializer list
       Matrix mat1(2,2), mat2(2,2);

       // Initialize matrices
       mat1(0, 0) = 1; mat1(0, 1) = 2;
       mat1(1, 0) = 3; mat1(1, 1) = 4;
       mat2(0, 0) = 5; mat2(0, 1) = 6;
       mat2(1, 0) = 7; mat2(1, 1) = 8;

       std::cout << "Matrix 1:\n";
       mat1.display();

       std::cout << "Matrix 2:\n";
       mat2.display();

      // Perform matrix addition
      Matrix result = mat1 + mat2;
      std::cout << "Resultant Matrix after addition:\n";
      result.display();


       /* creation of 2 objects of Point class  and intialize it's members using initializer list*/
       Point P1(10,5), P2 (2,4);

      // exmaple call to the operator +
       Point P3 = P1+ P2;

                             /* Virtual Functions example */
       HumanVirtual humvir;
       humvir.Talk();
        /* error, cannot declare variable 'animvir' to be of abstract type 'AnimalVirtual',
         because the following virtual functions are pure within 'AnimalVirtual */
       //AnimalVirtual animvir;

                          /* Functions overridding example */
       
       CircleOverRide cir(12);
       double CircleArea = cir.Area();
       //453.01
       cout << CircleArea << std::endl;

       Rectangle rectangle(10,6);
       double RectArea = rectangle.Area();
       //60
       cout << RectArea << std::endl;

                         /* Multiple Inheritance example */
       AmphibiousCar AmCar;
       Boat boat;
       CarInher carInher;
       cout << AmCar.Drive() << std::endl;     
       cout << AmCar.Cruise() << std::endl;   

                          /* Templates example */
       // int, double and string are template type
       /* same syntax for some of the containers in C++ (like vector) and this
       how containrs work as they use templates to create generic programming
       so that they can take many different types  */
       assert ( Max <int> (2,4) == 4);
       assert ( Max <double> (-1.0, -2.3) == -1.0);
       assert ( Max < char> ('a', 'b') == 'b');   

      /* The function expands to become
        double Sum (double a, double b)
        { 
        return a+ b;
        }  */
       cout << Sum <double> (20.0,13.7)  << std::endl;   
       
                             /* Deduction example */
       // the type is removed
       assert (Max(2,4) == 4); 

       // the type is removed
       std::vector v {1,2,3};
       assert (v.size() == 3);

       assert (Average(2.0,5.0) == 3.5);


       Mapping <std::string, int> mapping("age",20);
       // age:20
       cout << mapping.Print() << std::endl;


                

}
