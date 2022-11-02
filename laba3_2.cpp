#include <iostream>
using namespace std;

//class TV {
//public:
//    string m_company;
//
//    TV() {}
//
//    TV(string company) {
//        m_company = company;
//    }
//    int virtual Prodano() = 0;
//    void virtual Info() = 0;
//    virtual ~TV() {}
//
//   
//};
//
//class Samsung : public TV {
//protected:
//    double m_price;
//public:
//    Samsung(double price, string company) : TV(company) {
//        m_company=company;
//        m_price=price;
//    }
//    
//    int Prodano() override
//    {
//        return 35;
//    }
//    void Info() override{
//        cout << "Company: " << this->m_company << endl;
//        cout << "Price TV:  " << this->m_price << endl;
//    }
//    virtual ~Samsung() {}
//};
//
//class OLED: public Samsung{
//protected:
//    int m_diagonal;
//public:
//    OLED(string company, double price, int diagonal) : Samsung(price, company) {
//        m_diagonal=diagonal;
//    }
//    
//    int Prodano()override {
//        return 456;
//    }
//    void Info()override {
//        cout << "Company:" << this->m_company << endl;
//        cout << "Price TV:" << this->m_price << endl;
//        cout << "Diagonal TV: " << this->m_diagonal <<"''"<< endl;
//    }
//    virtual ~OLED() {}
//};
//
//
//
//class LG: public TV {
//protected:
//    string m_model;
//public:
//    LG(string company,string model) : TV(company) {
//        m_model=model;
//    }
//   
//    int Prodano()override {
//        return 68;
//    }
//    void Info() {
//        cout << "Company: " << this->m_company << endl;
//        cout << "Model: " << this->m_model<< endl;
//    }
//   virtual ~LG() {}
//};
//
//
//
//
//int main() {
//
//    TV** ts = new TV * [3];
//    ts[0] = new Samsung(2348.9,"Samsung");
//    ts[1] = new OLED("Samsung", 5678, 55);
//    ts[2] = new LG("LG", "Smart TV");
//
//    for (int i = 0; i < 3; i++)
//    {
//        ts[i]->Info();
//        cout << "Prodano:" << ts[i]->Prodano() <<"\n" << endl;
//        delete ts[i];
//    }
//    return 0;
//}

class TV {
public:
    string m_model;

    TV() {}

    TV(string model) {
        m_model = model;
    }

    ~TV() {}

    void GetTypeTV() {
        cout << "Model of TV is" << this->m_model << endl;
    }
};

class Expensive : public virtual TV {
protected:
    double m_price;
public:
    Expensive(double price, string model) : TV(model) {
        m_model = model;
        m_price = price;
    }
    ~Expensive() {}

    void GetModel() {
        cout << "price TV is" << this->m_price << endl;
    }
};

class OLED : public Expensive {
protected:
    int m_diagonal;
public:
    OLED(string model, double price, int diagonal) : Expensive(price, model) {
        m_diagonal = diagonal;
    }
    ~OLED() {}

    void GetNmaePlatform() {
        cout << "Диагональ TV: " << this->m_diagonal << endl;
    }
};

class Qualitative : public virtual TV {
protected:
    string m_producingCountry;
public:
    Qualitative(string model, string country) : TV(model) {
        m_model = model;
        m_producingCountry = country;
    }
    ~Qualitative() {}

    void GetPixel() {
        cout << "Страна производитель : " << this->m_producingCountry << endl;
    }
};

class LG : public Qualitative {
protected:
    string m_company;
public:
    LG(string company, string model, string country) : Qualitative(model, country) {
        m_company = company;
    }
    ~LG() {}

    void GetDefinition() {
        cout << "Компания производитель: " << this->m_company << endl;
    }
};


class LGOLED55A26LA : public OLED, public LG {
protected:
    int m_year;
public:
    LGOLED55A26LA(int year, string model, string country, string company, int diagonal, double price)
        :OLED(model, price, diagonal), LG(company, model, country) {
        m_year = year;
    }

    ~LGOLED55A26LA() {}

    void GetInfo() {
        cout << "Телевизор: " << this->m_company << endl;
        cout << "Модель телевизора: " << this->m_model << endl;
        cout << "Цена: " << this->m_price << "$" << endl;
        cout << "Диагональ: " << this->m_diagonal << " дюймов" << endl;
        cout << "Страна производитель: " << this->m_producingCountry << endl;
        cout << "Год выхода на рынок: " << this->m_year << " г." << endl;
    }
};

int main() {

    system("chcp 1251");
    system("cls");
    LGOLED55A26LA A(2022, "Smart TV", "Польша", "LG", 55, 1800);

    A.GetInfo();

    return 0;
}