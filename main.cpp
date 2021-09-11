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
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(int v, const char* name);   //1

    int value; //2
    std::string name;//3
};

T::T(int v, const char* constructorName) :
value(v),
name(constructorName)
{}

struct CompareObjects                                //4
{
    T* compare(T* a, T* b) //5
    {
        if ( a != nullptr || b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }       
        return nullptr;
    }
};

struct U
{
    float uValue1 { 0 }, uValue2 { 0 };
    float reduceDistanceMember(float* updatedValue)
    {
        if (updatedValue == nullptr)
        {
            std::cout << "Your pointer is not valid!" << std::endl;
            return 0;
        }
        std::cout << std::endl;
        std::cout << "U's uValue1 value: " << this->uValue1 << std::endl;
        this->uValue1 = *updatedValue;
        std::cout << "U's uValue1 updated value: " << this->uValue1 << std::endl;
        std::cout << "U's uValue2 initial value: " << this->uValue2 << std::endl;
        while( std::abs(this->uValue2 - this->uValue1) > 0.001f )
        {
            this->uValue2 += 0.0001f;
        }
        std::cout << "U's uValue2 updated value: " << this->uValue2 << std::endl;
        return this->uValue2 * this->uValue1;
    }      //12
    
};

struct staticStruct
{
    static float reduceDistance(U* that, float* updatedValue)        //10
    {
        if (that == nullptr || updatedValue == nullptr)
        {
            std::cout << "Your pointer is not valid!" << std::endl;
            return 0;
        }

        std::cout << std::endl;
        std::cout << "U's uValue1 value: " << that->uValue1 << std::endl;
        that->uValue1 = *updatedValue;
        std::cout << "U's uValue1 updated value: " << that->uValue1 << std::endl;
        std::cout << "U's uValue2 initial value: " << that->uValue2 << std::endl;
        while( std::abs(that->uValue2 - that->uValue1) > 0.001f )
        {
            // 
            // write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            // 
            that->uValue2 += 0.0001f;
        }
        std::cout << "U's uValue2 updated value: " << that->uValue2 << std::endl;
        return that->uValue2 * that->uValue1;
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
    T t1( 10, "Terminator1");                                             //6
    T t2( 20, "Terminator2");              
                              
    CompareObjects f;                                            //7
    auto* smaller = f.compare(&t1 , &t2);      
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is " <<  smaller->name << std::endl; //9
    }                                                                  //8
    else
    {
        std::cout << "Invalid Pointer or equal value" << std::endl;
    }
    
    U instanceOfU;
    float updatedValue = 5.f;
    
    std::cout << "[static func] instanceOfU's multiplied values: " << staticStruct::reduceDistance( &instanceOfU , &updatedValue) << std::endl;                  //11
    
    U anotherInstanceOfU;
    std::cout << "[member func] anotherInstanceOfU's multiplied values: " << anotherInstanceOfU.reduceDistanceMember( &updatedValue) << std::endl;
}

        
        
        
        
        
        
        
