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
    int val;
    int* ptrValue = &value;
    int* ptrVal = &val;
    const char* name; //3
    //*name = valName;
    T(int v, const char* n) : value(v), name(n) {std::cout << "T constructor starts!" << std::endl;}//1
    ~T(){std::cout << "T destructor finish!" << std::endl;}
};

struct CheckPointer                                //4
{
    CheckPointer(){std::cout << "CheckPointer constructor starts!" << std::endl;}
    ~CheckPointer(){std::cout << "CheckPointer destructor finish!" << std::endl;}
    T* compare(T* addrTinst1, T* addrTinst2) //5
    {
        if ( ( addrTinst1 != nullptr ) && ( addrTinst2 != nullptr) )
        {
            if( addrTinst1->value < addrTinst2->value ) 
            {
            	std::cout << "\taddrTinst1->value:\t" << addrTinst1->value << std::endl;
                std::cout << "\taddrTinst1:\t\t" << addrTinst1 << std::endl;
            	std::cout << "\taddrTinst2->value:\t" << addrTinst2->value << std::endl;
                std::cout << "\taddrTinst2:\t\t" << addrTinst2 << std::endl;
                return addrTinst1;
            }
            
            if( addrTinst1->value > addrTinst2->value ) 
            {
            	std::cout << "\taddrTinst1->value:\t" << addrTinst1->value << std::endl;
                std::cout << "\taddrTinst1:\t\t" << addrTinst1 << std::endl;
            	std::cout << "\taddrTinst2->value:\t" << addrTinst2->value << std::endl;
                std::cout << "\taddrTinst2:\t\t" << addrTinst2 << std::endl;
                return addrTinst2;
        	}
        }   
        return nullptr;
    }
};

struct U
{
    U(){std::cout << "U constructor starts!" << std::endl;}
    ~U(){std::cout << "U destructor finish!" << std::endl;}
    float uVariable1 { 0.0f }, uVariable2 { 0.0f };
    float* ptrTouVariable1 = &uVariable1;
    float* ptrTouVariable2 = &uVariable2;
    
    float updateU(float* updatedValue)      //12
    {
        if( updatedValue != nullptr)
        {
            std::cout << "U's unit1 value: " << this->uVariable1 << std::endl;
            this->uVariable1 = *updatedValue;
            std::cout << "\t'updatedValue':\t\t" << updatedValue << std::endl;
            std::cout << "\t'*updatedValue':\t" << *updatedValue << std::endl;
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
    multiplyUVariables(){std::cout << "multiplyUVariables constructor starts!" << std::endl;}
    ~multiplyUVariables(){std::cout << "multiplyUVariables destructor finish!" << std::endl;}
    static float multiply(U* uInstance, float* newUpdatedValue)         //10
    {
        std::cout << "\n\t'U* uInstance':\t\t" << uInstance << std::endl;
        if(uInstance == nullptr || newUpdatedValue == nullptr)
        {
            std::cout << "Warning: function arguments are nullptr" << std::endl;
            return 0.0f;
        }
        std::cout << "U's uVariable1 value: " << uInstance->uVariable1 << std::endl;
        uInstance->uVariable1 = *newUpdatedValue;
        std::cout << "\t'*newUpdatedValue':\t" << newUpdatedValue << std::endl;
        std::cout << "\t'newUpdatedValue':\t" << *newUpdatedValue << std::endl;
        std::cout << "U's uVariable1 updated value: " << uInstance->uVariable1 << std::endl;

        while( std::abs(uInstance->uVariable2 - uInstance->uVariable1) > 0.001f )
        {
            if (uInstance->uVariable2 < uInstance->uVariable1)
            {
                std::cout << "\t'uInstance->uVariable1':\t" << uInstance->uVariable1 << std::endl;
                std::cout << "\t'uInstance->uVariable2':\t" << uInstance->uVariable2 << std::endl;
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

int main()
{
    T tInst1( 3, "T struct instance 1" );//value y name NO han sido declarados
    std::cout << "\t'tInst1.value':\t\t" << tInst1.value << std::endl;
    std::cout << "\t'tInst1.ptrValue':\t" << tInst1.ptrValue << std::endl;
    std::cout << "\t'tInst1.name':\t\t" <<tInst1.name << std::endl;
    //std::cout << tInst1.valName << std::endl;
    std::cout << "\t'&tInst1':\t\t" << &tInst1 << std::endl;
    T tInst2( 2, "T struct instance 2" );               //6
    std::cout << "\t'tInst2.value':\t\t" << tInst2.value << std::endl;
    std::cout << "\t'tInst2.ptrValue':\t" << tInst2.ptrValue << std::endl;
    std::cout << "\t'tInst2.name':\t\t" <<tInst2.name << std::endl;
    std::cout << "\t'&tInst2':\t\t" << &tInst2 << std::endl;
    
    CheckPointer f;                                           //7
    
    auto* smaller = f.compare( &tInst1, &tInst2); 
    std::cout << "\tsmaller:\t\t" << smaller << std::endl;

    if(smaller != nullptr) //8
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "The pointer in null! " << std::endl;
    }     //9
    
    U uInst1;
    std::cout << "\t'&uInst1':\t\t" << &uInst1 << std::endl;
    std::cout << "\t'uInst1.uVariable1':\t" << uInst1.uVariable1 << std::endl;
    std::cout << "\t'ptrTouVariable1':\t" << uInst1.ptrTouVariable1 << std::endl;
    //std::cout << "'&uVariable1':\t\t" << &uVariable1 << std::endl;
    std::cout << "\t'uInst1.uVariable2':\t" << uInst1.uVariable2 << std::endl;
    std::cout << "\t'ptrTouVariable2':\t" << uInst1.ptrTouVariable2 << std::endl;
    
    float updatedValue = 0.5f;
    std::cout << "\t'&updatedValue':\t" << &updatedValue << std::endl;
    std::cout << "\n[static func] uInst1's multiplied values: " << multiplyUVariables::multiply( &uInst1, &updatedValue ) << std::endl;                  //11
    
    U uInst2;
    std::cout << "\t'&uInst2':\t\t" << &uInst2 << std::endl;
    std::cout << "\n[member func] uInst2's multiplied values: " << uInst2.updateU( &updatedValue ) << std::endl;
    
}
