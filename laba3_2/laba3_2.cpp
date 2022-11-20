#include <iostream>
using namespace std;

class TV {
public:
    string m_company;

    TV() {}

    TV(string company) {
        m_company = company;
    }
    int virtual Prodano() = 0;
    void virtual Info() = 0;
    virtual ~TV() {}

   
};

class Samsung : public TV {
protected:
    double m_price;
public:
    Samsung(double price, string company) : TV(company) {
        m_company=company;
        m_price=price;
    }
    
    int Prodano() override
    {
        return 35040;
    }
    void Info() override{
        cout << "Company: " << this->m_company << endl;
        cout << "Price TV:  " << this->m_price << endl;
    }
    virtual ~Samsung() {}
};

class OLED: public Samsung{
protected:
    int m_diagonal;
public:
    OLED(string company, double price, int diagonal) : Samsung(price, company) {
        m_diagonal=diagonal;
    }
    
    int Prodano()override {
        return 4563;
    }
    void Info()override {
        cout << "Company:" << this->m_company << endl;
        cout << "Price TV:" << this->m_price << endl;
        cout << "Diagonal TV: " << this->m_diagonal <<"''"<< endl;
    }
    virtual ~OLED() {}
};



class LG: public TV {
protected:
    string m_model;
public:
    LG(string company,string model) : TV(company) {
        m_model=model;
    }
   
    int Prodano()override {
        return 6800;
    }
    void Info() {
        cout << "Company: " << this->m_company << endl;
        cout << "Model: " << this->m_model<< endl;
    }
   virtual ~LG() {}
};




int main() {
    
    TV** tv = new TV * [3];
    tv[0] = new Samsung(2348.9,"Samsung");
    tv[1] = new OLED("Samsung", 5678, 55);
    tv[2] = new LG("LG", "Smart TV");

    for (int i = 0; i < 3; i++)
    {
        tv[i]->Info();
        cout << "Col-vo prodannyh TV: " << tv[i]->Prodano() <<"\n" << endl;
        delete tv[i];
    }
    return 0;
}

