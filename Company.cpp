#include"bitsc++.h"

class Technology;

struct Tech;

bool operator<(const Tech&, const Tech&) { return false; }

class Company {
public:
    string name;
    set<Tech> ListOfTechnology, HistoryOfTechnology, DutyTechnology;
    string StrategyName;
    int time, money;

    Company() = default;

    Company(string name, set<Tech> ListOfTechnology, set<Tech> HistoryOfTechnology, set<Tech> DutyTechnology) :
        name(name),
        ListOfTechnology(ListOfTechnology),
        HistoryOfTechnology(HistoryOfTechnology),
        DutyTechnology(DutyTechnology) {
    }

    friend ostream& operator<<(ostream& s, Company& c);

};

class Technology {
public:
    string name;
    int time;
    int price;
    int priceForLicense;
    vector<Technology> otherTechnology;
    vector<Company> company;

    Technology() = default;

    Technology(string name, int time,
        int price, int priceForLicense, vector<Technology> otherTechnology) :
        name(name),
        time(time),
        price(price),
        priceForLicense(priceForLicense),
        otherTechnology(otherTechnology) {
    }

    void addCompany(Company company) { this->company.push_back(company); }
    void addAuthor (Company company) { this->company.push_back(company); }


    friend ostream& operator<<(ostream& s, const Technology& t) {
        s << "Technology :";
        s << "Name = " << t.name << "\n";
        s << "Time =" << t.time << "\n";
        s << "Price = " << t.price << "\n";
        s << "Other Technology ( ";
        for (auto a : t.otherTechnology)s << a.name << " ";
        s << " )";
        s << "priceForLicense = " << t.priceForLicense << "\n";
        for (auto a : t.company)s << a << " ";
        s << ")";
        s << "\n________________________________________________________________________________\n";
        return s;
    }
};

struct Tech
{
    int start, finish;
    Technology technology;
};

void one_day(Company company,int day) {
    if (company.StrategyName == "S1") {
        for (auto a : company.ListOfTechnology) {
            for (auto b : company.HistoryOfTechnology)if (a.technology.name == b.technology.name)goto next1;
            a.start = day;
            a.finish = a.technology.time + day;
            for (auto b : a.technology.otherTechnology)company.HistoryOfTechnology.insert({ day,day,b });
            company.HistoryOfTechnology.insert(a);
        next1:;
        } 
    }
    if (company.StrategyName == "S2") {
        for (auto a : company.ListOfTechnology) {
            for (auto b : company.HistoryOfTechnology)if (a.technology.name == b.technology.name)goto next2;
            a.start = day;
            for (auto b : a.technology.otherTechnology) { 
                for (auto c : company.HistoryOfTechnology)if (c.technology.name == b.name)goto next3;
                company.HistoryOfTechnology.insert({ day,day += b.time,b });
            next3:;
            }
            a.finish= a.technology.time + day;
        next2:;
        }
    }
    if (company.StrategyName == "S3") {



    }
    if (company.StrategyName == "S4") {



    }
}

int main()
{
    Technology powder("Powder", 19, 19, 0, {});
    Technology rifle("Rifle", 10, 10, 1000, { powder });
    Technology mortar("Mortar", 20, 30, 2000, { powder,rifle });

    Company Ottoman_Empire("Ottoman Empire", { {0,0, rifle } }, { { 0,0, powder } }, { {} });
    Company Holy_Roman_Empire("Holy Roman Empire", { {0,0, rifle } ,{0,0, mortar } }, { { 0,0, powder } }, { {} });
    Ottoman_Empire.StrategyName = "S1";
    rifle.addCompany(Ottoman_Empire);
    rifle.addAuthor(Holy_Roman_Empire);
    one_day(Ottoman_Empire, 1);
    cout << Ottoman_Empire;

    return 0;
}

ostream& operator<<(ostream& s, Company& c){
    s << "Company :\n";
    s << "Name = "<<c.name << "\n";
    s << "ListOfTechnology =" ;
    for (auto a : c.ListOfTechnology)s <<"start "<<a.start<<" finish "<<a.finish<<" "<< a.technology.name << " ";
    s << "\n";
    s << "HistoryOfTechnology = ";
    for (auto a : c.HistoryOfTechnology)s << "start " << a.start << " finish " << a.finish << " " << a.technology.name << " ";
    s << "\n";
    s << "DutyTechnology = ";
    for (auto a : c.DutyTechnology)s << "start " << a.start << " finish " << a.finish << " " << a.technology.name << " ";
    s << "\n________________________________________________________________________________\n";
    return s;
}