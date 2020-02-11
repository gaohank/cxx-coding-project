#include "stack.h"
#include <string.h>

stack::stack()
{

}

void stack::init()
{
    top = 0;
    memset(space, 0, 1024);
}

bool stack::is_empty()
{
    return top == 0;
}

bool stack::is_full()
{
    return top == 1024;
}

char stack::pop()
{
    return space[--top];
}

void stack::push(char c)
{
    space[top++] = c;
}
