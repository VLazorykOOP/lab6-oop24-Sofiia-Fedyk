#include "task1.h"

// ===== BASE CLASS A =====
A::A() : data_a(10) {
    std::cout << "A constructor called" << std::endl;
}

A::~A() {
    std::cout << "A destructor called" << std::endl;
}

void A::printA() const {
    std::cout << "A::data_a = " << data_a << std::endl;
}

// ===== NON-VIRTUAL INHERITANCE HIERARCHY =====

// First level of inheritance
B1::B1() : A(), data_b1(20) {
    std::cout << "B1 constructor called" << std::endl;
}

B1::~B1() {
    std::cout << "B1 destructor called" << std::endl;
}

void B1::printB1() const {
    std::cout << "B1::data_b1 = " << data_b1 << std::endl;
}

B2::B2() : A(), data_b2(30) {
    std::cout << "B2 constructor called" << std::endl;
}

B2::~B2() {
    std::cout << "B2 destructor called" << std::endl;
}

void B2::printB2() const {
    std::cout << "B2::data_b2 = " << data_b2 << std::endl;
}

B3::B3() : A(), data_b3(40) {
    std::cout << "B3 constructor called" << std::endl;
}

B3::~B3() {
    std::cout << "B3 destructor called" << std::endl;
}

void B3::printB3() const {
    std::cout << "B3::data_b3 = " << data_b3 << std::endl;
}

// Second level of inheritance
C1::C1() : B1(), data_c1(50) {
    std::cout << "C1 constructor called" << std::endl;
}

C1::~C1() {
    std::cout << "C1 destructor called" << std::endl;
}

void C1::printC1() const {
    std::cout << "C1::data_c1 = " << data_c1 << std::endl;
}

C2::C2() : B2(), data_c2(60) {
    std::cout << "C2 constructor called" << std::endl;
}

C2::~C2() {
    std::cout << "C2 destructor called" << std::endl;
}

void C2::printC2() const {
    std::cout << "C2::data_c2 = " << data_c2 << std::endl;
}

// Final class with diamond inheritance (non-virtual)
D_NonVirtual::D_NonVirtual() : C1(), C2(), B3(), data_d(70) {
    std::cout << "D_NonVirtual constructor called" << std::endl;
}

D_NonVirtual::~D_NonVirtual() {
    std::cout << "D_NonVirtual destructor called" << std::endl;
}

void D_NonVirtual::printD() const {
    std::cout << "D_NonVirtual::data_d = " << data_d << std::endl;
    std::cout << "Accessing A through C1 path: ";
    C1::printA();
    std::cout << "Accessing A through C2 path: ";
    C2::printA();
    std::cout << "Accessing A through B3 path: ";
    B3::printA();
}

void D_NonVirtual::printAllData() const {
    std::cout << "=== D_NonVirtual full data ===" << std::endl;
    printD();
    printC1();
    printC2();
    B3::printB3();
    B1::printB1();
    B2::printB2();
}

void D_NonVirtual::demonstrateInheritance() const {
    std::cout << "\n=== Non-Virtual Inheritance Demonstration ===" << std::endl;
    std::cout << "D_NonVirtual has multiple copies of class A (diamond problem)" << std::endl;
    printD();
    printC1();
    printC2();
    B3::printB3();
}

void D_NonVirtual::analyzeSizes() {
    std::cout << "=== Non-Virtual Inheritance Sizes ===" << std::endl;
    std::cout << "Size of A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of B1: " << sizeof(B1) << " bytes" << std::endl;
    std::cout << "Size of B2: " << sizeof(B2) << " bytes" << std::endl;
    std::cout << "Size of B3: " << sizeof(B3) << " bytes" << std::endl;
    std::cout << "Size of C1: " << sizeof(C1) << " bytes" << std::endl;
    std::cout << "Size of C2: " << sizeof(C2) << " bytes" << std::endl;
    std::cout << "Size of D_NonVirtual: " << sizeof(D_NonVirtual) << " bytes" << std::endl;
    std::cout << "(Contains 3 separate copies of A)" << std::endl;
}

