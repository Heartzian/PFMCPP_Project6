/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    int value; //2
    const char* name; //3
    T(int v, const char* n) : value(v), name(n) {}//1
};

struct CheckPointer                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float uVariable1 { 0.0f }, uVariable2 { 0.0f };
    //float* ptrTouVariable1 = &uVariable1;
    //float* ptrTouVariable2 = &uVariable2;
    float updateU(float& updatedValue)      //12
    {
        std::cout << "U's unit1 value: " << this->uVariable1 << std::endl;
        this->uVariable1 = updatedValue;
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
    
};

struct multiplyUVariables
{
    static float multiply(U& uInstance, float& newValue)         //10
    {            
        std::cout << "U's uVariable1 value: " << uInstance.uVariable1 << std::endl;
        uInstance.uVariable1 = newValue;
        std::cout << "U's uVariable1 updated value: " << uInstance.uVariable1 << std::endl;

        while( std::abs(uInstance.uVariable2 - uInstance.uVariable1) > 0.001f )
        {
            if (uInstance.uVariable2 < uInstance.uVariable1)
            {
                uInstance.uVariable2 += 0.1f;
                std::cout << "uVariable2: " << uInstance.uVariable2 << std::endl;
            }
            else
            {
                uInstance.uVariable2 -= 0.1f;
                std::cout << "uVariable2: " << uInstance.uVariable2 << std::endl;
            }
        }
        std::cout << "U's uVariable2 updated value: " << uInstance.uVariable2 << std::endl;
        return uInstance.uVariable2 * uInstance.uVariable1;
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
    
    auto* smaller = f.compare( tInst1, tInst2); 
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
    std::cout << "\n[static func] uInst1's multiplied values: " << multiplyUVariables::multiply( uInst1, updatedValue ) << std::endl;                  //11
    
    U uInst2;
    std::cout << "\n[member func] uInst2's multiplied values: " << uInst2.updateU( updatedValue ) << std::endl;
}
