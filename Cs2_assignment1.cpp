#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

class Car
{
private:
    string Car_Brand;
    string Car_Type;
    string Car_Plate;
    int Speed;
    int Year_Model;

public:
    Car()
    {
        Car_Brand = "";
        Car_Type = "";
        Car_Plate = "";
        Speed = 0;
        Year_Model = 0;
    }

    Car(string _Car_Brand, int _Speed, int _Year_Model)
    {
        Car_Brand = _Car_Brand;
        Speed = _Speed;
        Year_Model = _Year_Model;
    }

    void set_Car_Brand(string _Car_Brand)
    {
        Car_Brand = _Car_Brand;
    }
    string get_Car_Brand()
    {
        return Car_Brand;
    }


    void set_Car_Type(string _Car_Type)
    {
        Car_Type = _Car_Type;
    }
    string get_Car_Type()
    {
        return Car_Type;
    }


    void set_Car_Plate(string _Car_Plate)
    {
        Car_Plate = _Car_Plate;
    }
    string get_Car_Plate()
    {
        return Car_Plate;
    }


    void set_Speed(int _Speed)
    {
        Speed = _Speed;
    }
    int get_Speed()
    {
        return Speed;
    }


    void set_Year_Model(int _Year_Model)
    {
        Year_Model = _Year_Model;
    }
    int get_Year_Model()
    {
        return Year_Model;
    }

};

class Road
{
private:
    char Road_Type;
    int Speed_Limit;
    int countA;
    int countB;
    int countC;

public:
    Road()
    {
        countA = 0;
        countB = 0;
        countC = 0;
    }

    Road(char _Road_Type, int _Speed_Limit)
    {
        countA = 0;
        countB = 0;
        countC = 0;
        Road_Type = _Road_Type;
        Speed_Limit = _Speed_Limit;
    }


    void setRoad_Type(char _Road_Type)
    {
        Road_Type = _Road_Type;
    }
    char getRoad_Type()
    {
        return Road_Type;
    }


    void setSpeed_Limit(int _Speed_Limit)
    {
        Speed_Limit = _Speed_Limit;
    }
    int getSpeed_Limit()
    {
        return Speed_Limit;
    }


    void setcountA(int _countA)
    {
        countA = _countA;
    }
    int getcountA()
    {
        return countA;
    }


    void setcountB(int _countB)
    {
        countB = _countB;
    }
    int getcountB()
    {
        return countB;
    }


    void setcountC(int _countC)
    {
        countC = _countC;
    }
    int getcountC()
    {
        return countC;
    }

    bool Radar(int car_speed, char Road_Type)
    {
        if (car_speed > Speed_Limit)
        {
            return true;
        }

        return false;
    }

    void allow(string Car_type)
    {
        if (Road_Type == 'A')
        {
            if (Car_type != "Private" && Car_type != "motorcycle")
            {
                cout << Car_type << " is not allowed in " << Road_Type << endl;

            }
            else
            {
                countA++;
                cout << Car_type << " is allowed in " << Road_Type << endl;
            }
        }

        if (Road_Type == 'B')
        {
            countB++;
            cout << Car_type << " is allowed in " << Road_Type << endl;
        }

        if (Road_Type == 'C')
        {
            if (Car_type == "truck")
            {
                countC++;
                cout << Car_type << " is allowed in " << Road_Type << endl;
            }
            else
            {
                cout << Car_type << " is not allowed in " << Road_Type << endl;
            }
        }
    }


    int age(int Year_Model)
    {
        return 2022 - Year_Model;
    }
};


int main()
{
    Road road = Road('A', 150);

    Car car = Car("A", 190, 2020);

    car.set_Car_Plate("ABC");
    car.set_Car_Type("C");

    //-----------------------------------

    if (road.Radar(car.get_Speed(), road.getRoad_Type()) == true)
    {
        cout << "This car will be fined" << endl;
        cout << "Car type = " << car.get_Car_Type() << endl;
        cout << "Car Car_Brand = " << car.get_Car_Brand() << endl;
        cout << "Car year model = " << car.get_Year_Model() << endl;
        cout << "Car speed = " << car.get_Speed() << endl;
        cout << "Car plate = " << car.get_Car_Plate() << endl;
    }

    cout << endl << "------" << endl;
    cout << "End part B" << endl;
    cout << endl << "------" << endl;

    //----------------------------------------------------------
    // Part C
    //----------

    queue<Car> q;

    Car a = Car("bm", 100, 2020);
    a.set_Car_Type("Private");
    q.push(a);

    Car b = Car("mr", 120, 2015);
    b.set_Car_Type("motorcycle");
    q.push(b);

    Car c = Car("abc", 160, 2019);
    c.set_Car_Type("truck");
    q.push(c);


    Road RoadA = Road('A', 100);
    Road RoadB = Road('B', 100);
    Road RoadC = Road('C', 100);

    while (q.size() > 0)
    {
        Car currentCar = q.front();
        q.pop();

        // RoadA
        bool radar1 = RoadA.Radar(currentCar.get_Speed(), RoadA.getRoad_Type());
        RoadA.allow(currentCar.get_Car_Type());
        int age1 = RoadA.age(currentCar.get_Year_Model());

        // RoadB
        bool radar2 = RoadB.Radar(currentCar.get_Speed(), RoadB.getRoad_Type());
        RoadB.allow(currentCar.get_Car_Type());
        int age2 = RoadB.age(currentCar.get_Year_Model());

        // RoadC
        bool radar3 = RoadC.Radar(currentCar.get_Speed(), RoadC.getRoad_Type());
        RoadC.allow(currentCar.get_Car_Type());
        int age3 = RoadC.age(currentCar.get_Year_Model());
    }

    //------------------------------------------------------

    double highestRoad = max({ RoadA.getcountA(), RoadB.getcountB(), RoadC.getcountC() });

    double efficiencyA = ((RoadA.getcountA() / highestRoad) * 100);

    double efficiencyB = ((RoadB.getcountB() / highestRoad) * 100);

    double efficiencyC = ((RoadC.getcountC() / highestRoad) * 100);

    cout << "efficiencyA = " << efficiencyA << "%\nefficiencyB = " << efficiencyB << "%\nefficiencyC = " << efficiencyC << "%" << endl;
}