// ===== VIRTUAL INHERITANCE HIERARCHY =====

// First level with virtual inheritance
VB1::VB1() : A(), data_vb1(20) {
    std::cout << "VB1 constructor called" << std::endl;
}

VB1::~VB1() {
    std::cout << "VB1 destructor called" << std::endl;
}

void VB1::printVB1() const {
    std::cout << "VB1::data_vb1 = " << data_vb1 << std::endl;
}

VB2::VB2() : A(), data_vb2(30) {
    std::cout << "VB2 constructor called" << std::endl;
}

VB2::~VB2() {
    std::cout << "VB2 destructor called" << std::endl;
}

void VB2::printVB2() const {
    std::cout << "VB2::data_vb2 = " << data_vb2 << std::endl;
}

VB3::VB3() : A(), data_vb3(40) {
    std::cout << "VB3 constructor called" << std::endl;
}

VB3::~VB3() {
    std::cout << "VB3 destructor called" << std::endl;
}

void VB3::printVB3() const {
    std::cout << "VB3::data_vb3 = " << data_vb3 << std::endl;
}

// Second level of inheritance
VC1::VC1() : A(), VB1(), data_vc1(50) {
    std::cout << "VC1 constructor called" << std::endl;
}

VC1::~VC1() {
    std::cout << "VC1 destructor called" << std::endl;
}

void VC1::printVC1() const {
    std::cout << "VC1::data_vc1 = " << data_vc1 << std::endl;
}

VC2::VC2() : A(), VB2(), data_vc2(60) {
    std::cout << "VC2 constructor called" << std::endl;
}

VC2::~VC2() {
    std::cout << "VC2 destructor called" << std::endl;
}

void VC2::printVC2() const {
    std::cout << "VC2::data_vc2 = " << data_vc2 << std::endl;
}

// Final class with virtual diamond inheritance
D_Virtual::D_Virtual() : A(), VC1(), VC2(), VB3(), data_vd(70) {
    std::cout << "D_Virtual constructor called" << std::endl;
}

D_Virtual::~D_Virtual() {
    std::cout << "D_Virtual destructor called" << std::endl;
}

void D_Virtual::printVD() const {
    std::cout << "D_Virtual::data_vd = " << data_vd << std::endl;
    std::cout << "Accessing shared A: ";
    printA(); // Only one A exists, no ambiguity
}

void D_Virtual::printAllData() const {
    std::cout << "=== D_Virtual full data ===" << std::endl;
    printVD();
    printVC1();
    printVC2();
    VB3::printVB3();
    VB1::printVB1();
    VB2::printVB2();
    printA(); // Single shared instance of A
}

void D_Virtual::demonstrateInheritance() const {
    std::cout << "\n=== Virtual Inheritance Demonstration ===" << std::endl;
    std::cout << "D_Virtual has a single shared copy of class A (solves diamond problem)" << std::endl;
    printVD();
    printVC1();
    printVC2();
    VB3::printVB3();
    printA(); // Only one A available
}

void D_Virtual::analyzeSizes() {
    std::cout << "=== Virtual Inheritance Sizes ===" << std::endl;
    std::cout << "Size of A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of VB1: " << sizeof(VB1) << " bytes" << std::endl;
    std::cout << "Size of VB2: " << sizeof(VB2) << " bytes" << std::endl;
    std::cout << "Size of VB3: " << sizeof(VB3) << " bytes" << std::endl;
    std::cout << "Size of VC1: " << sizeof(VC1) << " bytes" << std::endl;
    std::cout << "Size of VC2: " << sizeof(VC2) << " bytes" << std::endl;
    std::cout << "Size of D_Virtual: " << sizeof(D_Virtual) << " bytes" << std::endl;
    std::cout << "(Contains 1 shared copy of A + virtual table pointers)" << std::endl;
}

