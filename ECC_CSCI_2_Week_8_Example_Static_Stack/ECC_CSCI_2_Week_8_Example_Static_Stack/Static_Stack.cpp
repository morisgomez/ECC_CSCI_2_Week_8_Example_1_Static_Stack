/*
 Program Name: Static_Stack.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/02/2024
 Version Control: 4.0
 About: Week 8, CSCI 2, Example 1.
 Description:
    Intro to Static Stacks via arrays.
*/#include <iostream>

using namespace std;

//create IntStack:
class IntStack
{
private:
    int *stackArray; //does stackArray point to the address of the first element?
                    //would we need to derefrence each index to access value?
    int size;
    int top;

public:
//CONSTRUCTOR:
    IntStack(int sz)
    {
        //code for regular array: int name_array[sz];
        stackArray = new int[sz]; //initializes stack array with a set size of 'sz'.
        size = sz; //initializes the size of the stack array.
        top = -1; //initializes the top of the stack array to -1.
                  //-1 means empty stack array.
    } //end constructor.
    
//COPY CONSTRUCTOR:
    IntStack(const IntStack &obj) //& = reference, so changes to obj in func reflected in main.
    {
        //step 1: create stackArray.
        if(obj.size > 0)
        {
            stackArray = new int[obj.size];
        }
        else
        {
            stackArray = NULL; //points to NULL bc no size of new obj.
        }
        //step 2: copy size variable.
        size = obj.size;
        //step 3: copy the stack contents.
        for(int count = 0; count < size; count++)
        {
            stackArray[count] = obj.stackArray[count]; //obj3 = obj1.
        } //end for loop.
    } //end copy constructor.
    
    
//MEMBER FUNCTION #1: isFull().
    bool isFull() const //const = read-only func, so wont modify object it is called on.
                        //sort of like a getter.
    {
        if(top == size - 1) //if top is size - 1, it if full
                            //array size 5 needs to have top index as 4 to be full.
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isFull() function.
    
//MEMBER FUNCTION #2: isEmpty().
    bool isEmpty() const
    {
        if(top == -1) //if top is -1, list is empty: -1 is initialized during constructor.
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isEmpty() function.
    
//MEMBER FUNCTION #3: push().
    void push(int num)
    {
        if(isFull()) //if stack is full, cannot push bc arrays are fixed size.
        {
            cout << "Stack is full." << endl;
        }
        else //not full.
        {
            top = top + 1; //top becomes new index.
            stackArray[top] = num; //set that new index to num.
        }
    } //end push() function.
    
//MEMBER FUNCTION #4: pop().
    void pop(int &num)
    {
        if(isEmpty()) //empty, so cannot remove any elements.
        {
            cout << "Stack is empty." << endl;
        }
        else //has some indexes.
        {
            num = stackArray[top]; //assign top to num
            top = top - 1;
        }
    } //end pop() function.
    
//MEMBER FUNCTION #5: peek().
    int peek() const
    {
        if(isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        else
        {
            return stackArray[top];
        }
    } //end peek() function.

//MEMBER FUNCTION #5: display().
    void display()
    {
        int t = top; //last one in, first one out.
        //using while loop to traverse through stack array.
        while(t >= 0)
        {
            cout << stackArray[t] << endl;
            t = t - 1;
        } //end while loop.
    } //end display() function.
}; //end class IntStack.



//DRIVER for IntStack class via main function:
int main()
{
    //1)CREATE A STACK AND PUSH SOME VALUES:
    IntStack stackOne(5); //creates a Static Stack w/ a fixed size of 5 elements using constructor.
                //top = -1, size = 5.
    stackOne.push(7); //first one in, last one out. = BOTTOM of stack.
    stackOne.push(6);
    stackOne.push(4);
    stackOne.push(5);
    stackOne.push(2); //last one in, first one out = TOP of stack.
    stackOne.display();
    //BOTTOM [7, 6, 4, 5, 2] TOP
    //        0, 1, 2, 3, 4 =>indexes.
    /*
     TOP OF STACK:
     value at index 4 = [2]
     value at index 3 = [5]
     value at index 2 = [4]
     value at index 1 = [6]
     value at index 0 = [7]
     value at index -1 = [?] does index - 1 have a value?
     BOTTOM OF STACK:
     */
    
    //2)POP 1 VALUE FROM STACK:
    int x;
    stackOne.pop(x); //pops top index, must pass num as a variable.
    //top index should now be 3 with value 5 bc index 4 w/ value 2 was popped off.
    
    //3) PEEK TO SEE TOP VALUE:
    cout << "the top value is now: " << stackOne.peek() << endl; //peek returns the value at top index not indez itself. //should be 5
    stackOne.display();
    /*
     value at index 3 = [5]
     value at index 2 = [4]
     value at index 1 = [6]
     value at index 0 = [7]
     */
    
    //4) USE ISFULL AND IS EMPTY:
    cout << stackOne.isFull() << endl; //cout 0 (false) bc stack is not full.
    cout << stackOne.isEmpty() << endl; //cout 0 (false) bc stack is not empty.
    
    //5)USE COPY CONSTRUCTOR:
    IntStack stackTwo(5); //empty stack w/ fixed size of 5, so top is index -1?
    stackTwo = stackOne; //call copy constructor which copies stackOne into stackTwo.
    
    cout << "stack one: " << endl;
    stackOne.display();
    
    cout << "stack two: " << endl;
    stackTwo.display();
    
    
    return 0;
}
