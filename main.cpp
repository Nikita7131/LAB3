
#include <iostream>
#include "stack.h"

int main() {
    
    Stack st;
    
    std::cout << st.isEmpty() << std::endl;
    st.push(6);
    st.push(60);
    st.push(40);
    std::cout << st.isEmpty() << std::endl;
    
    st.show();
    st.multiPop(2);
    st.show();
    Stack st2;
    st2 = st;
    st2.show();
    
}