#include <iostream>
#include <math.h>

class Polynomial {
public:
    struct Node {
        int coef;
        int exp;
        Node* link;
        Node(int c=0, int e=0, Node* l=nullptr): coef(c), exp(e), link(l) {}
    };
    
    friend void Polynomial_Init();

    Polynomial();
    Polynomial(const Polynomial& a);
    const Polynomial& operator=(const Polynomial& a);
    ~Polynomial();

    friend std::istream& operator>>(std::istream& in, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);

    Polynomial operator+(const Polynomial& p) const;
    Polynomial operator-(const Polynomial& p) const;
    Polynomial operator*(const Polynomial& p) const;

    float Evaluate(float x) const;

private:
    Node* header;
    Node* end;

    static Node* available;

    static Node* getNode(int coef, int exp);
    static void freeNode(Node* p);

    void insertOrCombine(int coef, int exp);

    void releaseAll();
};

Polynomial::Node* Polynomial::available = nullptr;

Polynomial::Polynomial(){
    header = new Node;
    header->link = header;
    end = header;
}

Polynomial::Polynomial(const Polynomial& a){
    header = new Node;
    header->link = header;
    end = header;                   // copy 之前完成construct
    
    Node* current = a.header->link;
    while(current!= a.header){
        Node* new_node = getNode(current->coef, current->exp);
        new_node->link = header;    // 加入 llist
        end->link = new_node;       // 完善循環
        end = end->link;            // end 跟隨
        current = current->link;
    }
}

const Polynomial& Polynomial::operator=(const Polynomial& a){
    if (this == &a) return *this;

    releaseAll();
    
    Node* current = a.header->link; // 邏輯同copy
    while (current != a.header) {
        Node* new_node = getNode(current->coef, current->exp);
        new_node->link = header;   
        end->link = new_node;      
        end = new_node;            
        current = current->link;
    }
    
    return *this;
}


Polynomial::~Polynomial(){
    releaseAll();
    delete header;
    header = nullptr;
    end = nullptr;
}

std::istream& operator>>(std::istream& in, Polynomial& p){
    int coef, exp, segments;
    std::cout << "請輸入欲輸入項數 : ";
    in >> segments;
    while(segments--){
        std::cout << "請輸入係數 : ";
        in >> coef;
        std::cout << "請輸入指數值 : ";
        in >> exp;
        p.insertOrCombine(coef, exp);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    Polynomial::Node* current = p.header->link;
    bool first = true;
    while (current != p.header) {
        if (current->coef != 0) {
            if (!first && current->coef > 0) {
                out << "+";
            }
            out << current->coef << "x^" << current->exp;
            first = false;
        }
        current = current->link;
    }
    return out;
}

Polynomial Polynomial::operator+(const Polynomial& p) const {
    Polynomial result = Polynomial(*this);
    Node* current = p.header->link;

    while (current != p.header) {
        result.insertOrCombine(current->coef, current->exp);
        current = current->link;
    }
    
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& p) const {
    Polynomial result = Polynomial(*this);
    Node* current = p.header->link;

    while (current != p.header) {
        result.insertOrCombine(current->coef*-1, current->exp);
        current = current->link;
    }
    
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& p) const {
    Polynomial result;
    Node* here = header->link;
    Node* there = p.header->link;
    
    while(here!=header){
        while(there!=p.header){
            result.insertOrCombine(here->coef*there->coef,here->exp+there->exp);
            there = there->link;
        }
        there = p.header->link;
        here = here->link;
    }
    return result;
}

float Polynomial::Evaluate(float x) const {
    float total=0;
    Node* current = header->link;
    while(current!=header){
        total+=current->coef*pow(x, current->exp);
        current = current->link;
    }
    return total;
}

Polynomial::Node* Polynomial::getNode(int coef, int exp){
    Polynomial::Node* Node_for_use;
    if(available!=nullptr){
        Node_for_use = available;
        available = available->link;
    }else{
        Node_for_use = new Node;
    }
    Node_for_use->coef = coef;
    Node_for_use->exp = exp;
    Node_for_use->link = nullptr;
    return Node_for_use;
}

void Polynomial::freeNode(Node* p){
    p->link = available;
    available = p;
}

void Polynomial::insertOrCombine(int coef, int exp){
    if(coef == 0)
        return;
    Node* current=header->link;
    while(current!=header){
        if(exp == current->exp){
            current->coef+=coef;
            return;
        }
        current = current->link;
    }
    current = getNode(coef,exp);
    end->link=current; 
    current->link = header;
    end = current;
    return;
}

void Polynomial::releaseAll(){
    end->link = Polynomial::available;  // 把整個串列移置 available
    available = header->link;
    header->link = header;  // 重制環狀串列
    end = header;
}

int main(){
    int x;
    Polynomial a,b;
    std::cout << "輸入 A :\n";
    std::cin >> a;
    std::cout << "輸入 B :\n";
    std::cin >> b;
    std::cout << "\nA + B = " << a+b << "\nA - B = " << a-b << "\nA * B = " << a*b << "\n請輸入x";
    std::cin >> x;
    std::cout << "A(x) = " << a.Evaluate(x);
}
