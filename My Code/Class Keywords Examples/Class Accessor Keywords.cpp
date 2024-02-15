/*
Exploring the protected accessor keyword in classes
*/
#include <iostream>
class Base{
public:
    Base(int pub, int prot, int priv) : pub_base(pub), prot_base(prot), priv_base(priv){}
    int pub_base;
    int getPrivate(){
        return priv_base;
    }
protected:
    int prot_base;
private:
    int priv_base;
};

class Derived : public Base{
public:
    Derived(int pub, int prot, int priv,int d_pub, int d_prot, int d_priv) //parameter order is important
    :Base(pub, prot, priv), pub_derived(d_pub), prot_derived(d_prot), priv_derived(d_priv)
    {
    }
    int pub_derived; // public member variable
    int getDerivProtected(){ // get the protected member variable
        return prot_derived;
    }
    int getDerivPrivate(){ // get the protected member variable
        return priv_derived;
    }    
    int getBaseProtected(){ // get the protected member variable from Base class
        //return Base::prot_base; // Also works - what is the difference?
        return prot_base; 
    }
    int getBasePrivate(){
        //return Base::getPrivate(); //Also works - what is the difference?
        return getPrivate();
    }
protected:
    int prot_derived;
private:
    int priv_derived;
};


int main()
{
    std::cout << "Hello\n";

    Derived d{4, 5, 6, 40, 50, 60};
    
    std::cout << "Derived public: " << d.pub_derived << std::endl;
    std::cout << "Derived protected: " << d.getDerivProtected() << std::endl;
    std::cout << "Derived private: " << d.getDerivPrivate() << std::endl;
    std::cout << "Derived Base public: " << d.pub_base << std::endl;
    std::cout << "Derived Base protected: " << d.getBaseProtected() << std::endl;
    std::cout << "Derived Base private: " << d.getBasePrivate() << std::endl;
    
    return 0;
}