#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
//int i=column;ui->textBrowser->paste();
//ui->textBrowser->setText("dwd");
//ui->textBrowser->setText("sedgwsg");
//if(i==1)
//ui->textBrowser->setText("wegweg");
//item->setData(i,2,{"wef"});
}
#include <string>
#include <set>
using namespace std;
class Technology;

struct T;

bool operator<(const T& a, const T& b) { return false; }

class Company {
public:
    string name;
    set<T> List_Of_Technology, History_Of_Technology, Duty_Technology;
    string Strategy_Name;
    int time, money;

    Company() = default;

    Company(string name, set<T> List_Of_Technology, set<T> History_Of_Technology, set<T> Duty_Technology) :
        name(name),
        List_Of_Technology(List_Of_Technology),
        History_Of_Technology(History_Of_Technology),
        Duty_Technology(Duty_Technology) {
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

struct T
{
    int start, finish;
    Technology technology;
};

void one_day(Company company,int day) {
    if (company.Strategy_Name == "S1") {
        for (auto a : company.List_Of_Technology) {
            for (auto b : company.History_Of_Technology)if (a.technology.name == b.technology.name)goto next1;
            a.start = day;
            a.finish = a.technology.time + day;
            for (auto b : a.technology.otherTechnology)company.History_Of_Technology.insert({ day,day,b });
            company.History_Of_Technology.insert(a);
        next1:;
        }
    }
    if (company.Strategy_Name == "S2") {
        for (auto a : company.List_Of_Technology) {
            for (auto b : company.History_Of_Technology)if (a.technology.name == b.technology.name)goto next2;
            a.start = day;
            for (auto b : a.technology.otherTechnology) {
                for (auto c : company.History_Of_Technology)if (c.technology.name == b.name)goto next3;
                company.History_Of_Technology.insert({ day,day += b.time,b });
            next3:;
            }
            a.finish= a.technology.time + day;
        next2:;
        }
    }
}
Technology t1("t1", 19, 19, 0, {});
Technology t2("t2", 10, 34, 50, {t1});
Technology t3("t3", 29, 39, 47, {t1,t2});

Company c("c",   { {0,0, t1 } }, { { 0,0, t1 } }, { {} });
Company c1("c1", { {0,0, t3 }  ,  {0,0, t2 } }, { { 0,0, t1 } }, { {} });
Company c2("c2", { {0,0, t3 } }, { { 0,0, t1 } }, { {} });


void MainWindow::on_treeWidget_itemActivated(QTreeWidgetItem *item, int column)
{
    QString e,s="";

    e=item->text(column);
    if(e=="First Company"){
        s += "Company :\n";
        s += "Name = ";
        s+= c.name.c_str();
        s+="\n";
        s += "ListOfTechnology =" ;
        for (auto a : c.List_Of_Technology)s +=("start " +e.number(a.start)+ " finish " +e.number(a.finish)+ " " + a.technology.name.c_str() + " ");
        s += "\n";
        s += "HistoryOfTechnology = ";
        for (auto a : c.History_Of_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
        s += "\n";
        s += "DutyTechnology = ";
        for (auto a : c.Duty_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
        s += "\n______________________________________\n";
        ui->textBrowser->setText(s);

    }
    else if(e=="Second Company"){
        s += "Company :\n";
        s += "Name = ";
        s+= c1.name.c_str();
        s+="\n";
        s += "ListOfTechnology =" ;
        for (auto a : c1.List_Of_Technology)s +=("start " +e.number(a.start)+ " finish " +e.number(a.finish)+ " " + a.technology.name.c_str() + " ");
        s += "\n";
        s += "HistoryOfTechnology = ";
        for (auto a : c1.History_Of_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
        s += "\n";
        s += "DutyTechnology = ";
        for (auto a : c1.Duty_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
        s += "\n______________________________________\n";
        ui->textBrowser->setText(s);

    }
    else if(e=="Third Company"){
        s += "Company :\n";
        s += "Name = ";
        s+= c2.name.c_str();
        s+="\n";
        s += "ListOfTechnology =" ;
        for (auto a : c2.List_Of_Technology)s +=("start " +e.number(a.start)+ " finish " +e.number(a.finish)+ " " + a.technology.name.c_str() + " ");
        s += "\n";
        s += "HistoryOfTechnology = ";
        for (auto a : c2.History_Of_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
        s += "\n";
        s += "DutyTechnology = ";
        for (auto a : c2.Duty_Technology)s += "start " + e.number(a.start) + " finish " + e.number(a.finish) + " " + a.technology.name.c_str() + " ";
        s += "\n______________________________________\n";
        ui->textBrowser->setText(s);

    }
   else ui->textBrowser->setText(e);


}

void MainWindow::on_treeWidget_2_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QString e,s="";

    e=item->text(column);
    if(e=="First Tech"){


        s += "Technology :";
        s += "Name = " ;
        s += t1.name.c_str() ;
        s += "\n";
        s += "Time =" +  e.number(t1.time) + "\n";
        s += "Price = " +  e.number(t1.price) + "\n";
        s += "Other Technology ( ";
        for (auto a : t1.otherTechnology){s += a.name.c_str() ;
        s+= " ";}
        s += " )";
        s += "priceForLicense = " +  e.number(t1.priceForLicense) + "\n";
        for (auto a : t1.company){s += a.name.c_str();
                s+= " ";}
        s += ")";
        s += "\n______________________________________\n";
        ui->textBrowser->setText(s);

    }
    if(e=="Second Tech"){


        s += "Technology :";
        s += "Name = " ;
        s += t2.name.c_str() ;
        s += "\n";
        s += "Time =" +  e.number(t2.time) + "\n";
        s += "Price = " +  e.number(t2.price) + "\n";
        s += "Other Technology ( ";
        for (auto a : t2.otherTechnology){s += a.name.c_str() ;
        s+= " ";}
        s += " )";
        s += "priceForLicense = " +  e.number(t2.priceForLicense) + "\n";
        for (auto a : t2.company){s += a.name.c_str();
                s+= " ";}
        s += ")";
        s += "\n______________________________________\n";
        ui->textBrowser->setText(s);

    }
    if(e=="Third Tech"){


        s += "Technology :";
        s += "Name = " ;
        s += t3.name.c_str() ;
        s += "\n";
        s += "Time =" +  e.number(t3.time) + "\n";
        s += "Price = " +  e.number(t3.price) + "\n";
        s += "Other Technology ( ";
        for (auto a : t3.otherTechnology){s += a.name.c_str() ;
        s+= " ";}
        s += " )";
        s += "priceForLicense = " +  e.number(t3.priceForLicense) + "\n";
        for (auto a : t3.company){s += a.name.c_str();
                s+= " ";}
        s += ")";
        s += "\n______________________________________\n";
        ui->textBrowser->setText(s);

    }
}

ostream& operator<<(ostream& s, Company& c){
    s << "Company :\n";
    s << "Name = "<<c.name << "\n";
    s << "ListOfTechnology =" ;
    for (auto a : c.List_Of_Technology)s <<"start "<<a.start<<" finish "<<a.finish<<" "<< a.technology.name << " ";
    s << "\n";
    s << "HistoryOfTechnology = ";
    for (auto a : c.History_Of_Technology)s << "start " << a.start << " finish " << a.finish << " " << a.technology.name << " ";
    s << "\n";
    s << "DutyTechnology = ";
    for (auto a : c.Duty_Technology)s << "start " << a.start << " finish " << a.finish << " " << a.technology.name << " ";
    s << "\n________________________________________________________________________________\n";
    return s;
}
