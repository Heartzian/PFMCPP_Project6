/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <#place holder#> placeholders with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
#include <string>
struct T
{
    int value; //2
    std::string name; //3
    T(int v, std::string n) : value(v), name(n) {}//1
};

struct CheckPointer                                //4
{
    T* compare(T* a, T* b) //5
    {
        if ( ( a != nullptr ) && ( b != nullptr) )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float uVariable1 { 0.0f }, uVariable2 { 0.0f };
    //float* ptrTouVariable1 = &uVariable1;
    //float* ptrTouVariable2 = &uVariable2;
    float updateU(float* updatedValue)      //12
    {
        if( updatedValue != nullptr)
        {
            std::cout << "U's unit1 value: " << this->uVariable1 << std::endl;
            this->uVariable1 = *updatedValue;
            std::cout << "U's unit1 updated value: " << this->uVariable1 << std::endl;
            while( std::abs(this->uVariable2 - this->uVariable1) > 0.001f )
            {
                if(this->uVariable2 < this->uVariable1)
                    this->uVariable2 += 0.1f;
                else
                    this->uVariable2 -= 0.1f;
            }
            std::cout << "U's unit2 updated value: " << this->uVariable2 << std::endl;
            return this->uVariable2 * this->uVariable1;
        }
        std::cout << "Warning: float updatedValue is nullptr!" << std::endl;
        return 0.0f;
    }
    
};

struct multiplyUVariables
{
    static float multiply(U* uInstance, float* newValue)         //10
    {
        if(uInstance == nullptr || newValue == nullptr)
        {
            std::cout << "Warning: function arguments are nullptr" << std::endl;
            return 0.0f;
        }
        std::cout << "U's uVariable1 value: " << uInstance->uVariable1 << std::endl;
        uInstance->uVariable1 = *newValue;
        std::cout << "U's uVariable1 updated value: " << uInstance->uVariable1 << std::endl;

        while( std::abs(uInstance->uVariable2 - uInstance->uVariable1) > 0.001f )
        {
            if (uInstance->uVariable2 < uInstance->uVariable1)
            {
                uInstance->uVariable2 += 0.1f;
                std::cout << "uVariable2: " << uInstance->uVariable2 << std::endl;
            }
            else
            {
                uInstance->uVariable2 -= 0.1f;
                std::cout << "uVariable2: " << uInstance->uVariable2 << std::endl;
            }
        }
        std::cout << "U's uVariable2 updated value: " << uInstance->uVariable2 << std::endl;
        return uInstance->uVariable2 * uInstance->uVariable1;
    }
}; 
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T tInst1( 1, "T struct instance 1" );               //6
    T tInst2( 2, "T struct instance 1" );               //6
    
    CheckPointer f;                                           //7
    
    auto* smaller = f.compare( &tInst1, &tInst2); 
    if(smaller != nullptr) //8
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "The pointer in null! " << std::endl;
    }     //9
    
    U uInst1;
    float updatedValue = 2.f;
    std::cout << "\n[static func] uInst1's multiplied values: " << multiplyUVariables::multiply( &uInst1, &updatedValue ) << std::endl;                  //11
    
    U uInst2;
    std::cout << "\n[member func] uInst2's multiplied values: " << uInst2.updateU( &updatedValue ) << std::endl;
}
