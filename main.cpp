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
    T(int v, const char* n) : value(v), name(n) {} //1
    int value;//2
    const char* name;//3
};

struct findBiggerInt                                //4
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
    float memberVariableA { 0 }, memberVariableB { 0 };
    float memberFuncUpdateMultiplyTwoFloats(const float& updatedValue)      //12
    {
        std::cout << "U's memberVariableA value: " << memberVariableA << std::endl;
        this->memberVariableA = updatedValue;
        std::cout << "U's <#name1#> updated value: " << memberVariableA << std::endl;
        while( std::abs(memberVariableB - memberVariableA) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            if(memberVariableA < memberVariableB)
            {
                memberVariableB -= 0.001f;
            }
            else
            {
               memberVariableB += 0.001f; 
            }
        }
        std::cout << "U's memberVariableB updated value: " << this->memberVariableB << std::endl;
        return memberVariableB * memberVariableA;
    }
};

struct StaticFuncUpdateMultiplyTwoFloats
{
    static float updateAndMultiplyStatic(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's memberVariableA value: " << that.memberVariableA << std::endl;
        that.memberVariableA = updatedValue;
        std::cout << "U's <#name1#> updated value: " << that.memberVariableA << std::endl;
        while( std::abs(that.memberVariableB - that.memberVariableA) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            if(that.memberVariableA < that.memberVariableB)
            {
                that.memberVariableB -= 0.001f;
            }
            else
            {
               that.memberVariableB += 0.001f; 
            }
        }
        std::cout << "U's memberVariableB updated value: " << that.memberVariableB << std::endl;
        return that.memberVariableB * that.memberVariableA;
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
    T a(6, "SuSu");                                             //6
    T b(8, "HuHu");                                             //6
    
    findBiggerInt f;                                            //7
    auto* smaller = f.compare(a, b);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "Function returned nullptr because input variables have the same value" << std::endl;
    } //9
    
    U FloatPairA;
    float updatedValue = 5.f;
    std::cout << "[static func] <#name3#>'s multiplied values: " << StaticFuncUpdateMultiplyTwoFloats::updateAndMultiplyStatic(FloatPairA, updatedValue) << std::endl;                  //11
    
    U FloatPairB;
    std::cout << "[member func] <#name4#>'s multiplied values: " << FloatPairB.memberFuncUpdateMultiplyTwoFloats( updatedValue ) << std::endl;
}
