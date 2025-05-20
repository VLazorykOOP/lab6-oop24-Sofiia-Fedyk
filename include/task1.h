#ifndef TASK1_H
#define TASK1_H

#include <iostream>

// ===== BASE CLASS A =====
class A {
public:
    A();
    virtual ~A();
    void printA() const;
    
protected:
    int data_a;
};

// ===== NON-VIRTUAL INHERITANCE HIERARCHY =====

// First level of inheritance
class B1 : public A {
public:
    B1();
    virtual ~B1();
    void printB1() const;
    
protected:
    int data_b1;
};

class B2 : public A {
public:
    B2();
    virtual ~B2();
    void printB2() const;
    
protected:
    int data_b2;
};

class B3 : public A {
public:
    B3();
    virtual ~B3();
    void printB3() const;
    
protected:
    int data_b3;
};

// Second level of inheritance
class C1 : public B1 {
public:
    C1();
    virtual ~C1();
    void printC1() const;
    
protected:
    int data_c1;
};

class C2 : public B2 {
public:
    C2();
    virtual ~C2();
    void printC2() const;
    
protected:
    int data_c2;
};

// Final class with diamond inheritance (non-virtual)
class D_NonVirtual : public C1, public C2, public B3 {
public:
    D_NonVirtual();
    virtual ~D_NonVirtual();
    
    void printD() const;
    void printAllData() const;
    void demonstrateInheritance() const;
    static void analyzeSizes();
    
protected:
    int data_d;
};

// ===== VIRTUAL INHERITANCE HIERARCHY =====

// First level with virtual inheritance
class VB1 : virtual public A {
public:
    VB1();
    virtual ~VB1();
    void printVB1() const;
    
protected:
    int data_vb1;
};

class VB2 : virtual public A {
public:
    VB2();
    virtual ~VB2();
    void printVB2() const;
    
protected:
    int data_vb2;
};

class VB3 : virtual public A {
public:
    VB3();
    virtual ~VB3();
    void printVB3() const;
    
protected:
    int data_vb3;
};

// Second level of inheritance
class VC1 : public VB1 {
public:
    VC1();
    virtual ~VC1();
    void printVC1() const;
    
protected:
    int data_vc1;
};

class VC2 : public VB2 {
public:
    VC2();
    virtual ~VC2();
    void printVC2() const;
    
protected:
    int data_vc2;
};

// Final class with virtual diamond inheritance
class D_Virtual : public VC1, public VC2, public VB3 {
public:
    D_Virtual();
    virtual ~D_Virtual();
    
    void printVD() const;
    void printAllData() const;
    void demonstrateInheritance() const;
    static void analyzeSizes();
    
protected:
    int data_vd;
};

// ===== UTILITY FUNCTIONS FOR DEMONSTRATION =====
void compareInheritanceTypes();
void demonstrateBasicInheritance();
void demonstrateConstructorDestructor();
void demonstrateAdvancedFeatures();
void runAllDemonstrations();

#endif // TASK1_H