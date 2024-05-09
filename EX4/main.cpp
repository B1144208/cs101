#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    int m_EngineCapacity;
    int m_Horsepower;
    bool m_EngineRunning;

public:
    Engine(int EngineCapacity = 2000, int Horsepower = 200) {
        m_EngineCapacity = EngineCapacity;
        m_Horsepower = Horsepower;
        m_EngineRunning = false;
    }

    bool EngineStart() {
        if(!m_EngineRunning)
            m_EngineRunning = true;
        return true;
    }

    bool EngineStop() {
        if(m_EngineRunning)
            m_EngineRunning = false;
        return true;
    }

    bool get_EngineStatus() {
        return m_EngineRunning;
    }
};

class Fueltank{
private:
    int m_FueltankCapacity;
    int m_Gas_grade;

public:
    Fueltank(int FueltankCapacity = 3000, int Gas=98){ m_FueltankCapacity = FueltankCapacity; m_Gas_grade = Gas; }
    int fuel_up(int v, int gas) {
        if(v<=m_FueltankCapacity && gas==m_Gas_grade){
            printf("fuel_up: %d\n", v, m_Gas_grade);
            return 1;
        }else{

            if(v>m_FueltankCapacity)
                printf("Error:FueltankCapacity: %d but fuel up %d\n", m_FueltankCapacity, v);
            if(gas!=m_Gas_grade)
                printf("Error:Gas_grade: %d Correct Gas_grade: %d\n", gas, m_Gas_grade);

            return 0;
        }
    }
    int set_Gas_grade(int Gas_grade) {
        if(Gas_grade==98 || Gas_grade==95 || Gas_grade==92){
            m_Gas_grade = Gas_grade;
            printf("Set Gas_grade: %d\n", m_Gas_grade);
            return 1;
        }else{
            return 0;
        }
    }
    int get_Gas_grade() { return m_Gas_grade; }
};

class Car {
protected:
    string m_DriveMode;

private:
    Engine m_Engine;
    Fueltank m_Fueltank;
    int m_MaxSeating;
    int m_price;
    int m_base;
    string m_brand;
    string m_model;
    int m_year;
    void m_Update_price(int base = 50000){ m_price = m_MaxSeating*base; }

public:

    Car(string x, string y, int z, int s) {
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
        m_Update_price();
    }
    int get_m_MaxSeating() { return m_MaxSeating; }
    int get_price(){ return m_price; }
    void set_base(int n){ m_base = n; }
    string get_DriveMode() { return m_DriveMode; }
    string get_brand(){ return m_model; }
    bool get_EngineStatus(){ return m_Engine.get_EngineStatus(); }
    bool startEngine(){ return m_Engine.EngineStart(); }
    bool endEngine(){ return m_Engine.EngineStop(); }
    int get_Gas_grade(){ return m_Fueltank.get_Gas_grade(); }
    int set_Gas_grade(int gas=98){ return m_Fueltank.set_Gas_grade(gas); }
    int fuel_up(int v, int gas=98){ return m_Fueltank.fuel_up(v, gas); }
};

class AUDI_Car : public Car {
public:
    AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s) {
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
    }
};

int main() {
get_EngineStatus() << endl;

    //正常
    AUDI_Car car_1("A1", 2021, 2);
    cout << car_1.get_brand() << " : Gas grade = " << car_1.get_Gas_grade() << endl;
    car_1.set_Gas_grade(95);
    cout << car_1.get_brand() << " : Gas grade = " << car_1.get_Gas_grade() << endl;
    car_1.fuel_up(300, 95);
    cout << endl;

    //加錯油
    AUDI_Car car_2("A2", 2021, 2);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.set_Gas_grade(95);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300, 99);
    cout << endl;

    //加的量太大
    AUDI_Car car_3("A3", 2021, 2);
    cout << car_3.get_brand() << " : Gas_grade = " << car_3.get_Gas_grade() << endl;
    car_3.set_Gas_grade(95);
    cout << car_3.get_brand() << " : Gas_grade = " << car_3.get_Gas_grade() << endl;
    car_3.fuel_up(300000, 95);
    cout << endl;

    //加錯油且加的量太大
    AUDI_Car car_4("A4", 2021, 2);
    cout << car_4.get_brand() << " : Gas_grade = " << car_4.get_Gas_grade() << endl;
    car_4.set_Gas_grade(95);
    cout << car_4.get_brand() << " : Gas_grade = " << car_4.get_Gas_grade() << endl;
    car_4.fuel_up(10000, 98);

    return 0;
}
