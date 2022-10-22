#include <iostream>
using namespace std;

class TV {
public:
    string m_typeTV;

    TV() {}

    TV(string typeTV) {
        m_typeTV = typeTV;
    }

    ~TV() {}

    void GetTypeTV() {
        cout << "Type of TV is" << this->m_typeTV << endl;
    }
};

class Function : public virtual TV {
protected:
    string m_model;
public:
    Function(string typeTV, string model) : TV(typeTV) {
        m_model=model;
        m_typeTV=typeTV;
    }
    ~Function() {}

    void GetModel() {
        cout << "Model TV is" << this->m_model << endl;
    }
};

class Platform : public Function{
protected:
    string m_namePlatform;
public:
    Platform(string typeTV, string model, string namePlatform) : Function(typeTV, model) {
        m_namePlatform=namePlatform;
    }
    ~Platform() {}

    void GetNmaePlatform() {
        cout << "Платформа TV: " << this->m_namePlatform << endl;
    }
};

class Resolution : public virtual TV {
protected:
    string m_pixel;
public:
    Resolution(string typeTV, string pixel) : TV(typeTV) {
        m_typeTV=typeTV;
        m_pixel=pixel;
    }
    ~Resolution() {}

    void GetPixel() {
        cout << "Screen resolution : " << this->m_pixel << endl;
    }
};

class Quality : public Resolution {
protected:
    string m_definition;
public:
    Quality(string definition, string typeTV, string pixel) : Resolution(typeTV, pixel) {
        m_definition=definition;
    }
    ~Quality() {}

    void GetDefinition() {
        cout << "My stage " << this->m_definition << endl;
    }
};


class Company: public Platform, public Quality {
protected:
    string m_name;
public:
    Company(string name, string typeTV, string definition, string pixel, string model, string namePlatform)
        :Platform(typeTV, model, namePlatform), Quality(definition, typeTV, pixel) {
        m_name = name;
    }

    ~Company() {}

    void GetInfo() {
        cout << "Название: " << this->m_name << endl;
        cout << "Тип телевизора: " << this->m_typeTV << endl;
        cout << "Качество видео: " << this->m_definition << "(разрешение "<< this->m_pixel << " пикселей)" << endl;
        cout << "Модель: " << this->m_model<<" TV"<< endl;
        cout << "Платформа "<< this->m_model<<" TV: "<< this->m_namePlatform << "TV" << endl;
    }
};

int main() {

    system("chcp 1251");
    system("cls");
    Company Xiaomi("Xiaomi MI TV P1 50", "жидкокристолический", "4К UHD", "3840*2160", "Smart", "Android");

    Xiaomi.GetInfo();

    return 0;
}