// ===== UTILITY FUNCTIONS FOR DEMONSTRATION =====

void compareInheritanceTypes() {
    std::cout << "\n=== INHERITANCE TYPE COMPARISON ===" << std::endl;
    
    // Analyze sizes
    D_NonVirtual::analyzeSizes();
    std::cout << std::endl;
    D_Virtual::analyzeSizes();
    
    // Memory usage comparison
    std::cout << "\n=== Memory Usage Analysis ===" << std::endl;
    std::cout << "Non-virtual inheritance: " << sizeof(D_NonVirtual) << " bytes" << std::endl;
    std::cout << "Virtual inheritance: " << sizeof(D_Virtual) << " bytes" << std::endl;
    
    int diff = sizeof(D_NonVirtual) - sizeof(D_Virtual);
    if (diff > 0) {
        std::cout << "Non-virtual uses " << diff << " more bytes (multiple A copies)" << std::endl;
    } else if (diff < 0) {
        std::cout << "Virtual uses " << (-diff) << " more bytes (vtable overhead)" << std::endl;
    } else {
        std::cout << "Both use the same amount of memory" << std::endl;
    }
}

void demonstrateBasicInheritance() {
    std::cout << "=== BASIC INHERITANCE DEMONSTRATION ===" << std::endl;
    
    std::cout << "\n1. Creating non-virtual inheritance object:" << std::endl;
    D_NonVirtual nonVirtual;
    nonVirtual.printD();
    
    std::cout << "\n2. Creating virtual inheritance object:" << std::endl;
    D_Virtual virtualObj;
    virtualObj.printVD();
    
    std::cout << "\n3. Size comparison:" << std::endl;
    compareInheritanceTypes();
}

void demonstrateConstructorDestructor() {
    std::cout << "\n=== CONSTRUCTOR/DESTRUCTOR DEMONSTRATION ===" << std::endl;
    
    std::cout << "\nConstructing D_NonVirtual object (watch call order):" << std::endl;
    {
        D_NonVirtual nonVirtual;
        nonVirtual.demonstrateInheritance();
    }
    std::cout << "D_NonVirtual destructed (destructors called in reverse order)" << std::endl;
    
    std::cout << "\nConstructing D_Virtual object (watch call order):" << std::endl;
    {
        D_Virtual virtualObj;
        virtualObj.demonstrateInheritance();
    }
    std::cout << "D_Virtual destructed (destructors called in reverse order)" << std::endl;
}

void demonstrateAdvancedFeatures() {
    std::cout << "\n=== ADVANCED FEATURES DEMONSTRATION ===" << std::endl;
    
    std::cout << "\n1. Complete data access - Non-virtual inheritance:" << std::endl;
    D_NonVirtual nonVirtual;
    nonVirtual.printAllData();
    
    std::cout << "\n2. Complete data access - Virtual inheritance:" << std::endl;
    D_Virtual virtualObj;
    virtualObj.printAllData();
    
    std::cout << "\n3. Polymorphism demonstration:" << std::endl;
    A* basePtr = static_cast<A*>(&virtualObj);
    std::cout << "Calling printA() through base pointer: ";
    basePtr->printA();
    
    std::cout << "\n4. Diamond problem resolution comparison:" << std::endl;
    std::cout << "Non-virtual: Must specify path to A (C1::printA(), C2::printA(), B3::printA())" << std::endl;
    std::cout << "Virtual: Direct access to A (printA() - no ambiguity)" << std::endl;
}

// Function to run all demonstrations
void runAllDemonstrations() {
    std::cout << "C++ INHERITANCE COMPLETE DEMONSTRATION" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    demonstrateBasicInheritance();
    demonstrateConstructorDestructor();
    demonstrateAdvancedFeatures();
    
    std::cout << "\n=== DEMONSTRATION COMPLETE ===" << std::endl;
}