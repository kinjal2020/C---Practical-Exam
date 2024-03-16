#include <iostream>
#include <string.h>
using namespace std;

class Product
{
private:
    int id;
    char name[20];
    float price;

public:
    Product(int id, char name[20], float price)
    {
        this->id = id;
        strcpy(this->name, name);
        this->price = price;
    }
    Product();

    int getId()
    {
        return id;
    }

    void setId(int id)
    {
        this->id = id;
    }

    char *getName()
    {
        return name;
    }

    void setName(char name[20])
    {
        strcpy(this->name, name);
    }

    float getPrice()
    {
        return price;
    }

    void setPrice(float price)
    {
        this->price = price;
    }
};

class Electronics : public Product
{
private:
    char brand[20];

public:
    Electronics(int id, char name[20], float price, char brand[20])
    {
        setId(id);
        setName(name);
        setPrice(price);
        strcpy(this->brand, brand);
    }

    string getBrand() const { return brand; }

    void setBrand(char brand[30]) { strcpy(this->brand, brand); }
};

int main()
{
    char test[20] = "Test";
    char *ptr = test;
    Electronics e = Electronics(101, ptr, 2356.3, "testre");
    cout << e.getBrand();
    return 0;
}
